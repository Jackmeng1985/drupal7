// util.getWH.js
(function(){
    window.scrollTo(0,1);
    $(window).bind('pageGetWH', function (event, reloadPage) {
        if (reloadPage) {
            location.reload(true);
        }

        $.extend(window, {
            __width : $(window).width(),
            __height : $(window).height()
        });
    });
    // get W/H
    $('body').bind('orientationchange', function (event) {
        $(window).trigger("pageGetWH", true)
    });
    $(window).trigger("pageGetWH");

})();

