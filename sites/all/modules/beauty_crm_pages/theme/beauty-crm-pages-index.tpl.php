<!-- HTML DOMS -->
    <div class="wrapper" id="fp">
        <!-- 轮播图 -->
       <div class="slider">
            <?php foreach ($hairstyles as $hairstyle) :?>
            <div class="cont">
                <ul js="sliderCont" class="clearfix" style="margin-left:0;">
                    <li>
                        <div class="img"><a href="#">
                    <img src="<?php print file_create_url($hairstyle->field_origin_pic['und'][0]['uri']);?>" alt=""></a></div>
                        <div class="txt">
                            <div class="tit"><?php $hairstyle->name?></div>
                            <div class="comment"><?php $hairstyle->description?></div>
                        </div>
                    </li>
                    
                </ul>
            </div>
            <?php endforeach;?>
            <div class="tab">
                <ul js="sliderTab" class="clearfix" >
                    <li class="curr"><span class="dot"></span></li>
                    <li><span class="dot"></span></li>
                    <li><span class="dot"></span></li>
                </ul>
            </div>
        </div>
         
        <!-- 看发型/换发型 -->
        <div class="hairDesign">
            <div class="hairBtns">
                <a href="http://m.baidu.com/" class="takeAlook" title="看发型">看发型</a>
                <a href="http://m.163.com/" class="haveAtry" title="换发型">换发型</a>
            </div>
        </div>
        <!-- 首页导航按钮 -->
        <div class="navBtn">
            <p class="infomation">
                <a href="http://m.baidu.com/"><span>个人中心</span><em>Infomation</em></a>
            </p>
            <p class="hairdresser">
                <a href="http://www.sohu.com/"><span>美发师</span><em>HairDresser</em></a>
            </p>
            <p class="merchants">
                <a href="http://m.163.com/"><span>商户</span><em>Merchants</em></a>
            </p>
        </div>
    </div>
	 