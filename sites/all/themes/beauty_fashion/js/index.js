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

        var scrollFunc = function (direction, autoplayer) {
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

                newMarginLeft = (direction == 'right') ? (- (sliderLen-1) * window.__width) : 0;
                $(this).animate({'margin-left': newMarginLeft + 'px'}, 300, function () {
                    sliderKeyLock = false;
                    sliderPlayer();
                });

            } else {
                newMarginLeft = currMarginLeft + judgeDiff * window.__width;
                $(this).animate({
                    "margin-left": newMarginLeft + 'px'
                }, 300, function () {
                    sliderKeyLock = false;
                    sliderPlayer();
                });

            }
            sliderTab.find('li').eq(Math.abs(currMarginLeft/window.__width)).removeClass("curr");
            sliderTab.find('li').eq(Math.abs(newMarginLeft/window.__width)).addClass("curr");
        };

        sliderCont.bind('swiperight', function (event) {
            clearInterval(self.sliderAuto);
            scrollFunc.call(this, 'right');
        });
        sliderCont.bind('swipeleft', function (event) {
            clearInterval(self.sliderAuto);
            scrollFunc.call(this, 'left');
        });
        var sliderPlayer =  function() {
            clearInterval(self.sliderAuto);
            self.sliderAuto = setInterval(function(){
                scrollFunc.call(sliderCont, 'left');
            }, 5000);
        };
        sliderPlayer();

});

})(jQuery);