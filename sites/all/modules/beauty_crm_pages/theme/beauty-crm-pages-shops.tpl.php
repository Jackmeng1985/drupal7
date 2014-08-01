<div class="wrapper" id="shopList">
        <!-- 头图 -->
        <div class="topBanners">
            <div class="picWin"><a href="http://www.baidu.com/"></a></div>
            <div class="shopName">
                <div class="tips">上次光临的分店：</div>
                <div class="name">艾美丽美发沙龙丽泽店</div>
                <div class="starsShow clearfix">
                    <span class="showStar score25"><i class="s1"></i><i class="s2"></i><i class="s3"></i><i class="s4"></i><i class="s5"></i></span>
                    <span class="score"><120m</span>
                </div>
                <div class="addr">朝阳区将台路12号</div>
            </div>
        </div>
        <!-- 店铺列表 -->
        <div class="shopList">
            <ul class="clearfix">
                <?php foreach ($shops as $shop): ?>
                <li>
                    <a href="<?php print url("shop/$shop->sid");?>">
                        <span class="name">
                            <em><?php print $shop->name; ?></em>
                            <b class="stars score50" js="starts">
                                <i class="s1"></i>
                                <i class="s2"></i>
                                <i class="s3"></i>
                                <i class="s4"></i>
                                <i class="s5"></i>
                            </b>
                        </span>
                        <span class="cards">优惠卡激活89次</span>
                        <span class="info">
                            <em class="addr"><?php print $shop->address;?></em>
                            <em class="distance">120m</em>
                        </span>
                    </a>
                </li>
                <?php endforeach;?>
            </ul>
        </div>
    </div>
    