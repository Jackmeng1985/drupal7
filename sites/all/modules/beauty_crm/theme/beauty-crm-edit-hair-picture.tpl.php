<?php 
$base_path = base_path();
/*<?php print $base_path . $directory; ?>/*/
?>

<div class="art">
  <div class="pic">
    <div class="userhead"><img id="imageHair" src="<?php print $base_path . $directory; ?>/js/pF6H8I5wiI.jpeg" width="462" height="693"></div>
  </div>
  <div class="upload">
    <div class="load">
      <div class="hair"><img src="<?php print $base_path . $directory; ?>/js/sDxydi1LPo.png" alt="" title=""></div>
      <!-- div class="btn"><a href="" class="upbtn"></a></div -->
    </div>
    <div class="complie">
      <div class="sel">
        <div class="face">
          <ul>
            <li><i id="eyeLeft" class="i_eye_left"></i>左眼</li>
            <li><i id="eyeRight" class="i_eye_right"></i>右眼</li>
            <li><i id="mouth" class="i_mouth"></i>嘴巴</li>
            <li><i id="hairContour" class="i_blue"></i>发型轮廓点</li>
          </ul>
        </div>
      </div>
      <div class="notice">拖动点到左边的图片中对应的位置</div>
      <div class="btn"><a href="http://choosebeauty.com.cn/admin/hair_style_edit?hairId=769#" class="fine"></a></div>
    </div>
  </div>
<i id="eyeLeftDot" name="EyeLeft" class="i_eye_left" style="top:258px;left:626px;"></i><i id="eyeRightDot" name="EyeRight" class="i_eye_right" style="top:255px;left:725px;"></i><i id="mouthDot" name="Mouth" class="i_mouth" style="top:377px;left:678px;"></i><i id="hc1" name="HairContour[]" class="i_blue" style="top:640px;left:697px;"></i><i id="hc2" name="HairContour[]" class="i_blue" style="top:176px;left:614px;"></i><i id="hc3" name="HairContour[]" class="i_blue" style="top:653px;left:850px;"></i><i id="hc4" name="HairContour[]" class="i_blue" style="top:317px;left:628px;"></i><i id="hc5" name="HairContour[]" class="i_blue" style="top:309px;left:784px;"></i><i id="hc6" name="HairContour[]" class="i_blue" style="top:182px;left:559px;"></i><i id="hc7" name="HairContour[]" class="i_blue" style="top:170px;left:835px;"></i><i id="hc8" name="HairContour[]" class="i_blue" style="top:73px;left:764px;"></i><i id="hc9" name="HairContour[]" class="i_blue" style="top:71px;left:659px;"></i><i id="hc10" name="HairContour[]" class="i_blue" style="top:355px;left:789px;"></i><i id="hc11" name="HairContour[]" class="i_blue" style="top:376px;left:595px;"></i><i id="hc12" name="HairContour[]" class="i_blue" style="top:437px;left:869px;"></i><i id="hc13" name="HairContour[]" class="i_blue" style="top:485px;left:683px;"></i><i id="hc14" name="HairContour[]" class="i_blue" style="top:544px;left:773px;"></i><i id="hc15" name="HairContour[]" class="i_blue" style="top:534px;left:876px;"></i><i id="hc16" name="HairContour[]" class="i_blue" style="top:544px;left:639px;"></i><i id="hc17" name="HairContour[]" class="i_blue" style="top:325px;left:867px;"></i><i id="hc18" name="HairContour[]" class="i_blue" style="top:357px;left:514px;"></i><i id="hc19" name="HairContour[]" class="i_blue" style="top:573px;left:603px;"></i><i id="hc20" name="HairContour[]" class="i_blue" style="top:264px;left:530px;"></i><i id="hc21" name="HairContour[]" class="i_blue" style="top:471px;left:742px;"></i><i id="hc22" name="HairContour[]" class="i_blue" style="top:495px;left:556px;"></i></div>
<form action="" method="post" enctype="multipart/form-data" id="form1" name="form1">
	<input id="http_method" name="http_method" type="hidden" value="PUT">
    <input id="hairId" name="hairId" type="hidden" value="769">
    <input id="hairStyle" name="hairStyle" type="hidden" value="1">
    <input id="rawHairContour" name="rawHairContour" type="hidden" value="[{&quot;x&quot;:305.45454545454544,&quot;y&quot;:832.5541125541125},{&quot;x&quot;:190.47619047619045,&quot;y&quot;:189.78354978354977},{&quot;x&quot;:517.4025974025974,&quot;y&quot;:850.5627705627705},{&quot;x&quot;:209.87012987012986,&quot;y&quot;:385.1082251082251},{&quot;x&quot;:425.97402597402595,&quot;y&quot;:374.025974025974},{&quot;x&quot;:114.28571428571428,&quot;y&quot;:198.09523809523807},{&quot;x&quot;:496.6233766233766,&quot;y&quot;:181.47186147186147},{&quot;x&quot;:398.26839826839824,&quot;y&quot;:47.099567099567096},{&quot;x&quot;:252.8138528138528,&quot;y&quot;:44.32900432900433},{&quot;x&quot;:432.90043290043286,&quot;y&quot;:437.74891774891773},{&quot;x&quot;:164.15584415584414,&quot;y&quot;:466.8398268398268},{&quot;x&quot;:543.7229437229437,&quot;y&quot;:551.3419913419913},{&quot;x&quot;:286.06060606060606,&quot;y&quot;:617.8354978354978},{&quot;x&quot;:410.7359307359307,&quot;y&quot;:699.5670995670995},{&quot;x&quot;:553.4199134199134,&quot;y&quot;:685.7142857142857},{&quot;x&quot;:225.1082251082251,&quot;y&quot;:699.5670995670995},{&quot;x&quot;:540.952380952381,&quot;y&quot;:396.19047619047615},{&quot;x&quot;:51.94805194805195,&quot;y&quot;:440.5194805194805},{&quot;x&quot;:175.23809523809524,&quot;y&quot;:739.7402597402597},{&quot;x&quot;:74.11255411255411,&quot;y&quot;:311.68831168831167},{&quot;x&quot;:367.79220779220776,&quot;y&quot;:598.4415584415584},{&quot;x&quot;:110.12987012987013,&quot;y&quot;:631.6883116883116}]">
    <input id="rawFacePoints" name="rawFacePoints" type="hidden" value="{&quot;EyeLeft&quot;:{&quot;x&quot;:207.09956709956708,&quot;y&quot;:303.37662337662334},&quot;EyeRight&quot;:{&quot;x&quot;:344.24242424242425,&quot;y&quot;:299.2207792207792},&quot;Mouth&quot;:{&quot;x&quot;:279.1341991341991,&quot;y&quot;:468.2251082251082}}">
</form>
<script type="text/javascript">

var OFFSET = 11;
var hairNum = 1; //计数起始
var hairMax = 50;//最大50个发型轮廓
var rate = 1;

(function ($) {
  var targDom = $('.userhead'),
    targDomW = targDom.width(),
    targDomH = targDom.height();

  var imageHair = $('#imageHair'),
    hairWidth = imageHair.width(),
    hairHeight = imageHair.height();
    
  
  var wRate = targDomW / hairWidth;
  var hRate = targDomH / hairHeight;
  rate = wRate > hRate? hRate: wRate;
  console.log('rate=%f, targDomW=%d, targDomH=%d, hairWidth=%d, hairHeight=%d', rate, targDomW, targDomH, hairWidth, hairHeight);

  imageHair.attr('width', hairWidth * rate);
  imageHair.attr('height', hairHeight * rate);

  restorePoints();

  // 左眼
  $('#eyeLeft').mousedown(function(e){
    e.preventDefault();
    if($('#eyeLeftDot'))
      $('#eyeLeftDot').remove();

    appendPoint('eyeLeftDot', 'EyeLeft', 'i_eye_left', e.pageX, e.pageY);

    chkPointsSingle($('#eyeLeftDot'));
  });

  // 右眼
  $('#eyeRight').mousedown(function(e){
    e.preventDefault();
    if($('#eyeRightDot'))
      $('#eyeRightDot').remove();

    appendPoint('eyeRightDot', 'EyeRight', 'i_eye_right', e.pageX, e.pageY);

    chkPointsSingle($('#eyeRightDot'));
  });

  // 嘴巴
  $('#mouth').mousedown(function(e){
    e.preventDefault();
    if($('#mouthDot'))
      $('#mouthDot').remove();

    appendPoint('mouthDot', 'Mouth', 'i_mouth', e.pageX, e.pageY);

    chkPointsSingle($('#mouthDot'));
  });

  // 发型轮廓
  $('#hairContour').mousedown(function(e){
    e.preventDefault();
    if(hairNum > hairMax)
    {
      alert('发型轮廓点已达到最大值！')
      return false;
    }

    var theId = 'hc' + hairNum;
    appendPoint(theId, 'HairContour[]', 'i_blue', e.pageX, e.pageY);

    chkPointsSingle($('#' + theId));
    hairNum++;
  });

  // 完成
  $('.fine').click(function (e) {
    savePoints();
    $('#form1').get(0).submit();
  });

  // 获取有效区域
  function getCorrectArea () {
    var targDom = $('.userhead'),
        targDomW = targDom.width(),
        targDomH = targDom.height(),
        targDomOffset = targDom.offset();
    return {
      startX : targDomOffset.left,
      endX : targDomOffset.left+targDomW,
      startY : targDomOffset.top,
      endY : targDomOffset.top+targDomH,
    }
  }

  function savePoints() {
    var area = getCorrectArea();
    var facePoints = {}, _facePoints = {};
    _facePoints.EyeLeft = $('[name=EyeLeft]');
    _facePoints.EyeRight = $('[name=EyeRight]');
    _facePoints.Mouth = $('[name=Mouth]');
    $.each(_facePoints,function(k,v){
      facePoints[k] = {};
      facePoints[k]['x'] = (parseInt(v.css('left')) + OFFSET - area.startX) / rate;
      facePoints[k]['y'] = (parseInt(v.css('top')) + OFFSET - area.startY) / rate;
    });
    $('#rawFacePoints').val(JSON.stringify(facePoints));
    console.log('rate=%f, %s', rate, $('#rawFacePoints').val());

    var hairContour = [];
    $.each($('[name="HairContour[]"]'), function(i, el){
      hairContour.push({
            x:(parseInt($(el).css('left')) + OFFSET - area.startX) / rate,
            y:(parseInt($(el).css('top')) + OFFSET - area.startY) / rate
          });
    });
    $('#rawHairContour').val(JSON.stringify(hairContour));
    console.log('rate=%f, %s', rate, $('#rawHairContour').val());
  }

  // 增加mouseup后的有效验证
  function chkPointsSingle(idom){
    var area = getCorrectArea(),
        _top,
        _left,
        fake = true;
    idom.mouseup(function(e){
      _top = parseInt($(this).css('top'))+OFFSET;
      _left = parseInt($(this).css('left'))+OFFSET;
      if(_top < area.startY || _top > area.endY || _left < area.startX || _left > area.endX)
      {
        $(this).remove();
        if($(this).attr('id').indexOf('hc')!= -1)
          hairMax++;
      }
    })
  }

  function restorePoints() {
    var facePoints = $.parseJSON($('#rawFacePoints').val());
    if (!facePoints) {
      facePoints = $.parseJSON('{"EyeLeft":{"x":150,"y":235},"EyeRight":{"x":250,"y":235},"Mouth":{"x":200,"y":320}}');
    } else {
      for (var itemKey in facePoints) {
        var item = facePoints[itemKey];
        //console.log('itemKey=%s, item=(%f, %f)', itemKey, item.x, item.y);
        item.x = item.x * rate;
        item.y = item.y * rate;
      }
    }

    var targDom = $('.userhead'),
        targDomOffset = targDom.offset();
    if (facePoints['EyeLeft'])
        appendPoint('eyeLeftDot', 'EyeLeft', 'i_eye_left', facePoints['EyeLeft']['x'] + targDomOffset.left, facePoints['EyeLeft']['y'] + targDomOffset.top);
    if (facePoints['EyeRight'])
        appendPoint('eyeRightDot', 'EyeRight', 'i_eye_right', facePoints['EyeRight']['x'] + targDomOffset.left, facePoints['EyeRight']['y'] + targDomOffset.top);
    if (facePoints['Mouth'])
        appendPoint('mouthDot', 'Mouth', 'i_mouth', facePoints['Mouth']['x'] + targDomOffset.left, facePoints['Mouth']['y'] + targDomOffset.top);

    var hairContour = $.parseJSON($('#rawHairContour').val());
    if (!hairContour) {
      hairContour = $.parseJSON('[{"x":94,"y":252},{"x":192,"y":203},{"x":316,"y":258},{"x":123,"y":165},{"x":280,"y":162}]');
    } else {
      for (var i = 0; i < hairContour.length; i++) {
        var item = hairContour[i];
        //console.log('-> item=(%f, %f)', item.x, item.y);
        item.x = item.x * rate;
        item.y = item.y * rate;
      }
    }

    $.each(hairContour, function(i, el){
      var theId = 'hc' + hairNum;
      appendPoint(theId, 'HairContour[]', 'i_blue', el['x'] + targDomOffset.left, el['y'] + targDomOffset.top);
      hairNum ++;
    });
  }
  
  function appendPoint(theId, theName, theClass, left, top) {
    var appHtml = '<i id="' + theId + '" name="' + theName + '" class="' + theClass
        + '" style="top:' + (top - OFFSET) +'px;left:'+ (left - OFFSET) +'px;"></i>';
    $('.art').append(appHtml);
    new Drag(theId, true);
  }
});

</script>
