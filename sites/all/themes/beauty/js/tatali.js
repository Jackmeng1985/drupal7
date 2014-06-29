Date.prototype.format = function(format) {
  var o = {
    "M+": this.getMonth() + 1,
    "d+": this.getDate(),
    "h+": this.getHours(),
    "m+": this.getMinutes(),
    "s+": this.getSeconds(),
    "q+": Math.floor((this.getMonth() + 3) / 3),
    "S": this.getMilliseconds()
  }
  if(/(y+)/.test(format)) {
    format = format.replace(RegExp.$1, (this.getFullYear() + '').substr(4 - RegExp.$1.length));
  }
  for(var k in o){
    if(new RegExp('(' + k + ')').test(format)) {
      format = format.replace(RegExp.$1, RegExp.$1.length == 1 ? o[k] : ('00' + o[k]).substr(('' + o[k]).length));
    }
  }
  return format;
}
var tatali = function(type, id, template_name, target) {
  var url = 'http://hfx.choosebeauty.com.cn/mobile/views/classic.jsonp?args=' + id + '&page=0&callback=?';
  $.getJSON(url, function(data) {
    var item;
    items = '';
    var items = new Array();
    switch(type) {
      case 'weibo':
        $.each(data, function(i, e) {
          var dpam = jQuery.parseJSON(e.field_displayparam.und[0].value);
          var author_image = dpam.weibo_point.user.avatar_hd;
          var author_name = dpam.weibo_point.user.name;
          var author_location = dpam.weibo_point.user.location;
          var id = dpam.weibo_point.user.id;
          var mid = dpam.weibo_point.mid;
          var mid_url = WeiboUtility.mid2url(mid);
          var fullweibo = '';
          var weibo_content = dpam.weibo_point.text;
          var created_at = dpam.weibo_point.created_at;

          var url = 'http://weibo.com/' + id + '/' + mid_url;

          var created = new Date(created_at);
          created = created.format('yyyy-MM-dd hh:mm:ss');
          item = {
            url: url,
            author_image: author_image,
            author_name: author_name,
            author_location: author_location,
            weibo_content: weibo_content,
            created: created
          };
          items.push(item);
        });
      break;

      case 'youku':
        $.each(data, function(i, e) {
          var dpam = jQuery.parseJSON(e.field_displayparam.und[0].value);
          var m = parseInt(dpam.duration / 60) > 9 ? parseInt(dpam.duration / 60) : '0' + parseInt(dpam.duration / 60);
          var s = parseInt(dpam.duration % 60) > 9 ? parseInt(dpam.duration % 60) : '0' + parseInt(dpam.duration % 60);
          dpam.duration = m + ':' + s;
          items.push(dpam);
        });
      break;
    }

    var list = {
      list: items
    }
    var html = template(template_name, list);
    document.getElementById(target).innerHTML = html;
  });
}



