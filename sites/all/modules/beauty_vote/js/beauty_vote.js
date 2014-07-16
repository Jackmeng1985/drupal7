(function($) {
    $(document).ready(function() {
        $('.vote-icon-comment').click(function(){
            if ($(this).hasClass('vote-icon-comment-orange')) {
                return;
            }
            $(this).addClass('vote-icon-comment-orange');
            var v = $(this).text();
            $(this).text(parseInt(v) + 1)
//            $.get('');
        });
    });
})(jQuery);