<!-- HTML DOMS -->
    <div class="wrapper" id="changeStyle">
        <div class="photoLayer">
            <canvas class="cha"></canvas>
        </div>
        <div class="tookitBar">
            <div class="toolkit zoom" js="toolkit">
                <i class="ico"></i>
                <span>移动/缩放</span>
            </div>
            <div class="toolkit reset" js="toolkit">
                <i class="ico"></i>
                <span>复位</span>
            </div>
            <div class="toolkit more" js="toolkit">
                <i class="ico"></i>
                <span>更多发型</span>
            </div>
            <div class="toolkit save" js="toolkit">
                <i class="ico"></i>
                <span>保存</span>
            </div>
             <?php foreach ($hairstyles as $hairstyle) :?>
            <div class="styleList" js="styleList">
                <ul class="clearfix">
                    <li class="curr">
                         <div>
                        <span>
                    <img src="<?php print file_create_url($hairstyle->field_naked_pic['und'][0]['uri']);?>" alt="">
                        </span>
                      </div>
                    </li>
               </ul>
            </div>
              <?php endforeach;?>
        </div>
    </div>
    