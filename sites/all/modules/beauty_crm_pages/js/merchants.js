// js/index.js
(function($) {
$(function() {
// slider
    var merchangtsSlider = function (slideBox) {
        if(!slideBox){
            console && console.info('need params');
            return false;
        }
        var sliderCont = slideBox.find('[js=sliderCont]').eq(0),
            sliderTab = slideBox.find('[js=tabTit]').eq(0),
            sliderLen = sliderCont.find('li').size(),
            sliderKeyLock = false;
        sliderCont.css('width', sliderLen * window.__width);
        sliderCont.find('li').css('width', window.__width+'px');

        var scrollFunc = function (direction) {
            var currMarginLeft = parseInt($(this).css('margin-left'), 10),
                judgeLeft,
                judgeDiff,
                newMarginLeft;

            if (direction == 'right') {
                judgeLeft = 0;
                judgeDiff = 1;
            } else {
                judgeLeft = -(sliderLen-1) * window.__width;
                judgeDiff = -1;
            }

            if (sliderKeyLock) {
                return false;
            }
            sliderKeyLock = true;

            if (currMarginLeft == judgeLeft) {
                sliderKeyLock = false;

            } else {
                newMarginLeft = currMarginLeft + judgeDiff * window.__width;
                $(this).animate({
                    "margin-left": newMarginLeft + 'px'
                }, 300, function () {
                    sliderKeyLock = false;
                });

                sliderTab.find('span').eq(Math.abs(currMarginLeft/window.__width)).removeClass("curr");
                sliderTab.find('span').eq(Math.abs(newMarginLeft/window.__width)).addClass("curr");
            }
        };

        $(slideBox).delegate('[js=sliderCont]', 'swiperight', function (event) {
            scrollFunc.call(this, 'right');
        });
        $(slideBox).delegate('[js=sliderCont]', 'swipeleft', function (event) {
            scrollFunc.call(this, 'left');
        });
    };
    $('.slidebox').length && $.each($('.slidebox'), function (n, unit){
        new merchangtsSlider($(unit));
    });
    // toggle Cont
    $('.shopInfo').length && $('.shopInfo').bind('tap', '[js=toggleSlide]', function (e) {
        var self = this;
        $(this).closest('.infoClass').find('.cont').toggle(100, function () {
            if ($(self).hasClass('slideUp')) {
                $(self).removeClass('slideUp').addClass('slideDown');
            } else {
                $(self).removeClass('slideDown').addClass('slideUp');
            }
        });
    });
    // fixed nav
    var inPageTabNav = $('[js=inPageTabNav]');
    var getDomDefaultScrollTop = inPageTabNav.offset().top;

    inPageTabNav.length && $(window).bind('swipe scroll resize', function (e) {
            if ( $(this).scrollTop() >=  getDomDefaultScrollTop) {
                inPageTabNav.css({
                    position: 'fixed',
                    width: '100%',
                    zIndex: 10000,
                    top:0
                });
            } else {
                inPageTabNav.css({
                    position: 'static',
                    top:0
                });
            }
    });
});

})(jQuery);