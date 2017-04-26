<?php

/**
 * @file
 * ia.inc
 */

/**
 * Class ArpansaMigrationIA.
 */
class ArpansaMigrationIA extends ArpansaMigrationPage {

  /**
   * Last migrated menu item.
   *
   * @var array
   */
  protected $lastMenuItem;

  /**
   * Page Migration.
   *
   * @var \ArpansaMigrationPage
   */
  protected $pageMigration;

  /**
   * {@inheritdoc}
   */
  public function __construct(array $arguments = array()) {
    parent::__construct($arguments);

    $this->destination = new MigrateDestinationMenuLinks();
    $this->map = new MigrateSQLMap($this->machineName, [
      'source' => [
        'type' => 'varchar',
        'length' => 255,
      ],
    ], MigrateDestinationMenuLinks::getKeySchema());

    $this->codedFieldMappings = [];
    $this->addFieldMapping('menu_name')->defaultValue('main-menu');
    $this->addFieldMapping('plid')->defaultValue(0);
    $this->addFieldMapping('link_path', 'link_path');
    $this->addFieldMapping('link_title', 'link_title');
    $this->addFieldMapping('enabled')->defaultValue(TRUE);
    $this->addFieldMapping('expanded')->defaultValue(TRUE);
    $this->addFieldMapping('external')->defaultValue('0');
    $this->addUnmigratedDestinations([
      'module',
      'hidden',
      'options',
      'p1', 'p2', 'p3', 'p4', 'p5', 'p6', 'p7', 'p8', 'p9',
      'updated',
    ]);

    $this->pageMigration = Migration::getInstance('Page');
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    // AC7.1 Items marked with "delete" in column G should not be migrated.
    if ($row->type == 'delete' || $row->alias == 'delete') {
      return FALSE;
    }

    if ($destination = $this->handleSourceMigration([$this->pageMigration->getMachineName()], [$row->source])) {
      $row->source_nid = is_array($destination) ? reset($destination) : $destination;
      $node = node_load($row->source_nid);
      $row->title = $node->title;
      $row->link_path = 'node/' . $row->source_nid;

      if (empty($row->migrate_map_destid1)) {
        if ($menu_link = menu_link_get_preferred('node/' . $row->source_nid)) {
          $row->migrate_map_destid1 = $menu_link['mlid'];
        }
      }
    }
    else {
      $this->queueMessage(t('Source page @source not found.', ['@source' => $row->source]));
      return FALSE;
    }

    // Detect IA Title.
    $row->link_title = $row->title;
    foreach ([1, 2, 3, 4] as $level) {
      $link_title = $row->{'ia_title' . $level};
      if (!empty($link_title)) {
        $title_parts = explode(' - ', $link_title);
        // Remove "ARPANSA" from IA title.
        if ($title_parts[0] == 'ARPANSA') {
          unset($title_parts[0]);
        }
        if ($title_parts && count($title_parts)) {
          $link_title = implode(' - ', $title_parts);
        }

        if ($link_title) {
          $row->link_title = $link_title;
        }

        break;
      }
    }

    $row->alias = ArpansaMigrationHelper::sanitizeArpansaSourceUri($row->alias);

    return TRUE;
  }

  /**
   * Implements prepare().
   */
  public function prepare($menu_link, $row) {
    // Prepare parents.
    if (empty($row->alias)) {
      if (!empty($this->lastMenuItem)) {
        $menu_link->plid = $this->lastMenuItem->mlid;
      }
    }
    else {
      // Try to find a parent menu item.
      $parent_path = preg_replace('/\/+/i', '/', trim($row->alias, '/'));
      $parent_path = explode('/', $parent_path);
      if (count($parent_path) > 1) {
        $plid = 0;
        foreach ($parent_path as $index => $path_item) {
          if ($index + 1 == count($parent_path)) {
            break;
          }
          $trail = array_slice($parent_path, 0, $index + 1);
          $trail = implode('/', $trail);
          if ($parent_nid = $this->findNodeIdWithAlias($trail)) {
            if ($parent_menu = menu_link_get_preferred('node/' . $parent_nid, 'main-menu')) {
              $plid = $parent_menu['mlid'];
              // Ensure parent has_children set to avoid confusion in Superfish.
              $parent_menu['has_children'] = 1;
              menu_link_save($parent_menu);
            }
            else {
              $parent_menu_title = $trail;
              if ($parent_node = node_load($parent_nid)) {
                $parent_menu_title = $parent_node->title;
              }
              // Create one for its parent.
              $parent_menu = [
                'enabled' => TRUE,
                'link_title' => $parent_menu_title,
                'link_path' => 'node/' . $parent_nid,
                'plid' => $plid,
                'menu_name' => 'main-menu',
                'expanded' => 1,
                'has_children' => 1,
              ];
              $plid = menu_link_save($parent_menu);
              $this->map->saveIDMapping((object) ['source' => $trail], [$plid]);
            }
          }
        }

        $menu_link->plid = $plid;
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function complete($menu_link, $row) {
    if (!empty($row->alias)) {
      $this->lastMenuItem = $menu_link;
    }
    // Ensure parent has_children set to avoid confusion in Superfish.
    if (!empty($menu_link->plid)) {
      if ($menu_link_item = menu_link_load($menu_link->mlid)) {
        _menu_update_parental_status($menu_link_item);
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function postImport() {
    menu_rebuild();
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRollback($mlid) {
    if ($menu_link = menu_link_load($mlid)) {
      $mapping = $this->map->getRowByDestination([$mlid]);
      if ($node = menu_get_object('node', 1, $menu_link['link_path'])) {
        if ($node->type == 'landing_page' && $node->title == $mapping['sourceid1']) {
          node_delete($node->nid);
        }
      }
    }
  }

  /**
   * Implements createStub().
   */
  protected function createStub($migration, $source_key = NULL) {
    return FALSE;
  }

  /**
   * Find migrated node with alias.
   *
   * @param string $alias
   *   Path alias.
   * @param bool $createPageStub
   *   Whether to create a new stub if not found.
   *
   * @return int|false
   *   Node ID of the stub.
   */
  protected function findNodeIdWithAlias($alias, $createPageStub = TRUE) {
    if ($path = drupal_lookup_path('source', $alias)) {
      if ($node = menu_get_object('node', 1, $path)) {
        return $node->nid;
      }
    }
    else {
      $query = new EntityFieldQuery();
      $result = $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'landing_page')
        ->propertyCondition('title', $alias)
        ->execute();
      if (!empty($result['node']) && count($result['node'])) {
        $node = reset($result['node']);
        return $node->nid;
      }
    }

    if ($createPageStub) {
      if ($nids = parent::createStub($this, [$alias])) {
        $this->queueMessage(t('Create stub for alias @alias', ['@alias' => $alias]), self::MESSAGE_INFORMATIONAL);
        return reset($nids);
      }
    }

    return FALSE;
  }

}
