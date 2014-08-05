(function(jQuery){
    
 window.scrollTo(0,1);
    jQuery(window).bind('pageGetWH', function (event, reloadPage) {
        if (reloadPage) {
            location.reload(true);
        }

        jQuery.extend(window, {
            __width : jQuery(window).width(),
            __height : jQuery(window).height()
        });
    });
    // get W/H
    jQuery('body').bind('orientationchange', function (event) {
        jQuery(window).trigger("pageGetWH", true)
    });
    jQuery(window).trigger("pageGetWH");

})(jQuery);