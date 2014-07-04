<?php 
$base_path = base_path();
/*<?php print $base_path . $directory; ?>/*/
?>

<div class="art">
  <div class="pic">
    <div class="userhead"><img id="imageHair" src="<?php print $pic_origin_path; ?>" width="<?php print $pic_origin_width;?>" height="<?php print $pic_origin_height;?>" ></div>
  </div>
  <div class="upload">
    <div class="load">
      <div class="hair"><img src="<?php print $pic_path; ?>" alt="" title=""></div>
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
      <div class="btn"><a href="" class="fine" onclick="javascript:return false;"></a></div>
    </div>
  </div>
</div>
<form action="" method="post" enctype="multipart/form-data" id="form1" name="form1">
	<input id="http_method" name="http_method" type="hidden" value="PUT">
        <input id="rawHairContour" name="rawHairContour" type="hidden" value='<?php print $rawHairContour; ?>'>
    <input id="rawFacePoints" name="rawFacePoints" type="hidden" value='<?php print $rawFacePoints; ?>'>
</form>
<script type="text/javascript">

var OFFSET = 11;
var hairNum = 1; //计数起始
var hairMax = 50;//最大50个发型轮廓
var rate = 1;

(function ($) {
  Drupal.behaviors.Beauty_CRM_edit_hair_picture = {
  attach: function (context) {
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
  $('#hairContour').mousedown(function(e) {
                    e.preventDefault();
                    if (hairNum > hairMax)
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
                $('.fine').click(function(e) {
                    savePoints();
                    $('#form1').get(0).submit();
                });

                // 获取有效区域
                function getCorrectArea() {
                    var targDom = $('.userhead'),
                            targDomW = targDom.width(),
                            targDomH = targDom.height(),
                            targDomOffset = targDom.offset();
                    return {
                        startX: targDomOffset.left,
                        endX: targDomOffset.left + targDomW,
                        startY: targDomOffset.top,
                        endY: targDomOffset.top + targDomH,
                    }
                }

                function savePoints() {
                    var area = getCorrectArea();
                    var facePoints = {}, _facePoints = {};
                    _facePoints.EyeLeft = $('[name=EyeLeft]');
                    _facePoints.EyeRight = $('[name=EyeRight]');
                    _facePoints.Mouth = $('[name=Mouth]');
                    $.each(_facePoints, function(k, v) {
                        facePoints[k] = {};
                        facePoints[k]['x'] = (parseInt(v.css('left')) + OFFSET - area.startX) / rate;
                        facePoints[k]['y'] = (parseInt(v.css('top')) + OFFSET - area.startY) / rate;
                    });
                    $('#rawFacePoints').val(JSON.stringify(facePoints));
                    console.log('rate=%f, %s', rate, $('#rawFacePoints').val());

                    var hairContour = [];
                    $.each($('[name="HairContour[]"]'), function(i, el) {
                        hairContour.push({
                            x: (parseInt($(el).css('left')) + OFFSET - area.startX) / rate,
                            y: (parseInt($(el).css('top')) + OFFSET - area.startY) / rate
                        });
                    });
                    $('#rawHairContour').val(JSON.stringify(hairContour));
                    console.log('rate=%f, %s', rate, $('#rawHairContour').val());
                }

                // 增加mouseup后的有效验证
                function chkPointsSingle(idom) {
                    var area = getCorrectArea(),
                            _top,
                            _left,
                            fake = true;
                    idom.mouseup(function(e) {
                        _top = parseInt($(this).css('top')) + OFFSET;
                        _left = parseInt($(this).css('left')) + OFFSET;
                        if (_top < area.startY || _top > area.endY || _left < area.startX || _left > area.endX)
                        {
                            $(this).remove();
                            if ($(this).attr('id').indexOf('hc') != -1)
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

                    $.each(hairContour, function(i, el) {
                        var theId = 'hc' + hairNum;
                        appendPoint(theId, 'HairContour[]', 'i_blue', el['x'] + targDomOffset.left, el['y'] + targDomOffset.top);
                        hairNum++;
                    });
                }

                function appendPoint(theId, theName, theClass, left, top) {
                    var appHtml = '<i id="' + theId + '" name="' + theName + '" class="' + theClass
                            + '" style="top:' + (top - OFFSET) + 'px;left:' + (left - OFFSET) + 'px;"></i>';
                    $('.art').append(appHtml);
                    new Drag(theId, true);
                }
            }
        }
})(jQuery);

</script>
