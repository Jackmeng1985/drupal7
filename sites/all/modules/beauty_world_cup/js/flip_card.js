(function($) {

    Drupal.beauty_flip_card = {};
    Drupal.beauty_flip_card.card = 1;
    Drupal.beauty_flip_card.cardItems = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13];
    Drupal.beauty_flip_card.triggerIndex = false;
    Drupal.beauty_flip_card.triggered = false;
    
    $(document).ready(function() {
        //Initiliaze
        Drupal.beauty_flip_card.itemShow = 13;
        Drupal.beauty_flip_card.indexedItemShow = Drupal.beauty_flip_card.itemShow - 1
        Drupal.beauty_flip_card.itemList = $('#portfolio-item');
        Drupal.beauty_flip_card.itemWrapper = $('#portfolio');
        Drupal.beauty_flip_card.rotation = 'flipped-horizontal-right'; // 'flipped-vertical-bottom', 'flipped-vertical-top', 'flipped-horizontal-left', 

        //Populate items
        for (var i = 0; i < Drupal.beauty_flip_card.itemShow; i++) {

            var itemImage = Drupal.beauty_flip_card.itemList.children('li:eq(' + i + ')').children('img');
            var itemSrc = itemImage.attr('src');
            var item = '<div style="background:url(' + itemSrc + ')" onClick="javascript:Drupal.beauty_flip_card.click_card(this);"></div>';
            Drupal.beauty_flip_card.itemWrapper.append(item);
        }
    });
            


    Drupal.beauty_flip_card.click_card = function(card) {
        var $this = Drupal.beauty_flip_card;
        if ($this.triggered) return;
        var indexReal = $this.itemWrapper.find('div').index($(card));
        $this.triggerIndex = indexReal;
        var item =$this.itemWrapper.children('div:eq(' + indexReal + ')');
        var animation = $this.rotation;
        item.addClass('animated ' + animation);
        $this.triggered = true;

        item.bind('transitionend webkitTransitionEnd MSTransitionEnd oTransitionEnd', function() {
            var itemHost = $this.card + $this.indexedItemShow;
            var itemImage = $this.itemList.children('li:eq(' + itemHost + ')').children('img');
            var itemSrc = itemImage.attr('src');
            var itemCurrent = $this.itemWrapper.children('div:eq(' + indexReal + ')');
            itemCurrent.css('background', 'url(' + itemSrc + ')');
            $(this).removeClass();
            $this.flip_card(0);
        });
    };
    
    Drupal.beauty_flip_card.flip_card = function (index) {
        var $this = Drupal.beauty_flip_card;
        
        if ($this.triggerIndex == index) {
            $this.flip_card(index + 1);
            return;
        } 
        
        var item = $this.itemWrapper.children('div:eq(' + index + ')');
        var animation = $this.rotation;
        item.addClass('animated ' + animation);   
        item.bind('transitionend webkitTransitionEnd MSTransitionEnd oTransitionEnd', function() {
            var itemHost = $this.get_radom_card() + $this.indexedItemShow;
            var itemSrc = $this.itemList.children('li:eq(' + itemHost + ')').children('img').attr('src');
            $this.itemWrapper.children('div:eq(' + index + ')').css('background', 'url(' + itemSrc + ')');
            $(this).removeClass();
            if ($this.cardItems.length > 0) {
                $this.flip_card(index + 1);
            };            
        });
    }
    
    Drupal.beauty_flip_card.get_radom_card = function () {
         var random = Math.floor(Math.random() * (12 + 1));
         return random;
    }
    
})(jQuery);