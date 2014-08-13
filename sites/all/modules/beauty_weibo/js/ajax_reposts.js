(function ($) {
  $(document).ready(function() {
    $('.ajax-reposts').click(function() {
      var mid = $(this).attr('mid');
      var that = $(this);
      var get_reposts_url = '/beauty/ajax/weibo_get_reposts/' + mid;
      $.getJSON(get_reposts_url, function(data) {
        if (data.status) {
          that.attr('href', '/weibo/reposts/' + mid);
          that.html('查看');
          that.removeClass('ajax-reposts');
        }
      });
    });
  });
})(jQuery);
