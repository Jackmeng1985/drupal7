// js/index.js


(function($) {

$(function() {
 // slider
    var self = this;
    var sliderCont = $('[js=sliderCont]').eq(0),
        sliderTab = $('[js=sliderTab]').eq(0),
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
            sliderTab.find('.prev').add(sliderTab.find('.next')).show();
            newMarginLeft = currMarginLeft + judgeDiff * window.__width;
            $(this).animate({
                "margin-left": newMarginLeft + 'px'
            }, 300, function () {
                sliderKeyLock = false;
            });

            if (Math.abs(newMarginLeft/window.__width) == 0) {
                sliderTab.find('.prev').hide();
            } else if (Math.abs(newMarginLeft/window.__width) == (sliderLen-1)) {
                sliderTab.find('.next').hide();
            }
        }
        // sliderTab.find('li').eq(Math.abs(currMarginLeft/window.__width)).removeClass("curr");
        // sliderTab.find('li').eq(Math.abs(newMarginLeft/window.__width)).addClass("curr");
    };

    sliderCont.bind('swiperight', function (event) {
        scrollFunc.call(this, 'right');
    });
    sliderCont.bind('swipeleft', function (event) {
        scrollFunc.call(this, 'left');
    });
    sliderTab.find('.prev').bind('tap', function (event) {
        scrollFunc.call(sliderCont, 'right');
    });
    sliderTab.find('.next').bind('tap', function (event) {
        scrollFunc.call(sliderCont, 'left');
    });
    sliderTab.find('.next').show();

});

})(jQuery);
