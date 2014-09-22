<?php $s = $_SERVER['HTTP_USER_AGENT'];?>
<?php

$str62keys = array(

"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",

 "a", "b", "c", "d", "e", "f", "g", "h", "i", 

 "j", "k", "l", "m", "n", "o", "p", "q", 

 "r", "s", "t", "u", "v", "w", "x", "y", 

 "z","A", "B", "C", "D", "E", "F", "G", "H", 

 "I", "J", "K", "L", "M", "N", "O", "P", 

 "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"

);



/**

 * 10进制值转换为62进制

 * @param {String} int10 10进制值

 * @return {String} 62进制值

 */

function int10to62($int10) {

 global $str62keys;

 $s62 = '';

 $r = 0;

 while ($int10 != 0)

 {

  $r = $int10 % 62;

  $s62 = $str62keys[$r].$s62;

  $int10 = floor($int10 / 62);

 }

 return $s62;

}

/**

 * 

 * 通过mid获得短格式

 * @param string $mid

 * @return 短格式

 */

function getCodeByMid($mid){

 $url = '';

 for ($i = strlen($mid) - 7; $i > -7; $i -=7) //从最后往前以7字节为一组读取mid

 {

  $offset1 = $i < 0 ? 0 : $i;

  $offset2 = $i + 7;

  $num = substr($mid, $offset1,$offset2-$offset1); 

  //mid.substring(offset1, offset2); 

  $num = int10to62($num);

  $url = $num .$url;

 }

 

 return $url;

}

echo getCodeByMid('221110410216147026');

?>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="initial-scale=1, maximum-scale=1, user-scalable=no, minimal-ui">
  <meta name="apple-mobile-web-app-capable" content="yes">
  <meta name="apple-mobile-web-app-status-bar-style" content="black">
  <title>测试</title>
</head>
<body>
  请测试一下下列每种情况的表现，并记录是否能拍照和上传图片
  <div class="case">
    <p>case1</p>
    <input type="file" accept="image/*" capture>
  </div>
  <div class="case">
    <p>case2</p>
    <input type="file" accept="image/*" capture="camera">
  </div>
  <div class="case">
    <p>case3</p>
    <input type="file"capture="camera">
  </div>
  <div class="case">
    <p>case4</p>
    <input type="file" capture>
  </div>
  <div class="case">
    <p>case5</p>
    <input type="file" accept="image/*">
  </div>
    <div class="case">
    <p>case6</p>
    <input type="file" accept="image/*;capture=camera"> 
  </div>
    <div class="case">
    <p>user agemnt</p>
    <?php print $s;?>
  </div>
</body>
</html>
