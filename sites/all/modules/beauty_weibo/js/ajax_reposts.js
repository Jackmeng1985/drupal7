(function ($) {
  $(document).ready(function() {
    $('.ajax-reposts').click(function() {
      var mid = $(this).attr('mid');
      var get_reposts_url = '/beauty/ajax/weibo_get_reposts/' + mid;
      $.getJSON('get_reposts_url', function(data) {
        //
      });
    });
  });
})(jQuery);
