        <!-- 头图 -->
         <?php foreach ($barbers as $barber) :?>
        <div class="topBanners">
            <div class="picWin">
                <ul js="sliderCont" class="clearfix">
                    <li>
                        <a href="#">
                             <img src="<?php print file_create_url($rowworks[$barber->bid]->field_work_image['und'][0]['uri']);?>" alt="">  
                        </a>
                        <div class="shopName">
                            <div class="name">艾美丽美发沙龙<?php print $rowshops[$barber->bid]->name;?>店</div>
                                 <div class="time">2013/06/06 23:33</div>
                        </div>
                        <div class="barberName">造型师 /<?php print $barber->name;?></div>
                    </li>
                 
                </ul>
            </div>
            <div class="navBtn" js="sliderTab">
                <a href="#" class="prev" style="display:none;"></a>
                <a href="#" class="next" style="display:none;"></a>
            </div>
        </div>
        <div class="orderBarber">
            <div class="barberInfo clearfix">
                <div class="avatar">
                    <span><div class="barimg"></div></span>
                </div>
                <div class="info">
                    <h2><?php print $barber->name;?></h2>
                    <div class="jobTitle"><?php print $rowshops[$barber->bid]->name;?>店技术总监</div>
                </div>
                <div class="orderBtn"><a href="#">预约他</a></div>
            </div>
            <div class="barberSign">
                <em class="quote start"></em>改变发型可以有比整形外科有更好更安全的修脸的效果，感谢光临丽锦的每一位客人，她们的信任是我源源不断的灵感之泉。<em class="quote end"></em>
            </div>
        </div>
         <?php endforeach;?>

   