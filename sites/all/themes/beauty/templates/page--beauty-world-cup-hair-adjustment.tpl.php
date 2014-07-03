<?php
$base_path = base_path();
/*<?php print $base_path . $directory; ?>/*/
?>
<nav class="bar bar-tab">
  <a class="tab-item scaleup" href="#">放大</a>
  <a class="tab-item scaledown" href="#">缩小</a>
  <a class="tab-item" href="<?php print url('world_cup/hair'); ?>">更多发型</a>
</nav>
<div class="content">
  <div class="page-hair-adjustment">
       <canvas id="face" width="600" height = "600"> </canvas>
       <canvas id ="hairChange" width="448" height="733" > </canvas>
       <canvas id="hairStyle" width="448" height="733"></canvas>
  </div>
</div>
<?php print($page['content']['system_main']['main']['#markup']);?>
<script>
  WeixinApi.ready(function(Api) {
      var canvas = document.getElementById('face');
      var share_data = canvas.toDataURL();
      $.ajaxSetup({
          async : false
      });
      $.post('/world_cup/hair/share', {'image': share_data}, function(data) {
        window.share_url = data.url;
      }, 'json');
    // 微信分享的数据
    var wxData = {
        "appId": "wx3abd6037cb0edf82", // 服务号可以填写appId
        "imgUrl" : window.share_url,
        "link" : 'http://pfx.choosebeauty.com.cn/world_cup/hair',
        "desc" : '找到一个好玩的东西，可以换新发型玩',
        "title" : "发型由我"
    };

    // 分享的回调
    var wxCallbacks = {
        // 分享操作开始之前
        ready : function() {
        },
        // 分享被用户自动取消
        cancel : function(resp) {
            // 你可以在你的页面上给用户一个小Tip，为什么要取消呢？
        },
        // 分享失败了
        fail : function(resp) {
            // 分享失败了，是不是可以告诉用户：不要紧，可能是网络问题，一会儿再试试？
        },
        // 分享成功
        confirm : function(resp) {
            // 分享成功了，我们是不是可以做一些分享统计呢？
            //window.location.href='http://192.168.1.128:8080/wwyj/test.html';
        },
        // 整个分享过程结束
        all : function(resp) {
            // 如果你做的是一个鼓励用户进行分享的产品，在这里是不是可以给用户一些反馈了？
        }
    };

    // 用户点开右上角popup菜单后，点击分享给好友，会执行下面这个代码
    Api.shareToFriend(wxData, wxCallbacks);

    // 点击分享到朋友圈，会执行下面这个代码
    Api.shareToTimeline(wxData, wxCallbacks);

    // 点击分享到腾讯微博，会执行下面这个代码
    Api.shareToWeibo(wxData, wxCallbacks);
  });
</script>
