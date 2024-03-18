#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <graphics.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <list>
#include <queue>

#define LL long long int

#include "assets/include/MyLibrary.hpp"
#include "assets/include/mask_handle.hpp"
#include "assets/include/music_handle.hpp"
#include "assets/include/display_setting.hpp"
#include "assets/include/MySprites.hpp"
#include "assets/include/Sprite_handle.hpp"
#include "assets/include/text_handle.hpp"
#include "assets/include/story_collection.hpp"
using namespace std;
#define kilo * 1000			// 1k 一千

clock_t last_time = clock(), current_time;	// 定义游戏进行的上一次时间和当前时间，用于控制游戏帧率
int mouse_x = 0, mouse_y = 0;		// 鼠标坐标
int game_over = false;		// 是否结局

void end_setting(int game_out);		// 结束游戏界面

void update(clock_t current_time);		// 更新游戏各种元素


// 说明：该游戏大部分代码都注释完毕，但因水平有限，可能有部分解释不够详细
// 游戏完成耗时10天，代码独立完成，侧重游戏体系建构的学习过程，所以游戏性有所欠缺

int main(){
	srand((unsigned int)time(NULL));		// 随机种子
	initgraph(1000, 600, EX_DBLCLKS | EX_SHOWCONSOLE);		// 允许双击，显示控制台
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	cleardevice();
	puts("启动");

	BeginBatchDraw();		// 开启双缓冲绘图
	init_graph();			// 首先进入游戏初始介绍界面
	clock_t game_start_time = clock();		// 记录游戏开始时间
	clock_t game_time = 0;			// 实际游戏游玩时间
	int boss_status = 0;		// boss出场状态
	int story_status = 0;		// 故事（剧情）更新状态
	int lives = 8;				// 玩家剩余生命数量
	back_music = Musicv(wav_ctj34);		// 设置背景音乐

	vtub_init();	// 初始化主播
	if (0) {
		vtub_reac_clear();
		int p = subtitleQ.size();
		while (p--) subtitleQ.pop();
		voice_clear();
		vtub_story8();		// 开场白述说
	}
	playerAlienL_add_one();		// 添加初始玩家操作的外星小人
	

	IMAGE backgroud;		// 背景板
	char backgroud_s[40];
	sprintf_s(backgroud_s, "res\\Picture\\BackGroud\\baback%02d.png", rand() % 28);
	loadimage(&backgroud, backgroud_s, 1000, 600, true);


	res_road_add();			// 添加道路
	int key_alpha = 0, key_num = 0;		// 键盘里字母键和数字键的按下状态
	clock_t backgroup_update_t = 0;		// 上次背景板更新时间
	clock_t tst = 0;					// 小键盘上次按下时间
	clock_t subtitle_t = 0;				// 上次弹幕更新时间
	clock_t tblockL_add_last_time = 0;	// 上次选择方块更新时间

	bool end_play = false;		// 是否结束游戏


#if 1
	while (true) {
		current_time = clock();		// 记录当前时间
		game_time = current_time - game_start_time;		// 记录实际游玩时间
		if (current_time - last_time > 1000 / 90 && !game_over) {		// 控制帧率
			last_time = current_time;

			cleardevice();	

			if (current_time > backgroup_update_t + 40 * 1000) {  // 更新背景板,每40秒更新一次
				backgroup_update_t = current_time;
				sprintf_s(backgroud_s, "res\\Picture\\BackGroud\\baback%02d.png", rand() % 28);
				loadimage(&backgroud, backgroud_s, 1000, 600, true);
			}
			putimage(0, 0, &backgroud);

			setfillcolor(RGB(200, 100, 200));
			solidrectangle(100, 0, 100 + 416, 600);	// 道路背景底色填充

			update(current_time);		// 更新各种游戏元素

			collide_check();		// 精灵类碰撞检测
			player_alien_move();		// 玩家移动
			enemy_move();			// 敌人移动

			//控制敌人添加
			{
				if (game_time <= 30 kilo) {		// 游戏时长<=30秒
					if (enemyL.size() < 2) enemyL_add_one(rand() % 400 + 100);
				}
				else if (game_time <= 60 kilo) {
					if (enemyL.size() < 5) enemyL_add_one(rand() % 400 + 100);
				}
				else if (game_time <= 120 kilo) {
					if (enemyL.size() < 8) enemyL_add_one(rand() % 400 + 100);
				}
				else if (game_time <= 150 kilo) {
					if (enemyL.size() < 12) {
						int r = rand() % 100;
						if (r <= 80) enemyL_add_one(rand() % 400 + 100);
						else enemyL_add_one(-rand() % 150, rand() % 350, 0);
					}
				}
				else if (game_time <= 240 kilo) {
					if (enemyL.size() < 15) {
						int r = rand() % 100;
						if (r <= 50) enemyL_add_one(rand() % 400 + 100);
						else if (r <= 70) enemyL_add_one(-rand() % 150, rand() % 400, 0);
						else if (r <= 80) enemyL_add_one(1000 + rand() % 150, rand() % 450, 4);
						else if (r <= 90) enemyL_add_one(-rand() % 150, rand() % 500, 7);
						else enemyL_add_one(1000 - rand() % 150, -rand() % 200, 5);
					}
				}
				else if (game_time <= 300 kilo) {
					if (enemyL.size() < 20) {
						int r = rand() % 100;
						if (r <= 30) enemyL_add_one(rand() % 400 + 100);
						else if (r <= 50) enemyL_add_one(-rand() % 150, rand() % 400, 0);
						else if (r <= 70) enemyL_add_one(1000 + rand() % 150, rand() % 450, 4);
						else enemyL_add_one(-rand() % 150, rand() % 500, 7);
					}
				}
				else {
					if (enemyL.size() < 25) {
						int r = rand() % 100;
						if (r <= 30) enemyL_add_one(rand() % 400 + 100);
						else if (r <= 50) enemyL_add_one(-rand() % 150, 600 - rand() % 400, 0);
						else if (r <= 70) enemyL_add_one(1000 + rand() % 150, 600 - rand() % 500, 4);
						else enemyL_add_one(-rand() % 150, rand() % 500, 7);
					}
				}
			}

			//设置boss出场
			{
				if (game_time >= 30 kilo && !(boss_status & 1 << (1 - 1))) {	// 若boss1还没出场过 
					boss_status |= 1 << (1 - 1);
					boss_add(1);
				}
				else if (game_time >= 120 kilo && !(boss_status & 1 << (2 - 1))) {
					boss_status |= 1 << (2 - 1);
					boss_add(2);
				}
				else if (game_time >= 180 kilo && !(boss_status & 1 << (3 - 1))) {
					boss_status |= 1 << (3 - 1);
					boss_add(3);
				}
				else if (game_time >= 240 kilo && !(boss_status & 1 << (4 - 1))) {
					boss_status |= 1 << (4 - 1);
					boss_add(4);
				}
			}

			if (runeL.size() < 2) runeL_add_one(rand() % 400 + 100);

			// 控制二选一方块
			{
				if (game_time >= 180 kilo && tblockL.size() <= 5) {
					if (game_time >= tblockL_add_last_time + 3 kilo) {
						tblockL_add_last_time = game_time;
						tblockL_add(rand() % 2, rand() % 2, true);
					}
				}

				if (game_time <= 60 kilo) {
					if (tblockL.size() < 2) tblockL_add(0, 0);
				}
				else if (game_time <= 120 kilo) {
					int r = rand() % 2;
					if (tblockL.size() < 2) tblockL_add(r, 1 - r);
				}
				else {
					if (tblockL.size() < 2) tblockL_add(rand() % 2, rand() % 2);
				}
			}   

			// 故事更新
#if 1
			if (game_time >= 120 kilo && !(story_status & 1 << (1 - 1)) && !game_out) {
				story_status |= 1 << (1 - 1);
				vtub_reac_clear();
				int p = subtitleQ.size();
				while (p--) subtitleQ.pop();
				voice_clear();
				vtub_story1();
			}
			else if (game_time >= 240 kilo && !(story_status & 1 << (2 - 1)) && !game_out) {
				story_status |= 1 << (2 - 1);
				vtub_reac_clear();
				int p = subtitleQ.size();
				while (p--) subtitleQ.pop();
				voice_clear();
				vtub_story2();
			}
			else if (game_time >= 360 kilo && !(story_status & 1 << (3 - 1)) && !game_out) {
				story_status |= 1 << (3 - 1);
				vtub_reac_clear();
				int p = subtitleQ.size();
				while (p--) subtitleQ.pop();
				voice_clear();
				vtub_story3();
			}
#endif			

			// 结局条件判定
#if 1
			if (game_time >= 120 kilo && abs(ATK_muti) <= 100 
					&& !(story_status & 1 << (4 - 1)) && !game_out) {
				for (int i = 0; i < playerAlienL.size(); i += 1) playerAlienL.pop_front();
				story_status |= 1 << (4 - 1);
				if (rand() % 100 <= 70) {
					vtub_reac_clear();
					int p = subtitleQ.size();
					while (p--) subtitleQ.pop();
					voice_clear();
					vtub_story4();
				}
			}
			else if (lives == 0 && views <= 10000 && rand() % 100 <= 60 
					&& !(story_status & 1 << (5 - 1)) && !game_out) {
				story_status |= 1 << (5 - 1);
				for (int i = 0; i < playerAlienL.size(); i += 1) playerAlienL.pop_front();
				vtub_reac_clear();
				int p = subtitleQ.size();
				while (p--) subtitleQ.pop();
				voice_clear();
				vtub_story5();
			}
			else if (lives == 0 && !(story_status & 1 << (6 - 1))
					&& !game_out) {
				story_status |= 1 << (6 - 1);
				for (int i = 0; i < playerAlienL.size(); i += 1) playerAlienL.pop_front();
				vtub_reac_clear();
				int p = subtitleQ.size();
				while (p--) subtitleQ.pop();
				voice_clear();
				vtub_story6();
			}
			else if (game_time >= 360 kilo && views >= 100 kilo && !(story_status & 1 << (7 - 1))
					&& !game_out) {
				story_status |= 1 << (7 - 1);
				vtub_reac_clear();
				int p = subtitleQ.size();
				while (p--) subtitleQ.pop();
				voice_clear();
				vtub_story7();
			}
			else if (game_time >= 540 kilo && !(story_status & 1 << (8 - 1))
					&& !game_out) {
				story_status |= 1 << (8 - 1);
				vtub_reac_clear();
				int p = subtitleQ.size();
				while (p--) subtitleQ.pop();
				voice_clear();
				vtub_story8();
			}
#endif

			key_alpha = key_num = 0;  // 重置键盘按下状态
			getkeyConsole(&key_alpha, &key_num);		// 获取键盘按键被按下的状态
			ExMessage msg;		// 获取键盘与鼠标消息
			if (peekmessage(&msg)) {
				mouse_x = msg.x, mouse_y = msg.y;	// 更新鼠标坐标
			}

			if (clock() > tst + 200) {		// 小键盘按下情况，有冷却
				tst = clock();
				if (lives) {
					if (GetKeyState(VK_UP) & 0x8000) {
						playerAlienL_mutiply(2);		// 小键盘按上，玩家数量翻倍
						lives -= 1;
						views *= 0.96;
					}
					if (GetKeyState(VK_RIGHT) & 0x8000) {
						views *= 2;
						lives -= 1;
					}
					if (GetKeyState(VK_LEFT) & 0x8000) {
						views /= 2;
						lives -= 1;
					}
					if (GetKeyState(VK_DOWN) & 0x8000) {
						ATK_muti *= 2;
						lives -= 1;
					}
				}
			}

			if (clock() > subtitle_t + 1000) {		// 发送弹幕
				subtitle_t = clock();
				views += (rand()%((int)(views * 0.02) * 2)) - ((int)(views * 0.02)) + 5;	// 模拟真实直播环境，让观看人数不断变化
				for (int i = 0; i < log(views / 100 + 2.718); i += 1)
					if (rand() % 100 <= 60) add_a_subtitle();
			}

			if (game_time > 3000) {		// 展示鼠标与键盘状态
				display_mouse(msg);
				display_key(msg);
			}

			check_player_move(key_alpha);		// 检测wasd键状态来控制玩家移动
			char s[30];
			sprintf_s(s, "LIVES : %d", lives);		// 展示玩家剩余生命
			outtextxy(20, 380, s);

#if 1		// 游戏结局判定
			if (game_out == 1 && current_time - game_start_time >= game_out_ddl) {
				if (!end_play) {
					end_play = true;
					music_play(wav_ctj24);
					music_play(wav_ctj48);
					music_play(wav_ctj2);
					back_music_update(wav_ctj16);
				}
				end_setting(game_out);	// 弹出结局界面
				if (msg.message == WM_LBUTTONDOWN) {	// 退出程序的ok键判定
					if (mouse_x >= 580 && mouse_x <= 630 && mouse_y >= 350 && mouse_y <= 370)
						return 0;
				}
			}
			if (game_out == 2) {
				if (rand()%1000 <= 200) add_a_subtitle(true);
				views += 999;
				player_score += 99;
				lives += 9;
			}
			if (game_out == 2 && current_time - game_start_time >= game_out_ddl) {
				if (!end_play) {
					end_play = true;
					music_play(wav_ctj2);
					music_play(wav_ctj7);
					back_music_update(wav_ctj27);
				}

				end_setting(game_out);
				if (msg.message == WM_LBUTTONDOWN) {
					if (mouse_x >= 580 && mouse_x <= 630 && mouse_y >= 350 && mouse_y <= 370)
						return 0;
				}
			}
			if (game_out == 3 && current_time - game_start_time >= game_out_ddl) {
				if (!end_play) {
					end_play = true;
					music_play(wav_ctj2);
					music_play(wav_ctj4);
					music_play(wav_ctj8);
					back_music_update(wav_ctj17);
				}
				end_setting(game_out);
				if (msg.message == WM_LBUTTONDOWN) {
					if (mouse_x >= 580 && mouse_x <= 630 && mouse_y >= 350 && mouse_y <= 370)
						return 0;
				}
			}
			if (game_out == 4 && current_time - game_start_time >= game_out_ddl) {
				if (!end_play) {
					end_play = true;
					music_play(wav_ctj2);
					back_music_update(wav_ctj15);
				}
				end_setting(game_out);
				if (msg.message == WM_LBUTTONDOWN) {
					if (mouse_x >= 580 && mouse_x <= 630 && mouse_y >= 350 && mouse_y <= 370) 
						return 0;
				}
			}
			if (game_out == 5 && current_time >= game_out_ddl) {
				if (!end_play) {
					end_play = true;
					music_play(wav_ctj47);
					music_play(wav_ctj53);
					music_play(wav_ctj50);
					music_play(wav_ctj2);
					back_music_update(wav_ctj25);
				}
				end_setting(game_out);
				if (msg.message == WM_LBUTTONDOWN) {
					if (mouse_x >= 580 && mouse_x <= 630 && mouse_y >= 350 && mouse_y <= 370)
						return 0;
				}
			}
#endif //结局分支

			FlushBatchDraw();
		}
	}
	EndBatchDraw();
#endif


	return 0;
}



void end_setting(int game_out) {		// 结局界面
	for (int i = 0; i < playerAlienL.size(); i += 1) playerAlienL.pop_front();
	IMAGE out;
	loadimage(&out, "res/Picture/Initial_Groud/windowbase_inactive.png");
	putimage(350, 200, &out);
	outtextxy(460, 210, "结束");
	char s[20];
	sprintf_s(s, "结局  %d / 5", game_out);
	outtextxy(560, 210, s);
	if (game_out == 1) outtextxy(400, 300, "菜，就多练");
	else if (game_out == 2) outtextxy(400, 300, "她真的发现真相了吗");
	else if (game_out == 3) outtextxy(400, 300, "这样的平凡也挺好");
	else if (game_out == 4) outtextxy(400, 300, "网络发言需谨慎");
	else if (game_out == 5) outtextxy(400, 300, "网络并非善地");
	setfillcolor(RED);
	fillrectangle(580, 350, 630, 370);
	outtextxy(600, 356, "OK");
}

void update(clock_t current_time) {		// 各种游戏元素更新
	res_road_update(current_time);		// 道路更新
	player_alien_update(current_time);	// 玩家小人更新
	enemy_update(current_time);			// 敌人更新
	runeL_update(current_time);			// 铭文更新

	vtub_update(current_time);			// 主播表情（动作）更新
	ctj_speak(current_time);			// 主播话语更新

	bullet_update();					// 玩家射出子弹更新
	subtitle_update(current_time);		// 弹幕更新
	tblockL_update();					// 选择方块更新
	music_update(current_time);			// 音乐更新
	back_music_check(current_time);		// 背景音乐更新
}







