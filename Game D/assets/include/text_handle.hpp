#ifndef TEXT_HANDLE_HPP
#define TEXT_HANDLE_HPP


// 该文件负责弹幕处理与主播话语处理



//弹幕处理
#if 1
class Subtitle {		// 定义弹幕类
public:
	char context[100];	// 弹幕类对象内容
	int x, y, speed;	// 弹幕类主播，速度
	COLORREF color;		// 弹幕类对象颜色
	bool colored = false;		// 弹幕类对象是否为彩色（颜色一直改变)
	clock_t ddl = -1;		// 弹幕类对象应该发送的时间

	Subtitle(char* s, int nx = 0,int ny = -1, int a = 0, int b = 0, int c = 0, int nspeed = 2) { // 弹幕类对象初始化
		strcpy_s(context, s);			// 弹幕内容，初始坐标，颜色的三个色素值，弹幕速度
		x = 1000 + nx, y = ny, speed = nspeed;
		if (y == -1) y = rand() % 200 + 10;
		if (a == 0 && b == 0 && c == 0) a = rand() % 255, b = rand() % 255, c = rand() % 255;
		color = RGB(a, b, c);
	}
	Subtitle(bool is_colored, char* s, int nx = 0,int nspeed = 2) {  // 弹幕类对象初始化2，用于创建彩色弹幕
		strcpy_s(context, s);
		x = 1000 + nx, speed = nspeed;
		y = rand() % 200 + 10;
		color = RGB(rand() % 255, rand() % 255, rand() % 255);
		colored = is_colored;
	}

	void update() {		// 弹幕类对象更新
		x -= speed;		// 弹幕类对象位置更新
		if (colored) settextcolor(RGB(rand() % 255, rand() % 255, rand() % 255));	// 弹幕类对象如果是彩色，更新颜色
		else settextcolor(color);
		outtextxy(x, y, context);	// 弹幕类对象文字显示
		settextcolor(BLACK);
	}
};

// 弹幕类内容定义
#if 1
char* subtext0 = "光啊~";
char* subtext1 = "主播行不行啊";
char* subtext2 = "主播好厉害爱了爱了";
char* subtext3 = "也就脸还行吧";
char* subtext4 = "尊嘟假嘟";
char* subtext5 = "古希腊掌管掌管的神";
char* subtext6 = "小天使请安";
char* subtext7 = "是懂节目效果的";
char* subtext8 = "+升天+";
char* subtext9 = "哇酷哇酷";
char* subtext10 = "都是总力战害了你";
char* subtext11 = "HaHaHaa";
char* subtext12 = "Ohhhhhhhhh";
char* subtext13 = "还是PVP大佬";
char* subtext14 = "WOC！盒";
char* subtext15 = "？？？？？";
char* subtext16 = "下！懂？";
char* subtext17 = "笨蛋一枚石锤了哈哈";
char* subtext18 = "真有意思";
char* subtext19 = "怎么感觉好多机器人？";
char* subtext20 = "游戏本该如此";
char* subtext21 = "湖北省洪山区珞喻路1037号华中科技大学实名xxx发射成功";
char* subtext22 = "超天酱还是有实力的";
char* subtext23 = "捏捏的就让我看这？";
char* subtext24 = "来看了一看，也就这吧，走了拜拜";
char* subtext25 = "屏幕前的陌生人你好啊";
char* subtext26 = "谢谢你";
char* subtext27 = "好可爱";
char* subtext28 = "前面的路以后再来探索吧";
char* subtext29 = "17个小人你能秒我？";
char* subtext30 = "爱你哦！！";
char* subtext31 = "L O V E";
char* subtext32 = "为师来喽ᕕ(◠ڼ◠)ᕗ";
char* subtext33 = "来啦～(∠・ω< )⌒☆​";
char* subtext34 = "ㅁ슴ㅁ슴ㅁ슴ㅁ슴ㅁ슴ㅁ슴 ㅁ슴ㅁ슴ㅁ슴ㅁ슴ㅁ슴ㅁ슴 ㅁ슴ㅁ슴ㅁ슴ㅁ슴ㅁ슴ㅁ슴";
char* subtext35 = "︎好好好( ᐛ )︎";
char* subtext36 = "✿✿ヽ(°▽°)ノ✿";
char* subtext37 = "(๑•̀ㅂ•́)ﾉ➹♡";
char* subtext38 = "- =͟͟͞͞ =͟͟͞͞ ﾍ( ´Д`)ﾉ";
char* subtext39 = "(ᇂ_ᇂ|||)";
char* subtext40 = "╰(⇀‸↼)╯";
char* subtext41 = "(๑•̌.•̑๑)ˀ̣ˀ̣";
char* subtext42 = "你特娘的还真是个天才";
char* subtext43 = "天生综艺感啊这是";
char* subtext44 = "不要再继续玩火了，但是请继续！";
char* subtext45 = "awsl ";
char* subtext46 = "这主播长得跟我老婆好像";
char* subtext47 = "颜控万岁";
char* subtext48 = "我每天都有看";
char* subtext49 = "我信你";
char* subtext50 = "小天使就是我的精神源泉";
char* subtext51 = "黑 暗 面 探 头";
char* subtext52 = "越 共 探 头";
char* subtext53 = "领   域   展   开 ヽ(°▽°)ノ";
char* subtext54 = "好好好可爱";
char* subtext55 = "卡哇伊得斯";
char* subtext56 = "听不懂思密达";
char* subtext57 = "大天使";
char* subtext58 = "火起来吧";
char* subtext59 = "神神神神神神神神神神";
char* subtext60 = "终于·等到你~";
char* subtext61 = "加油哦";
char* subtext62 = "zzzzz";
char* subtext63 = "超 天 萌 萌 哒";
char* subtext64 = "也太可爱了啪";
char* subtext65 = "我必每晚亿遍";
char* subtext66 = "好爽";
char* subtext67 = "升 天 状 态";
char* subtext68 = "咕楸";
char* subtext69 = "谁问你了";
char* subtext70 = "很喜欢一句话：啊？";
char* subtext71 = "sb";
char* subtext72 = "小鸡子露出了小黑脚";
char* subtext73 = "呦西";
char* subtext74 = "晚上好啊";
char* subtext75 = "笑死 好慌哦";
char* subtext76 = "手忙脚乱的样子好好笑";
char* subtext77 = "我特么笑出声";
char* subtext78 = "__ __,__ __!";
char* subtext79 = "这真是神回";
char* subtext80 = "我惹~~~~~~~";
char* subtext81 = "好热闹啊";
char* subtext82 = "鸡汤来喽";
char* subtext83 = "你这也行？";
char* subtext84 = "好厉害 但是";
char* subtext85 = "听君一席话 如听一席话";
char* subtext86 = "快乐就完事了";
char* subtext87 = "好开心啊";
char* subtext88 = "这这这这这这？";
char* subtext89 = "烦死了";
char* subtexts[90] = { subtext0,  subtext1,  subtext2,  subtext3,  subtext4,		subtext5 ,  subtext6 ,  subtext7 ,  subtext8,  subtext9 ,
						subtext10,  subtext11,  subtext12,  subtext13,  subtext14,	subtext15 ,  subtext16 ,  subtext17 ,  subtext18,  subtext19 ,
						subtext20,  subtext21,  subtext22,  subtext23,  subtext24,	subtext25 ,  subtext26 ,  subtext27 ,  subtext28,  subtext29 ,
						subtext30,  subtext31,  subtext32,  subtext33,  subtext34,		subtext35 ,  subtext36 ,  subtext37 ,  subtext38,  subtext39 ,
						subtext40,  subtext41,  subtext42,  subtext43,  subtext44,		subtext45 ,  subtext46 ,  subtext47 ,  subtext48,  subtext49 ,
						subtext50,  subtext51,  subtext52,  subtext53,  subtext54,		subtext55 ,  subtext56 ,  subtext57 ,  subtext58,  subtext59 ,
						subtext60,  subtext61,  subtext62,  subtext63,  subtext64,		subtext65 ,  subtext66 ,  subtext67 ,  subtext68,  subtext69 ,
						subtext70,  subtext71,  subtext72,  subtext73,  subtext74,		subtext75 ,  subtext76 ,  subtext77 ,  subtext78,  subtext79 ,
						subtext80,  subtext81,  subtext82,  subtext83,  subtext84,		subtext85 ,  subtext86 ,  subtext87 ,  subtext88,  subtext89 ,
};
#endif

#if 1
char* subtext_sto_five0 = "呀，就死了啊";
char* subtext_sto_five1 = "好菜啊不是我说";
char* subtext_sto_five2 = "主播行不行啊";
char* subtext_sto_five3 = "真是一塌糊涂啊";
char* subtext_sto_five4 = "主播不是一般的菜";
char* subtext_sto_five5 = "要不要我教你玩啊";
char* subtext_sto_five6 = "超天酱，不要紧的，继续吧";
char* subtext_sto_five7 = "好烂";
char* subtext_sto_five8 = "就这水平啊";
char* subtext_sto_five9 = "小老弟你给我坐坐坐坐坐坐下！";
char* subtext_sto_five10 = "主播是啥子吗";
char* subtext_sto_five11 = "还自称小天使？我看是堕天使吧";
char* subtext_sto_five12 = "这个世界不需要你这种five";
char* subtext_sto_five13 = "前面的吵什么啊，超天酱刚玩很正常啊";
char* subtext_sto_five14 = "不用对我家天使说这种话好不好";
char* subtext_sto_five15 = "sb";
char* subtext_sto_five16 = "骂又怎么了，隔着网线你能砍我不成";
char* subtext_sto_five17 = "真是笨蛋啊";
char* subtext_sto_five18 = "小天使，PLEASE HOLD ON YOUR DETREMINATION!";
char* subtext_sto_five19 = "玩不起就别玩";
char* subtext_sto_five20 = "给我闭嘴好不好，你行你上啊";
char* subtext_sto_five21 = "果然花瓶一个啊";
char* subtext_sto_five22 = "去捏的";
char* subtext_sto_five23 = "好菜，走了";
char* subtext_sto_five24 = "来看了一看，也就这吧，走了拜拜";
char* subtext_sto_five25 = "屏幕前的陌生人你好坏";
char* subtext_sto_five26 = "告辞不谢";
char* subtext_sto_five27 = "hhhhh";
char* subtext_sto_five28 = "给爷整笑了";
char* subtext_sto_five29 = "真菜啊";
char* subtext_sto_fives[30] = { subtext_sto_five0,  subtext_sto_five1,  subtext_sto_five2,  subtext_sto_five3,  subtext_sto_five4,		subtext_sto_five5 ,  subtext_sto_five6 ,  subtext_sto_five7 ,  subtext_sto_five8,  subtext_sto_five9 ,
						subtext_sto_five10,  subtext_sto_five11,  subtext_sto_five12,  subtext_sto_five13,  subtext_sto_five14,	subtext_sto_five15 ,  subtext_sto_five16 ,  subtext_sto_five17 ,  subtext_sto_five18,  subtext_sto_five19 ,
						subtext_sto_five20,  subtext_sto_five21,  subtext_sto_five22,  subtext_sto_five23,  subtext_sto_five24,	subtext_sto_five25 ,  subtext_sto_five26 ,  subtext_sto_five27 ,  subtext_sto_five28,  subtext_sto_five29
};
#endif


list<Subtitle> subtitleL;		// 已经存在于屏幕中的弹幕链表
queue<Subtitle> subtitleQ;		// 要发送的弹幕队列

void add_a_subtitle(bool is_colored = false) {		// 添加一个弹幕
	Subtitle sti(subtexts[rand()%90]);
	if (is_colored) sti.colored = true;		// 弹幕是否为彩色
	subtitleL.push_front(sti);
}
void add_a_subtitle(char *s , int nx = -10,bool is_colored = false) {	// 添加一个弹幕
	if (nx == -10) nx = rand() % 200;
	Subtitle sti(is_colored,s,nx);
	subtitleL.push_front(sti);
}
void add_a_subtitle(clock_t _ddl,char* s,bool is_colored = false,int nx = -10) {		// 添加一个弹幕（添加到队列）
	if (nx == -10) nx = rand() % 200;
	Subtitle sti(is_colored, s, nx);
	sti.ddl = _ddl;		// 弹幕欲添加的时间
	subtitleQ.push(sti);
}

bool is_subtitle_remove(Subtitle a) {		// 弹幕清除判断
	if (a.x + textwidth(a.context) < -2 ) return true;
	return false;
}

void subtitle_update(clock_t current_time) {		// 弹幕更新位置
	subtitleL.remove_if(is_subtitle_remove);		// 移除超出边界的弹幕
	if (!subtitleQ.empty()) {
		if (current_time > subtitleQ.front().ddl) {
			Subtitle sti = subtitleQ.front();		// 当前时间到底弹幕队列头的发送时间，发送这个弹幕到弹幕链表中
			subtitleL.push_front(sti);
			subtitleQ.pop();
		}
	}
	for (auto it = subtitleL.begin(); it != subtitleL.end(); it++) {
		(*it).update();
	}
}

#endif

//主播speak
#if 1
struct Voice {		// 主播话语
	char context[100];
	int x = 826, y = 580;
	clock_t ddl;		// 主播话语显示的截止时间

	Voice(char* s, clock_t _delay = 3000) {		// 主播话语初始化
		strcpy_s(context, s);
		ddl = clock() + _delay;
	}
};
queue<Voice> voiceQ;		// 主播话语队列

void voice_add(char s[], clock_t delay = 3000, int x = 826, int y = 580) {		// 添加主播话语
	Voice one(s,delay);
	if (voiceQ.empty()) one.ddl = clock() + delay;
	else one.ddl = voiceQ.back().ddl + delay;
	voiceQ.push(one);
}

void voice_clear() {		// 清空主播话语队列
	int p = voiceQ.size();
	while (p--) voiceQ.pop();
}

void ctj_speak(clock_t current_time) {		// 更新主播话语显示（显示在右下角）
	if (!voiceQ.empty()) {
		char* s = voiceQ.front().context;
		if (textwidth(s) > 348) outtextxy(1000 - textwidth(s) - 5, voiceQ.front().y - textheight(s) / 2, s);
		else outtextxy(voiceQ.front().x - textwidth(s) / 2, voiceQ.front().y - textheight(s) / 2, s);
		if (current_time >= voiceQ.front().ddl) voiceQ.pop();
	}
}
#endif


#endif