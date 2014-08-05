// js/index.js


(function($) {

$(function() {

// tab cont
    var locationHash = location.hash.substr(1);
    var checkCostNotice = function () {
        // body...
    };

    if (!locationHash || ($('[js='+ locationHash +']').length == 0)) {
        $('.inPageTabCont').first().show();
        $('.inPageTabNav a').first().addClass('curr');
    } else {
        $('[js='+ locationHash +']').show();
        $('[js='+ locationHash +'Tab]').addClass('curr');
    }

    $('[js=inPageTabNav]').bind('tap', 'a', function (e) {
        var newCont = $(this).attr('href');
        location.hash = newCont;
        $(this).closest('[js=inPageTabNav]').find('a').removeClass('curr');
        $(this).addClass('curr');
        $('.inPageTabCont').hide();
        $('[js='+ newCont.substr(1) + ']').show();
        // check 消费提醒 条目
        checkCostNotice();
        $(window).trigger('scroll');
    });

    $('.tookitBar').bind('tap', '[js=toolkit]', function () {
        $('[js=toolkit]').removeClass('curr');
        $(this).addClass('curr');

        if ($(this).index() != 3) {
            $('[js=styleList] ul').animate({
                "margin-left": 0
            }, 300);
            $('[js=styleList] li').eq(0).trigger('tap');
        }
    });

    $('[js=styleList]').bind('tap', 'li', function () {
        $('[js=styleList]').find('li').removeClass('curr');
        $(this).addClass('curr');
    });

    // set ul width
    var ulWidth = Math.max(window.__width, $('[js=styleList] li').length * 70);
    $('[js=styleList] ul').css('width', ulWidth+'px' );

    var self = this;
    var sliderCont = $('[js=styleList]').eq(0),
        sliderLen = sliderCont.find('li').size(),
        sliderKeyLock = false;
    var scrollFunc = function (direction) {
        var currMarginLeft = parseInt($(this).css('margin-left'), 10),
            judgeLeft,
            judgeDiff,
            newMarginLeft;
        var step = 70 * 2;

        if (direction == 'right') {
            judgeLeft = 0;
            judgeDiff = 1;
        } else {
            judgeLeft = (-1) *(ulWidth - window.__width);
            judgeDiff = -1;
        }

        if (sliderKeyLock) {
            return false;
        }
        sliderKeyLock = true;

        if ((currMarginLeft >= 0 && direction == 'right')  || (direction == 'left' && (currMarginLeft < (window.__width-ulWidth)))) {
            sliderKeyLock = false;
        } else {
            newMarginLeft = currMarginLeft + judgeDiff * step;
            $(this).animate({
                "margin-left": newMarginLeft + 'px'
            }, 300, function () {
                sliderKeyLock = false;
            });
        }
    };
    $('[js=styleList] ul').bind('swipeleft', function () {
        scrollFunc.call(this, 'left');
    });
    $('[js=styleList] ul').bind('swiperight', function () {
        scrollFunc.call(this, 'right');
    });

});

})(jQuery);








