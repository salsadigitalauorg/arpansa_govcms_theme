jQuery.fn.size = function() {
  return this.length;
};

jQuery.extend({
  handleError: function(s, xhr, status, e) {
    // If a local callback was specified, fire it
    if (s.error) {
      s.error.call(s.context, xhr, status, e);
    }

    // Fire the global callback
    if (s.global) {
      jQuery.triggerGlobal(s, "ajaxError", [xhr, s, e]);
    }
  },
  httpData: function(xhr, type, s) {
    var ct = xhr.getResponseHeader("content-type") || "",
      xml = type === "xml" || !type && ct.indexOf("xml") >= 0,
      data = xml ? xhr.responseXML : xhr.responseText;

    if (xml && data.documentElement.nodeName === "parsererror") {
      jQuery.error("parsererror");
    }

    // Allow a pre-filtering function to sanitize the response
    // s is checked to keep backwards compatibility
    if (s && s.dataFilter) {
      data = s.dataFilter(data, type);
    }

    // The filter can actually parse the response
    if (typeof data === "string") {
      // Get the JavaScript object, if JSON is used.
      if (type === "json" || !type && ct.indexOf("json") >= 0) {
        data = jQuery.parseJSON(data);

        // If the type is "script", eval it in global context
      } else if (type === "script" || !type && ct.indexOf("javascript") >= 0) {
        jQuery.globalEval(data);
      }
    }

    return data;
  }
});
