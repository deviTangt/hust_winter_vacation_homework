#ifndef STORY_COLLECTION_HPP
#define STORY_COLLECTION_HPP


// 该文件负责游戏中剧情处理的存储功能




// 初始界面
void init_graph() {
	IMAGE backgroud_init;
	IMAGE a, b, c, d, e, f;
	loadimage(&backgroud_init, "res\\Picture\\Initial_Groud\\windowbase_active.png", 1000, 600, true);
	loadimage(&a, "res\\Picture\\Initial_Groud\\icon_window_psyche.png");
	loadimage(&b, "res\\Picture\\Initial_Groud\\icon_desktop_youtube2.png");
	loadimage(&c, "res\\Picture\\Initial_Groud\\icon_desktop_game.png");
	loadimage(&d, "res\\Picture\\Initial_Groud\\icon_cho #16681.png");
	loadimage(&e, "res\\Picture\\Initial_Groud\\icon_desktop_folder_open1.png");
	loadimage(&f, "res\\Picture\\Initial_Groud\\windowbase_inactive.png");

	music_play(wav_ctj39,50,2);
	music_play(wav_ctj4);
	music_play(wav_ctj21);

	while (true) {
		music_repeat_check(wav_ctj39);
		putimage(0, 0, &backgroud_init);
		putimage_mask(50, 30, &a);
		putimage_mask(900, 30, &b);
		putimage_mask(500, 30, &c);
		outtextxy(200, 150, "你好，我是一个名为超天酱的虚拟网络主播");
		outtextxy(200, 180, "全名是【超绝最可爱天使酱】");
		outtextxy(200, 210, "现在我将要进行一场关于游玩一个小游戏的直播");
		outtextxy(200, 240, "请你协助我完成这个游戏，获得尽可能高的分数");
		outtextxy(200, 270, "分数的提高会吸引更多观众前来直播间观看");
		outtextxy(200, 300, "当然若观众过少我可能会因压力大而撑不住退播啦");
		outtextxy(200, 330, "所以，之后就拜托你啦~");
		outtextxy(200, 360, "如果你同意的话，请和小天使拉勾勾！");
		outtextxy(240, 450, "CLICK HERE ----->");
		putimage_mask(450, 425, &d);
	
		outtextxy(750, 150, "游戏玩法");
		putimage_mask(750, 175, &e);
		outtextxy(650, 250, "键盘WASD进行移动");
		outtextxy(650, 280, "初始拥有8条LIVES");
		outtextxy(650, 310, "使用小键盘上下左右键会消耗生命，获得效果");
		outtextxy(650, 340, "上键： 使玩家操纵小人数翻倍；");
		outtextxy(650, 370, "       无小人则复活一个小人");
		outtextxy(650, 400, "左键： views /= 2");
		outtextxy(650, 430, "右键： views *= 2");
		outtextxy(650, 460, "下键： ATK *= 2");
		outtextxy(650, 490, "LIVES 为0时游戏结束");
		ExMessage msg;
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x >= 450 && msg.x <= 501 && msg.y >= 425 && msg.y <= 451) {
					music_play(wav_ctj1);
					music_play(wav_ctj7);
					music_play(wav_ctj23);
					music_close(wav_ctj39);
					music_close(wav_ctj4);
					music_close(wav_ctj21);
					break;
				}
			}
		}
		FlushBatchDraw();
	}
}

// 开场白
void vtub_init() {
	views = 1000;		// 初始化观看数
	for (int i = 0; i < 30;i += 1) add_a_subtitle("小天使请安！",rand()%800);
	add_a_subtitle("小天使请安！", rand() % 800,true);		// 添加弹幕
	add_a_subtitle("小天使请安！", rand() % 800,true);
	vtub_addr(8, 3000);		// 添加主播表情
	voice_add("小天使请安！");		// 添加主播话语
	music_add(wav_ctj40, voiceQ.back().ddl - 3000);
	vtub_addr(2);
	voice_add("我是【超绝最可爱天使酱】，简称【超天酱】哦");
	music_add(wav_ctj43, voiceQ.back().ddl - 3000);
	add_a_subtitle(voiceQ.back().ddl + rand()% 3000, "名字好怪");
	add_a_subtitle(voiceQ.back().ddl + rand() % 3000, "好 很有精神 爱了");
	add_a_subtitle(voiceQ.back().ddl + rand() % 3000, "可爱！ 可爱！");
	add_a_subtitle(voiceQ.back().ddl + rand() % 3000, "新人 记住了");
	add_a_subtitle(voiceQ.back().ddl + rand() % 3000, "? !");
	add_a_subtitle(voiceQ.back().ddl + rand() % 3000, "! ! ! !");
	vtub_addr(4, 9000);
	voice_add("我乃从天而降的一道光");
	voice_add("照亮混沌的今夕网络世界");
	music_add(wav_ctj7, voiceQ.back().ddl - 3000);
	add_a_subtitle(voiceQ.back().ddl + rand() % 3000, "笑死");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "我是新人，请问这个主播是有病吗");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "好中二啊");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "谢谢，在外放，已经尬出两室一厅了");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "别犯病啊");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "谢谢你来到人间");
	voice_add("为漂泊在电子之海的宅宅们献上笑容！");
	voice_add("当代互联网小天使，堂堂降临！");
	music_add(wav_ctj24, voiceQ.back().ddl - 3000);
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "出现了————ε=ε=(＞Д＜)ノノ!!");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "╭(°A°`)╮哦（冷漠）");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "滚");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "相当不错吗");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "颜值区天花板");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "小天使请安！，不好意思现在才到");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "滚");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "嚯嚯");
	vtub_addr(6, 6000);
	voice_add("开场白就说到这里");
	voice_add("好，那开启进入我们今天的直播");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "前面的黑子也太过分了吧，不看滚");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "小天使爱你");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "好期待啊");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "来吧");
	vtub_addr(0, 9000);
	voice_add("我们今天要来玩一款网络沙雕小游戏");
	voice_add("如屏幕前的你们所见，就是我现在玩的这个游戏");
	voice_add("也是有很多粉丝推荐我玩，于是就来浅玩一下");
	music_add(wav_ctj41, voiceQ.back().ddl - 3000);
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "这款游戏我也有玩过唉");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "额，好普通的游戏，超天酱不能播点别的吗，太无聊了");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "原来是这款游戏啊");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "看起来很好玩的亚子");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "emm……");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "不管超天酱玩什么，我都会认真看的（认真脸）");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "超天酱好棒！");
	vtub_addr(12);
	voice_add("其实我不怎么会玩游戏的啦，菜的话请见谅");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "快进到玩游戏就要笑着玩");
	vtub_addr(2);
	voice_add("话说我上次玩这个游戏还是在上次呢。。。");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "《如玩》");
	vtub_addr(10);
	voice_add("哈哈哈");
	music_add(wav_ctj44, voiceQ.back().ddl - 3000);
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "超天酱笑起来好好看");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "要被治愈了喵");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "吧啦吧啦");
	add_a_subtitle(voiceQ.back().ddl + rand()%3000, "快进到玩游戏就要笑着玩");
}

void vtub_story1() {
	vtub_addr(0, 6000);
	voice_add("说个题外话，我今天早上去上海红棉街惹~");
	voice_add("虽说那里现在已经是主题咖啡店和城市化的天下了");
	add_a_subtitle("xiaxia", rand() % 800, true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好滴");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我昨天才去红棉街唉");
	vtub_addr(2);
	voice_add("不过幸好二手游戏店还开着");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "真不错");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "╭(°A°`)╮哦（冷漠）");
	vtub_addr(0, 9000);
	voice_add("超天酱买的呢，就是讲一个美术落榜生靠奋斗逆袭的故事");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "买游戏了？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好眼光");
	voice_add("里面哥特式的氛围和庄严的音乐最棒了");
	voice_add("相对的Boss也是超难打的啦......");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "模拟三战那个？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "针不戳");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "可以让我教教你吗?",true);
	vtub_addr(12, 9000);
	voice_add("不过通关后我们的主人公也是成功fashion做主人");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "硬核");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "那是啥？？？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "怎么尽玩大叔玩的东西啊");
	voice_add("最终迎娶了一位有着大胡子的异国公主");
	voice_add("完美诠释了什么叫做人生：奋斗与机遇");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "是很厉害");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "BGM爱了");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我感觉剧情很无聊唉");
	vtub_addr(18, 6000);
	voice_add("有机会的话想把整个系列都玩一遍");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "原来你喜欢模拟类的",true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "steam什么的有在用吗？",true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "敢不敢玩点新出的");
	voice_add("现在很多卡带已经绝版了，要全收集有点困难呢");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "B给你打钱，去买吧");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "还算有趣");
	vtub_addr(4);
	voice_add("但我是不会输的，看我把boss杀个片甲不留！！！");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "技术还可以");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "别输啊~");
	vtub_addr(2, 6000);
	voice_add("我读下评论");
	voice_add("【可以让我教教你吗？】");
	vtub_addr(5, 6000);
	voice_add("啊哈？不行哦·&");
	voice_add("【原来你喜欢模拟类的】");
	vtub_addr(0, 6000);
	voice_add("对！乱斗类的我也喜欢那个");
	voice_add("有个脱了战斗甲反而比较能打的女人的游戏");
	vtub_addr(2);
	voice_add("题外话至此，回归正题，继续现在的游戏吧");
}

void vtub_story2() {
	vtub_addr(3, 9000);
	voice_add("玩到这个我突然想到一个点子");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "可爱");
	voice_add("话说大家喜欢听阴谋论吗？");
	voice_add("反正我是超喜欢的，还经常主动搜来着");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我懂");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "阿宅都喜欢这个");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "阴谋论好刺激哦 喜欢",true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "原来超天酱也喜欢啊");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "阴谋论好吓人",true);
	vtub_addr(0, 12000);
	voice_add("今天嘛~我先来说一个阴谋论吧");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "别太深入了");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好懂哦");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "绝妙选择");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "？！");
	voice_add("【游戏角色阴谋论】");
	voice_add("这个是说我们所有人其实都不过是");
	voice_add("某个巨大游戏中的一员");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "啥<啥米！！＼(`Δ’)／");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好可怕");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "那怎么可能......");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我喜欢听这个");
	vtub_addr(17, 9000);
	voice_add("就像现在我们所玩的这个游戏一样");
	voice_add("出现了各种各样的角色");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我可不是阿宅！",true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我将心甘情愿被超天酱骗");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "搞这块内容也不是不行");
	voice_add("那有没有一种可能，我是说有一种可能");
	vtub_addr(18, 9000);
	voice_add("我，你们——超天酱和各位宅宅们—");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "这人继续直播下去感觉会变得很可怕", true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "乖乖不哭 (ɔˆз(ˆ⌣ˆc)");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "搞这块内容也不是不行");
	voice_add("——其实都是某个游戏中的NPC，供人把玩？");
	voice_add("是不是细思极恐呢？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好可怕哦，已经被吓晕了(„ಡωಡ„)");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好怕怕啊");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "怎么会这样呢");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "这个主播一派胡言");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我信你个鬼");
	vtub_addr(3, 15000);
	voice_add("我无法证明我说的是正确的，但同样的");
	voice_add("这件事也无法证伪，不是吗？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "是这样");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "道理是这么个道理");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我悟了大师");
	voice_add("正如庄周梦蝶，我们怎么判断我是蝴蝶，还是蝴蝶为吾？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "哦哦");
	voice_add("犹如伊甸园的存在无法证伪，这件事");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "突然开启贤者max模式");
	voice_add("本身处于一种量子态无法观测的地步");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "听不懂思密达");
	vtub_addr(2);
	voice_add("我说的难道不是很有道理吗？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "别吵，我在思考",true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "小脑萎缩了");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好厉害");
	vtub_addr(1, 9000);
	voice_add("好啦，不要恐慌了各位宅宅们");
	voice_add("反正我说的不一定对，既然真相尚未明朗");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "到底是谁在慌啊");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "嗯哼");
	voice_add("还是让我们对生活充满热情！积极奋斗吧！");
	vtub_addr(0, 9000);
	voice_add("之前悲观了些，但是不要一直虚无下去呦");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "快说谢谢超天酱");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "谢谢超天酱");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "哈哈有意思");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "领悟了");
	voice_add("让我读下评论");
	voice_add("【阴谋论好吓人】");
	vtub_addr(13, 9000);
	voice_add("害怕吗？在网上发现真相之前");
	voice_add("还是关掉电脑出去玩玩好哦");
	voice_add("【这人继续直播下去感觉会变得很可怕】");
	vtub_addr(32, 6000);
	voice_add("虾米！如果超天酱哪天堕入了黑暗");
	voice_add("到时你要来杀我哦");
	vtub_addr(2);
	voice_add("读评完毕，又不小心扯歪了哈，还是继续游戏吧");
}

void vtub_story3() {
	vtub_addr(43, 9000);
	voice_add("玩游戏玩的好久，宅宅们是不是会感动有一些枯燥？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "确实有点无聊");
	voice_add("不过好消息是有超天酱陪大家扯淡啦");
	voice_add("我现在继续聊个阴谋论话题吧");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好啊好啊");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "超天酱真懂我");
	vtub_addr(0, 12000);
	voice_add("据我所知我们的世界啊，再过三十年有可能统一哦");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "虾米？ε=(＞Д＜)ノ");
	voice_add("这就是【世界统一阴谋论】！");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "又开始了");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "这主播我看传谣能力999");
	voice_add("届时会有来自神秘力量的势力莅临地球");
	voice_add("为人类带来拯救？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "又开始谜语人了");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我不信");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "尊嘟假嘟",true);
	vtub_addr(21, 12000);
	voice_add("我们人类啊，总是不肯安于现状");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "又开始谜语人了");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我不信");
	voice_add("为了自己的私利，肆意开采地球资源，污染自然");
	voice_add("某些国家甚至可耻地，向蔚蓝洁净的海洋");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "hhhh");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "人类就是不可救药啊");
	voice_add("排放比恒河水还恶劣的物质");
	vtub_addr(29, 9000);
	voice_add("人类又为了争夺有限的资源，不惜对同类反目成仇");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "人类会为自己的行为付出代价的");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "资源啊");
	voice_add("互相开战，让世界永无安宁之日无数流离失所");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "战争好可怕");
	voice_add("不过一切就要改变了");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "啊？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "超天酱，我好怕怕，抱抱>3_3>-",true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我选择哈基米");
	vtub_addr(30, 15000);
	voice_add("再过30年，世界就会和平起来，会有人拯救我们的");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "哦哦哦哦哦");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我持半疑态度");
	voice_add("无论是拯救派也好，降临派也好");
	voice_add("救救人类吧！");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "是的");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "人类需要被拯救！");
	voice_add("或许会是三体人来，但也或许会是——");
	voice_add("我，超天酱来拯救你们！");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "消灭人类霸权，世界属于三体！");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "还文明以岁月！");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我更希望超天酱拯救我们！");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "超天酱，救救人类吧！");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "哈？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "超天酱，爱你");
	vtub_addr(4, 6000);
	voice_add("开个玩笑哈，切勿当真");
	voice_add("我看不少宅宅已经害怕起来了呢");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "虾米，原来是假的啊，好失落");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "可信度下降");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我的小天使");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "有趣但有趣，但有点犯忌");
	vtub_addr(12, 12000);
	voice_add("哪有什么神秘力量降维打击的啊");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "假的啊，好失望，要是人类真这样就好了",true);
	voice_add("你们不要信这些哦，你们只需要信超天酱就够了！");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "嗯，有超天酱就够了");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "小天使！！！");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "You Are Our's Angle!",true);
	voice_add("现在是读评时间");
	voice_add("【超天酱，我好怕怕，抱抱>3_3>-】");
	vtub_addr(13, 9000);
	voice_add("哈哈哈，小可爱，竟然真能被吓到啊");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "超门！", true);
	voice_add("这是不是说明我超天酱的传教能力真的很强啊");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "<--前面超门的逆天");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "笑死，超门");
	voice_add("【假的啊，好失望，要是人类真这样就好了】");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "超门加我一个");
	vtub_addr(42, 6000);
	voice_add("这位宅宅的头脑很危险哦");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我也要超超门");
	voice_add("要是真这样的话，你们可就见不到超天酱了哦");
	for (int i = 0; i < 30; i += 1) add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "超门!");
	vtub_addr(36, 6000);
	voice_add("而且有吾辈超天酱在，我是势必不会让那种事发生的！");
	vtub_addr(11);
	voice_add("继续游戏吧");
	vtub_addr(2);
}

//结局4
void vtub_story4() {
	back_music_update(wav_ctj32);
	vtub_addr(11, 12000);
	voice_add("哈哈哈，好好玩", 9000);
	add_a_subtitle(voiceQ.back().ddl - 6000, "请问那个和超天酱一样可爱的黑头发女孩是谁啊",true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "什么意思啊？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "超天酱最可爱，不接受反驳");
	voice_add("【请问那个和超天酱一样可爱的黑头发女孩是谁啊】");
	vtub_addr(32, 6000);
	voice_add("woc,盒！", 6000);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "盒武器来了吗？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "这下有戏看了");
	vtub_addr(22, 9000);
	voice_add("超天酱错了");
	add_a_subtitle(voiceQ.back().ddl - 3000, "你爹现在在我手里", true);
	voice_add("超天酱不该在网上口嗨的");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "来真的？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "主播不会连这都信吧");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好单纯啊");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "也有可能是真的吧");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "emmm");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "看不懂捏");
	voice_add("【你爹现在在我手里】");
	vtub_addr(33, 9000);
	voice_add("是是是");
	voice_add("只要别盒我");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "怎么感觉是在演戏呢");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "ooooo");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "虾米");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "？");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "真离谱啊");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "美国5星上将麦克阿瑟对此评论到：不是上门上不起，而是开盒更有性价比！");
	voice_add("我爹我妈都在你手里");
	vtub_addr(48, 90000);
	voice_add("主播已下播", 90000);
	game_out = 4;
	game_out_ddl = voiceQ.back().ddl - 90000 + 6000;
}

//结局5
void vtub_story5() {
	back_music_update(wav_ctj49);
	vtub_addr(37, 6000);
	voice_add("唉，又死掉了",6000);
	for (int i = 0; i < 30; i += 1) 
		add_a_subtitle(voiceQ.back().ddl - rand() % 6000, subtext_sto_fives[rand() % 30],true);
	vtub_addr(36, 6000);
	voice_add("可恶啊，明明就差一点点", 6000);
	for (int i = 0;i < 20;i += 1) 
		add_a_subtitle(voiceQ.back().ddl - rand() % 6000, subtext_sto_fives[rand()%30], true);
	vtub_addr(23, 6000);
	voice_add("话说你们是怎么回事啊，我就失误一点不至于这样子吧？",6000);
	for (int i = 0; i < 20; i += 1)
		add_a_subtitle(voiceQ.back().ddl - rand() % 6000, subtext_sto_fives[rand() % 30], true);
	vtub_addr(32, 6000);
	voice_add("你们能不能正常一点，我有点害怕", 6000);
	for (int i = 0; i < 20; i += 1)
		add_a_subtitle(voiceQ.back().ddl - rand() % 6000, subtext_sto_fives[rand() % 30], true);
	vtub_addr(27, 6000);
	voice_add("烦死了，骂骂骂，就知道骂");
	for (int i = 0; i < 20; i += 1)
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, subtext_sto_fives[rand() % 30], true);
	voice_add("你们一个二个嘴巴是烂掉了吗");
	vtub_addr(37, 6000);
	voice_add("我真的有做错什么吗");
	for (int i = 0; i < 20; i += 1)
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, subtext_sto_fives[rand() % 30],true);
	voice_add("...........");
	vtub_addr(31, 6000);
	voice_add("啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊", 6000);
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "她疯了！！", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "笑死 这就破防了？", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "啊啊啊啊啊啊啊啊啊啊啊啊啊啊", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "烦死了！！！！！", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "不要这样小天使，我好害怕", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "清醒点啊", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "毁灭吧！", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "变成堕天使了", true);
	}
	vtub_addr(26, 6000);
	voice_add("你们都tm有病是吧");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "她肯定是太累了", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "乐", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "超天酱你没事吧？", true);
	}
	voice_add("你们这些人很喜欢看我出丑吗");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "攻击力有待提高", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "就这水平啊，游戏不行，对线更垃圾", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "废物不配说话", true);
	}
	vtub_addr(25);
	voice_add("受不了了，你们真的是...");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "烦死了！！！！！", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "喜欢嘴硬是这样", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好废啊，这就不行了", true);
	}
	vtub_addr(34, 6000);
	voice_add("(嗯呃嗯额嗯哦)", 6000); for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "嗯？", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "要吐了。。。", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "哈哈哈哈哈", true);
	}
	vtub_addr(35, 6000);
	voice_add("(呕啊呕啊呕啊)", 6000);
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "真吐了啊", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "变成呕吐女了", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "xswl", true);
	}
	vtub_addr(34, 6000);
	voice_add("啊 我现在真的好想...算了");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "呕吐女，别捣蛋", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "就是就是", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "呕吐女哈哈", true);
	}
	voice_add("干脆把一切都结束掉算了......");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "那你去死啊", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "毁灭吧！", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "变成堕天使了", true);
	}
	vtub_addr(33,15000);
	voice_add("为什么我还活着啊");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "在哭", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "；；；", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "妆要花了", true);
	}
	voice_add("很怪吧 明明我只是个一文不值的废物");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "！！！！！", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "去死", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "振作起来啊", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "不要这样超天酱", true);
	}
	voice_add("对不起大家 上播说这些怪话");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "入典", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "66666", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "66666", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "66666", true);
	}
	voice_add("还在直播间呕……");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "入典", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好废啊，这就不行了", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "超天酱坚持住啊", true);
	}
	voice_add("大家一定很幻灭吧");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "入典", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "去死吧", true);
	}
	vtub_addr(41, 12000);
	voice_add("对不起啊 对不起啊");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "66666", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "无视小黑子好不好", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "去死吧", true);
	}
	voice_add("（呜咽声）");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "呕吐女", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "喜欢嘴硬是这样", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好废啊，这就不行了", true);
	}
	voice_add("对不起啊");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "休息下吧", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "小天使！！", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "hhhhhh", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好菜啊", true);
	}
	voice_add("今天就先下播吧");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "是不是报警比较好", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "呃哈哈", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "辛苦了", true);
	}
	for (int i = 0; i < 50;i += 1) add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "+升天+", true);
	//  ☨升天☨
	vtub_addr(48, 90000);
	voice_add("直播间已关闭...", 90000);
	game_out = 5;
	game_out_ddl = voiceQ.back().ddl - 90000 + 6000;
	//printf("GAME %d  %d\n", voiceQ.back().ddl, game_out_ddl);
}

//结局1
void vtub_story6() {
	back_music_update(wav_ctj29);
	vtub_addr(37, 6000);
	voice_add("唉，又死掉了", 6000);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "哈哈哈", true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好可爱", true);
	vtub_addr(36);
	voice_add("可恶啊，明明就差一点点");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "不要紧的", true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "再接再厉吧", true);
	vtub_addr(38);
	voice_add("这破游戏真的是");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "有你在就很好", true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "小天使加油啊", true);
	vtub_addr(37, 6000);
	voice_add("唉，今天状态果然很差啊",6000);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "并不是只有你一个人差啦", true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "才刚开始玩嘛，倒也正常", true);
	vtub_addr(40);
	voice_add("大家都被我弱智般的操作劝退了好多哈哈");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "哈哈哈", true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好可爱", true);
	vtub_addr(46, 6000);
	voice_add("继续直播下去估计也不会好太多");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "那就休息下吧", true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "那要不今天就到此为止吧", true);
	voice_add("果然超天酱还是不太会玩游戏啊");
	vtub_addr(11, 6000);
	voice_add("罢了罢了");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "嗯哼", true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "hhhhhh", true);
	voice_add("那今天就播到这里了吧");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好的", true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好可爱", true);
	vtub_addr(8);
	voice_add("谢谢各位的观看");
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "嚯嚯", true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "今天也辛苦了", true);
	vtub_addr(19, 3000);
	vtub_addr(47, 3000);
	voice_add("屏幕前还在的宅宅们，拜拜喽", 6000);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "拜拜喽", true);
	add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好的，下次也再会来的", true);
	vtub_addr(4, 6000);
	voice_add("+升天+", 6000);
	for (int i = 0; i < 20; i += 1) add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "+升天+", true);
	vtub_addr(48, 60000);
	voice_add("直播间已关闭", 60000);
	game_out = 1;
	game_out_ddl = voiceQ.back().ddl - 60000 + 6000;
}

//结局2
void vtub_story7() {
	back_music_update(wav_ctj14);
	vtub_addr(2, 6000);
	voice_add("哈，好多人啊", 6000);
	for (int i = 0; i < 1000; i += 1) add_a_subtitle(voiceQ.back().ddl - rand() % 6000,"小天使请安！", true);
	vtub_addr(43, 6000);
	voice_add("我就玩一会游戏的功夫");
	voice_add("直播间就涌入了这么多宅宅陪我一起");
	vtub_addr(14, 9000);
	voice_add("好幸福啊~", 6000);
	voice_add("不知道这一美好的时刻会不会一直持续下去~");
	vtub_addr(10, 9000);
	voice_add("哈~");
	voice_add("越来越多人出现了呢");
	voice_add("这个服务器恐怕要撑不住了呢");
	vtub_addr(5, 9000);
	voice_add("不，整个网络", 6000);
	voice_add("为什么那么多人会来观看呢");
	vtub_addr(12);
	voice_add("是因为超天酱有着什么魔力吗？");
	vtub_addr(9, 9000);
	voice_add("开个玩笑 哈哈", 6000);
	voice_add("嗨，其实我现在终于想明白了一件事");
	vtub_addr(4, 6000);
	voice_add("从这个奇妙的网络延发");
	voice_add("我突然想到");
	vtub_addr(3, 6000);
	voice_add("我们大家都还没有见过面吧");
	voice_add("你们知道超天酱，超天酱却不知道你们");
	vtub_addr(6, 9000);
	voice_add("网络犹如一个蜂窝");
	voice_add("将我们团团围住");
	voice_add("在网络空间，谁也分不清了谁");
	vtub_addr(43, 12000);
	voice_add("我们每个人身处其中");
	voice_add("皆好似一条绳上的蚂蚱");
	voice_add("我虽离你 尔却不离 处处相随");
	voice_add("汝欲亲吾 子却勿密 无处相寻");
	vtub_addr(45, 15000);
	voice_add("从这个奇妙的网络延发");
	voice_add("你我皆在奇点");
	voice_add("你我却不同归");
	voice_add("你我皆于殊途");
	voice_add("你我却胜稠点");
	vtub_addr(46, 15000);
	voice_add("网络将我们一个个个体划分入一个个相界");
	voice_add("虽无同行，但得同质");
	voice_add("犹如实数轴上的两点");
	voice_add("远 然距离终是定数");
	voice_add("近 但二点之间亦有无数");
	vtub_addr(14, 6000);
	voice_add("我们都被困在了网络世界");
	voice_add("我们都享受被困在网络世界");
	voice_add("所以我想说的是————");
	vtub_addr(0, 9000);
	voice_add("我们这个世界是由网络构成的！");
	voice_add("正如我先前所想");
	voice_add("其实我们都是网络世界的一个个NPC而已");
	vtub_addr(37, 9000);
	voice_add("哈哈哈 荒诞吧");
	voice_add("但事实如此");
	voice_add("有人发明了网络 有人又在网络中创造了我们");
	vtub_addr(19, 12000);
	voice_add("我们确然被操纵");
	voice_add("然而无妨");
	voice_add("因为此，我们活于网络");
	voice_add("因为此，超天酱得以与宅宅们相见");
	vtub_addr(21, 6000);
	voice_add("谢谢你们");
	voice_add("谢谢你");
	vtub_addr(5, 6000);
	voice_add("直播间要崩溃了，我们下次再见吧~");
	voice_add("那么，再见了各位");
	vtub_addr(15);
	vtub_addr(16);
	voice_add("宅宅们，爱你们(＾Ｕ＾)ノ~ＹＯ",6000);
	vtub_addr(17);
	voice_add("不要忘记超天酱哦~");
	vtub_addr(19,6000);
	voice_add("现在，让我们一起",6000);
	for (int i = 0; i < 3000; i += 1) add_a_subtitle(voiceQ.back().ddl - rand() % 6000, "+升天+", true);
	vtub_addr(49,6000);
	voice_add("迈向奇点！",6000); 
	vtub_addr(50);
	game_out = 2;
	game_out_ddl = voiceQ.back().ddl + 6000;
}

//结局3
void vtub_story8() {
	back_music_update(wav_ctj18);
	vtub_addr(43, 6000);
	voice_add("嗨，今天玩游戏也玩了很久了", 6000);
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好好好", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "是啊", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "不知不觉看超天酱玩游戏一晚上了", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "什么？现在几点？", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "awsl₍˄·͈༝·͈˄*₎◞ ̑̑", true);
	}
	vtub_addr(4, 6000);
	voice_add("我今天玩得很不错吧？", 6000);
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "+升天+", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "+升天+", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "+升天+", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "+升天+", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "+升天+", true);
	}
	vtub_addr(8, 6000);
	voice_add("我就说嘛，小天使不菜的", 6000);
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "很棒呢", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "完美(˃ ⌑ ˂ഃ )", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "可可爱爱爱没有脑袋", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "颜值与技术兼备啊", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "小菜子不6的", true);
	}
	vtub_addr(5);
	voice_add("今天和大家聊天也聊得很开心啊");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "开心", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "开森", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "今天也很充实", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "小天使给我力量", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "很不错呢", true);
	}
	vtub_addr(10);
	voice_add("谢谢大家了");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "也谢谢小天使啊", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "阿里可多", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "thank u⌓‿⌓", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "嗯嗯嗯嗯嗯", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "嘻嘻哈哈", true);
	}
	vtub_addr(2, 6000);
	voice_add("时候不早了，现在是晚上12点，大家也该睡觉了吧");
	vtub_addr(13);
	voice_add("超天酱给你们说声晚安哦");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "晚安小天使(●'◡'●)", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "超天酱晚安", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "Good Night", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "谢谢超天酱", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好啊好啊", true);
	}
	vtub_addr(21, 6000);
	voice_add("小天使会一直祝福宅宅们的");
	voice_add("祝大家留得好梦");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "会的会的(ง •̀_•́)ง", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "梦里会遇到超天酱吗", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我也累了，睡咯", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "嘿嘿，我的精神源泉", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "我爱了", true);
	}
	vtub_addr(17, 6000);
	voice_add("so", 6000);
	vtub_addr(18);
	voice_add("那就");
	vtub_addr(19, 6000);
	voice_add("今天就到这了,回见~", 6000);
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "回见ʕ ᵔᴥᵔ ʔ", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "明天也要继续加油哦", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "下次也要一起", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "好的，bb", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "可爱", true);
	}
	vtub_addr(20);
	voice_add("bye~bye~");
	for (int i = 0; i < 10; i += 1) {
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "卡哇伊(๑•̀ㅂ•́)ﾉ➹♡", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "嗯哼", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "变聪明了", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "超门！！！ᕕ(◠ڼ◠)ᕗ", true);
		add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "今天也辛苦了！", true);
	}
	vtub_addr(4, 6000);
	voice_add("+升天+", 6000);
	for (int i = 0; i < 100; i += 1) add_a_subtitle(voiceQ.back().ddl - rand() % 3000, "+升天+", true);
	vtub_addr(48, 60000);
	voice_add("直播间已关闭", 60000);
	game_out = 3;
	game_out_ddl = voiceQ.back().ddl - 60000 + 6000;
}




#endif