<!-- HTML DOMS --> <script src="http://libs.baidu.com/jquery/2.0.0/jquery.min.js"></script>
<div class="wrapper" id="fp">
    <!-- 轮播图 -->
    <div class="slider">

        <div class="cont">
            <ul js="sliderCont" class="clearfix" style="margin-left:0;">
                <?php foreach ($hairstyles as $hairstyle) : ?>     <li>
                        <div class="img"><a href="#">
                                <img src="<?php print file_create_url($hairstyle->field_origin_pic['und'][0]['uri']); ?>" alt=""></a></div>
                        <div class="txt">
                            <div class="tit"><?php echo $hairstyle->name; ?></div>
                            <div class="comment"><?php echo $hairstyle->description; ?></div>
                        </div>
                    </li>
                <?php endforeach; ?>
            </ul>
        </div>
        <div class="tab">
            <ul js="sliderTab" class="clearfix" >
                <?php
                $i = 0;
                foreach ($hairstyles as $hairstyle) :
                    ?>
                    <li <?php $i == 0 ? print"class='curr'" : print""; ?>><span class="dot"></span></li>
                    <?php
                    $i++;
                endforeach;
                ?>
            </ul>
        </div>
    </div>

    <!-- 看发型/换发型 -->
    <div class="hairDesign">
        <div class="hairBtns">
            <a href="<?php print url(''); ?>" class="takeAlook" title="看发型">看发型</a>
            <a href="<?php print url('changestyle') ?>" class="haveAtry" title="换发型">换发型</a>
        </div>
    </div>
    <!-- 首页导航按钮 -->
    <div class="navBtn">
        <p class="infomation">
            <a href="<?php print url('usertabs') ?>"><span>个人中心</span><em>Infomation</em></a>
        </p>
        <p class="hairdresser">
            <a href="<?php print url('barberindex') ?>"><span>美发师</span><em>HairDresser</em></a>
        </p>
        <p class="merchants">
            <a href="http://m.163.com/"><span>商户</span><em>Merchants</em></a>
        </p>
    </div>
</div>
