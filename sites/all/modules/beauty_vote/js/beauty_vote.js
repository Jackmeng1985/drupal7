(function($) {
    $(document).ready(function() {
        $('.vote-icon-comment').click(function(){
            var $this = $(this);
            if ($this.hasClass('vote-icon-comment-orange')) {
                return;
            }
            $this.addClass('vote-icon-comment-orange');
            var v = $this.text();
            $this.text(parseInt(v) + 1);
            var ref = $this.attr('ref').split('|');
            $.get(Drupal.settings.basePath + 'beauty_vote/vote/' + ref[1] + '/' + ref[0]);
        });
    });
})(jQuery);