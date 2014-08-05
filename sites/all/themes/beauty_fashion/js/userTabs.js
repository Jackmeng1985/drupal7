// js/index.js


(function($) {

$(function() {

 // tab cont
    var locationHash = location.hash.substr(1);
    var checkCostNotice = function () {
        // body...
    };
    var checkXiaofeijilu = function () {
        var hh = location.hash.substr(1);
        if (hh == 'xiaofeijilu') {
            $('[js=sortby]').closest('.sortBy').removeClass('byMoney');
            $('[js=countInfo]').show();
        } else {
            $('[js=countInfo]').hide();
        }
    };
    // 初始化tab选中哪个
    if (!locationHash || ($('[js='+ locationHash +']').length == 0)) {
        $('.inPageTabCont').first().show();
        $('.inPageTabNav a').first().addClass('curr');

    } else {
        $('[js='+ locationHash +']').show();
        $('[js='+ locationHash +'Tab]').addClass('curr');
    }
    checkXiaofeijilu();
    // tab切换
    $('[js=inPageTabNav]').bind('tap', 'a', function (e) {
        var newCont = $(this).attr('href');
        location.hash = newCont;
        $(this).closest('[js=inPageTabNav]').find('a').removeClass('curr');
        $(this).addClass('curr');
        $('.inPageTabCont').hide();
        $('[js='+ newCont.substr(1) + ']').show();
        // check 消费提醒 条目
        checkCostNotice();
        checkXiaofeijilu();
        $(window).trigger('scroll');
    });
    // 排序
    $('[js=countInfo]').bind('tap', '[js=sortby]', function () {
        var sortby = $(this).attr('sortby');
        // 拉取数据
        /*
        $.ajax({

        })
        */
        // after success
        if (sortby == 'money') {
            $(this).closest('span').addClass('byMoney');
        } else {
            $(this).closest('span').removeClass('byMoney');
        }
    });
    // 评分
    $('[js=starts]').bind('tap swipe', 'span', function () {
        $(this).closest('div').attr('class','stars stars'+($(this).index()+1));
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

});