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
#define kilo * 1000			// 1k һǧ

clock_t last_time = clock(), current_time;	// ������Ϸ���е���һ��ʱ��͵�ǰʱ�䣬���ڿ�����Ϸ֡��
int mouse_x = 0, mouse_y = 0;		// �������
int game_over = false;		// �Ƿ���

void end_setting(int game_out);		// ������Ϸ����

void update(clock_t current_time);		// ������Ϸ����Ԫ��


// ˵��������Ϸ�󲿷ִ��붼ע����ϣ�����ˮƽ���ޣ������в��ֽ��Ͳ�����ϸ
// ��Ϸ��ɺ�ʱ10�죬���������ɣ�������Ϸ��ϵ������ѧϰ���̣�������Ϸ������Ƿȱ

int main(){
	srand((unsigned int)time(NULL));		// �������
	initgraph(1000, 600, EX_DBLCLKS | EX_SHOWCONSOLE);		// ����˫������ʾ����̨
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	cleardevice();
	puts("����");

	BeginBatchDraw();		// ����˫�����ͼ
	init_graph();			// ���Ƚ�����Ϸ��ʼ���ܽ���
	clock_t game_start_time = clock();		// ��¼��Ϸ��ʼʱ��
	clock_t game_time = 0;			// ʵ����Ϸ����ʱ��
	int boss_status = 0;		// boss����״̬
	int story_status = 0;		// ���£����飩����״̬
	int lives = 8;				// ���ʣ����������
	back_music = Musicv(wav_ctj34);		// ���ñ�������

	vtub_init();	// ��ʼ������
	if (0) {
		vtub_reac_clear();
		int p = subtitleQ.size();
		while (p--) subtitleQ.pop();
		voice_clear();
		vtub_story8();		// ��������˵
	}
	playerAlienL_add_one();		// ��ӳ�ʼ��Ҳ���������С��
	

	IMAGE backgroud;		// ������
	char backgroud_s[40];
	sprintf_s(backgroud_s, "res\\Picture\\BackGroud\\baback%02d.png", rand() % 28);
	loadimage(&backgroud, backgroud_s, 1000, 600, true);


	res_road_add();			// ��ӵ�·
	int key_alpha = 0, key_num = 0;		// ��������ĸ�������ּ��İ���״̬
	clock_t backgroup_update_t = 0;		// �ϴα��������ʱ��
	clock_t tst = 0;					// С�����ϴΰ���ʱ��
	clock_t subtitle_t = 0;				// �ϴε�Ļ����ʱ��
	clock_t tblockL_add_last_time = 0;	// �ϴ�ѡ�񷽿����ʱ��

	bool end_play = false;		// �Ƿ������Ϸ


#if 1
	while (true) {
		current_time = clock();		// ��¼��ǰʱ��
		game_time = current_time - game_start_time;		// ��¼ʵ������ʱ��
		if (current_time - last_time > 1000 / 90 && !game_over) {		// ����֡��
			last_time = current_time;

			cleardevice();	

			if (current_time > backgroup_update_t + 40 * 1000) {  // ���±�����,ÿ40�����һ��
				backgroup_update_t = current_time;
				sprintf_s(backgroud_s, "res\\Picture\\BackGroud\\baback%02d.png", rand() % 28);
				loadimage(&backgroud, backgroud_s, 1000, 600, true);
			}
			putimage(0, 0, &backgroud);

			setfillcolor(RGB(200, 100, 200));
			solidrectangle(100, 0, 100 + 416, 600);	// ��·������ɫ���

			update(current_time);		// ���¸�����ϷԪ��

			collide_check();		// ��������ײ���
			player_alien_move();		// ����ƶ�
			enemy_move();			// �����ƶ�

			//���Ƶ������
			{
				if (game_time <= 30 kilo) {		// ��Ϸʱ��<=30��
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

			//����boss����
			{
				if (game_time >= 30 kilo && !(boss_status & 1 << (1 - 1))) {	// ��boss1��û������ 
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

			// ���ƶ�ѡһ����
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

			// ���¸���
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

			// ��������ж�
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

			key_alpha = key_num = 0;  // ���ü��̰���״̬
			getkeyConsole(&key_alpha, &key_num);		// ��ȡ���̰��������µ�״̬
			ExMessage msg;		// ��ȡ�����������Ϣ
			if (peekmessage(&msg)) {
				mouse_x = msg.x, mouse_y = msg.y;	// �����������
			}

			if (clock() > tst + 200) {		// С���̰������������ȴ
				tst = clock();
				if (lives) {
					if (GetKeyState(VK_UP) & 0x8000) {
						playerAlienL_mutiply(2);		// С���̰��ϣ������������
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

			if (clock() > subtitle_t + 1000) {		// ���͵�Ļ
				subtitle_t = clock();
				views += (rand()%((int)(views * 0.02) * 2)) - ((int)(views * 0.02)) + 5;	// ģ����ʵֱ���������ùۿ��������ϱ仯
				for (int i = 0; i < log(views / 100 + 2.718); i += 1)
					if (rand() % 100 <= 60) add_a_subtitle();
			}

			if (game_time > 3000) {		// չʾ��������״̬
				display_mouse(msg);
				display_key(msg);
			}

			check_player_move(key_alpha);		// ���wasd��״̬����������ƶ�
			char s[30];
			sprintf_s(s, "LIVES : %d", lives);		// չʾ���ʣ������
			outtextxy(20, 380, s);

#if 1		// ��Ϸ����ж�
			if (game_out == 1 && current_time - game_start_time >= game_out_ddl) {
				if (!end_play) {
					end_play = true;
					music_play(wav_ctj24);
					music_play(wav_ctj48);
					music_play(wav_ctj2);
					back_music_update(wav_ctj16);
				}
				end_setting(game_out);	// ������ֽ���
				if (msg.message == WM_LBUTTONDOWN) {	// �˳������ok���ж�
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
#endif //��ַ�֧

			FlushBatchDraw();
		}
	}
	EndBatchDraw();
#endif


	return 0;
}



void end_setting(int game_out) {		// ��ֽ���
	for (int i = 0; i < playerAlienL.size(); i += 1) playerAlienL.pop_front();
	IMAGE out;
	loadimage(&out, "res/Picture/Initial_Groud/windowbase_inactive.png");
	putimage(350, 200, &out);
	outtextxy(460, 210, "����");
	char s[20];
	sprintf_s(s, "���  %d / 5", game_out);
	outtextxy(560, 210, s);
	if (game_out == 1) outtextxy(400, 300, "�ˣ��Ͷ���");
	else if (game_out == 2) outtextxy(400, 300, "����ķ�����������");
	else if (game_out == 3) outtextxy(400, 300, "������ƽ��Ҳͦ��");
	else if (game_out == 4) outtextxy(400, 300, "���緢�������");
	else if (game_out == 5) outtextxy(400, 300, "���粢���Ƶ�");
	setfillcolor(RED);
	fillrectangle(580, 350, 630, 370);
	outtextxy(600, 356, "OK");
}

void update(clock_t current_time) {		// ������ϷԪ�ظ���
	res_road_update(current_time);		// ��·����
	player_alien_update(current_time);	// ���С�˸���
	enemy_update(current_time);			// ���˸���
	runeL_update(current_time);			// ���ĸ���

	vtub_update(current_time);			// �������飨����������
	ctj_speak(current_time);			// �����������

	bullet_update();					// �������ӵ�����
	subtitle_update(current_time);		// ��Ļ����
	tblockL_update();					// ѡ�񷽿����
	music_update(current_time);			// ���ָ���
	back_music_check(current_time);		// �������ָ���
}







