(function($) {

    Drupal.beauty_flip_card = {};
    $(document).ready(function() {
        //Initiliaze
        Drupal.beauty_flip_card.itemShow = 2;
        Drupal.beauty_flip_card.indexedItemShow = Drupal.beauty_flip_card.itemShow - 1
        Drupal.beauty_flip_card.itemList = $('#portfolio-item');
        Drupal.beauty_flip_card.itemWrapper = $('#portfolio');
        Drupal.beauty_flip_card.rotation = ['flipped-vertical-bottom', 'flipped-vertical-top', 'flipped-horizontal-left', 'flipped-horizontal-right'];
        Drupal.beauty_flip_card.navigation = $('#navigation a');

        //Populate items
        for (var i = 0; i < Drupal.beauty_flip_card.itemShow; i++) {

            var itemImage = Drupal.beauty_flip_card.itemList.children('li:eq(' + i + ')').children('img');
            var itemSrc = itemImage.attr('src');
            var itemAlt = itemImage.attr('alt');
            var item = '<div style="background:url(' + itemSrc + ')" onClick="javascript:Drupal.beauty_flip_card.change_card();"> <span>' + itemAlt + '</span></div>';
            Drupal.beauty_flip_card.itemWrapper.append(item);
        }
    });
            


    Drupal.beauty_flip_card.change_card = function(context) {

            var page = 2;

            for (var i = 0; i <= Drupal.beauty_flip_card.indexedItemShow; i++) {

                var random = Math.floor(Math.random() * (3 - 0 + 1));
                var animation = Drupal.beauty_flip_card.rotation[random];

                var item = Drupal.beauty_flip_card.itemWrapper.children('div:eq(' + i + ')');

                item.addClass('animated ' + animation);

                window.setTimeout(function(index) {
                    return function() {

                        var indexReal = (page == 1) ? index : (index + (page - 1));
                        var itemHost = indexReal + (Drupal.beauty_flip_card.indexedItemShow * (page - 1));

                        var itemImage = Drupal.beauty_flip_card.itemList.children('li:eq(' + itemHost + ')').children('img');
                        var itemSrc = itemImage.attr('src');
                        var itemAlt = itemImage.attr('alt');
                        var itemCurrent = Drupal.beauty_flip_card.itemWrapper.children('div:eq(' + index + ')');

                        itemCurrent.css('background', 'url(' + itemSrc + ')');
                        itemCurrent.children('span').text(itemAlt);
                    };
                }(i), 500);

                item.bind('transitionend webkitTransitionEnd MSTransitionEnd oTransitionEnd', function() {
                    $(this).removeClass();
                });
            }
        };
})(jQuery);