#ifndef SPRITE_HANDLE
#define SPRITE_HANDLE
#include "MySprites.hpp"
#include <list>


// ���ļ���Ҫ���ھ�����Ĵ�����ع���
// �����õ�·�ƶ����������Ҽ���ײ���������


// �����·����ṹ
#if 1
struct Ares {		// ÿ����·����ṹ�Ĵ�СΪ32 * 32
	MySprite* msptr = NULL;			// ��·����ṹ����Ӧ��Դ������
	int x, y, frame = 0;			// ��·����ṹ����Ļ�ϵ�������λͼ֡��ֵ
	Ares(MySprite* nmsptr = NULL, int nx = 0, int ny = 0, int nframe = 0) {		// ��·����ṹ��ʼ��
		msptr = nmsptr, x = nx, y = ny, frame = nframe;
	}
};
Ares road_map[15][20];		// �����·��Ϊ��ά���飬�����ɵ�·����ṹ��ɣ���·��Ϊ14 * 32����Ϊ19 * 32


void res_road_add() {		// ��ʼ����·��ά���飬Ϊÿ��Ԫ�����ö�Ӧ�ĵ�·����
	for (int i = 0; i <= 13; i += 1) {
		for (int j = 0; j <= 18; j += 1) {
			int frame1 = rand() % 360;
			int frame2 = rand() % 360;
			road_map[i][j] = Ares{ &res_city1,0,0,frame1};
		}
	}
}


clock_t road_last_time = 0;	// ��·���µ���һ��ʱ��

void res_road_update(clock_t current_time,int ticks = 250) {	// ��·���£�ticks��ʾ��·���µ�ʱ����
	if (current_time > road_last_time + ticks) {
		road_last_time = current_time;
		for (int i = 0; i < 13; i += 1) {
			for (int j = 18; j >= 1; j -= 1) {
				road_map[i][j] = road_map[i][j - 1];		// ʹ��·���ϵ�������
			}
			road_map[i][0] = Ares{ &res_city1,0,0,rand() % 360 };	// ��·���϶���������µĵ�·����
		}
	}

	for (int i = 0; i < 13; i += 1) {
		for (int j = 0; j <= 18; j += 1) {
			(*road_map[i][j].msptr).drawf(100 + i * 32, j * 32, road_map[i][j].frame); // ���Ƶ�·����
		}
	}
}
#endif

//���
#if 1
LL player_score = 0;	// ��ҵ÷֣�ͨ������������÷֣�

struct PAlien { PlayerAlien alien; };	// �������С�ˣ�alien����Ҳ���������С�ˣ�
list<PAlien> playerAlienL;		// ���С�˵�����
int playerAlienL_len[2] = { 0 };	// �������С��level0��level1�����������С���㹻��ʱ��ϳɴ�����С�ˣ�level1����
list<Bullet> bulletL;				// ���С�˷������ӵ�����

void playerAlienL_add_one(int x = 300,int y = 600,int level = 0) {		// ���һ�����С��C
	PlayerAlien Pone(rand()%5 * 2,level);		// ����һ�������ʽ����ɫ�������С�ˣ������ü���Ĭ��Ϊ0����С��
	if (x == 300 && y == 600 && playerAlienL.size()) {	// δָ��xy���겢���С�˸�����0ʱ
		auto paptr = playerAlienL.end();
		paptr--;
		x = paptr->alien.rect.topleft.x;		// ���µ����С�����������С�������������С�˸���
		y = paptr->alien.rect.topleft.y;
	}
	Pone.positionf = Pointf{ (float)x,(float)y };
	if (level == 0 && playerAlienL_len[0] < 60) playerAlienL.push_front(PAlien{ Pone});	// ��ֹ���ڿ��٣��������С������
	else if (level == 1 && playerAlienL_len[1] < 30) playerAlienL.push_back(PAlien{ Pone });
	playerAlienL_len[level] += 1;		// �ö�Ӧ��level�����С������+1
}

void playerAlineL_merge() {				// �ϲ����С��    ���С���㹻��ʱ��ϳɴ�����С�ˣ�level1��
	if (playerAlienL.size() >= 50 && playerAlienL_len[1] < 30) {
		while (playerAlienL_len[0] >= 30) {
			playerAlienL_len[0] -= 4;
			for (int i = 0; i < 4; i += 1) 
				if (!playerAlienL.empty())
					playerAlienL.pop_front();
			playerAlienL_add_one(300, 450, 1);  // ���ɵĵ����С�ˣ�level1�� 
		}
	}
}

void playerAlienL_mutiply(float muti) {// ʹ���С���������Ա���������С�������һ��С�� 
	int n = (int)(playerAlienL_len[0] * (muti - 1));		// ���Ա�����Ӧ����ӵ������С������
	for (int i = 0; i < n; i += 1) {
		playerAlienL_add_one();
	}
	if (playerAlienL_len[0] == 0) playerAlienL_add_one();	// ����С�������һ��С�� 
}


void player_shoot(int x,int y,int width,int height,int ATK) {  // ʹ���С�˷����ӵ�
	Bullet one = Bullet{ x,y,width,height,ATK };		// ����һ���ӵ�
	bulletL.push_front(one);		// ���ӵ���ӵ��ӵ�������
}

clock_t last_shoot_time = 0;		// �ϴ��ӵ�����ʱ��
clock_t shoot_dps = 300;			// �����ӵ������ʱ����

bool is_remove_alien(PAlien a) {		// �ж����С���Ƿ��������Ƴ�������ֻ����������С�˸��º�����ʹ��
	if (a.alien.HP <= 0) {		// HP <= 0 ��������
		playerAlienL_len[a.alien.level] -= 1;
		return true;
	}
	return false;
}

void player_alien_update(clock_t current_time) {		// ���С�˸��º���
	playerAlienL.remove_if(is_remove_alien);		// �ж����С���Ƿ��������Ƴ�����
	for (auto it = playerAlienL.begin(); it != playerAlienL.end(); it++) {		// �������С������
		(*it).alien.update(current_time);		// ���С�˸��£����¶�����
		(*it).alien.draw();			// ���С�˻���
		if (current_time > last_shoot_time + shoot_dps) {	// ���С�˷����ӵ�
			player_shoot((*it).alien.rect.topleft.x, (*it).alien.rect.topleft.y - 20, 3, 8, (*it).alien.HP / 10);
		} // �����ӵ�
	}
	if (current_time > last_shoot_time + shoot_dps) {
		last_shoot_time = current_time;		// �������С���ϴη����ӵ���ʱ��
	}
	char s[30];
	sprintf_s(s,"Alien Numbers:%d", playerAlienL.size());	// չʾ���С�˵�ǰ������
	outtextxy(20, 300, s);
	sprintf_s(s, "ATK:%d", ATK_muti);			// չʾ���С�˵Ĺ�����
	outtextxy(20, 340, s);
	sprintf_s(s, "SCORE: %d", player_score);	// չʾ��ҵ÷�
	outtextxy(20, 360, s);
}


void player_alien_move() {	// ���С���ƶ�
	playerAlineL_merge();		// ���С�˺ϲ���������������Ļ���
	for (auto it = playerAlienL.begin(); it != playerAlienL.end(); it ++) {
		(*it).alien.move();
	}
}

void check_player_move(int key_alpha) {		// ���ݼ��̵�����������ж����С���Ƿ��ƶ����Լ��ƶ�����
	int direction = -1;
	if (key_alpha & 1 << 'D' - 'A' && key_alpha & 1 << 'W' - 'A') direction = 1;
	else if (key_alpha & 1 << 'A' - 'A' && key_alpha & 1 << 'W' - 'A') direction = 3;
	else if (key_alpha & 1 << 'A' - 'A' && key_alpha & 1 << 'S' - 'A') direction = 5;
	else if (key_alpha & 1 << 'D' - 'A' && key_alpha & 1 << 'S' - 'A') direction = 7;
	else if (key_alpha & 1 << 'D' - 'A') direction = 0;
	else if (key_alpha & 1 << 'W' - 'A') direction = 2;
	else if (key_alpha & 1 << 'A' - 'A') direction = 4;
	else if (key_alpha & 1 << 'S' - 'A') direction = 6;
	for (auto it = playerAlienL.begin(); it != playerAlienL.end(); it++) {
		(*it).alien.setdirection(direction);		// �������С���ƶ�����-1��ʾ��ֹ��
	}
}


bool is_bullet_remove(Bullet one) {		// �ж��ӵ��Ƿ�Ӧ�������
	if (one.rect.topleft.y < -20 || one.ATK <= 0) return true;		// �ӵ������߽���Ѿ������Ŀ�꣨ATK����Ϊ0�����Ƴ�
	return false;
}

void bullet_update() {		// �ӵ�����
	bulletL.remove_if(is_bullet_remove);
	for (auto it = bulletL.begin(); it != bulletL.end(); it++) {
		(*it).update();
	}
}
#endif

//����
#if 1
int enemy_num = 0;		// ��������
list<Enemy> enemyL;		// �����������

void enemyL_add_one(int x = 0, int y = 0,int direction = 6) {	// ��ӵ���
	if (x == 0) x = rand() % 400 + 100;		// ���õ���x����
	if (direction == 6) {		// ���ϵ����ƶ���ֻ��һ�ֵ���
		Enemy Pone(Res_animal[rand() % 10], x, y);		// ����ͷ����
		if (clock() > 3 * 1000) Pone.origin_HP = Pone.HP = 3 * (clock() / 1000) + 100 * log10(clock() / 300) + ATK_muti * 5;
		enemyL.push_front(Pone);		// ����Ѫ�����ø���ʵ���������
	}
	else if (direction == 0) {
		int r = rand() % 100;
		if (r <= 10) {
			Enemy Pone(Res_planet[rand()%10], x, y, direction);		// ���ǵ���
			Pone.origin_HP = Pone.HP = 100 + abs(ATK_muti * 2);
			enemyL.push_front(Pone);
		}
		else if (r <= 60) {
			int p = rand() % 41;
			while (p == 7 || p == 17 || p == 19 || p == 28) p = rand() % 41;
			Enemy Pone(Res_yuan[p], x, y, direction);		// һ��ͼƬ
			Pone.origin_HP = Pone.HP = 100 + abs(ATK_muti * 2);
			enemyL.push_front(Pone);
		}
		else {
			Enemy Pone(Res_tanks_bullet[rand()%4], x, y, direction);		// ̹����̹���ӵ��ĵ���
			Pone.origin_HP = Pone.HP = 100 + abs(ATK_muti * 2);
			enemyL.push_front(Pone);
		}
	}
	else if (direction == 4) {
		Enemy Pone(Res_planet[0], x, y, direction);
		Pone.origin_HP = Pone.HP = 100 + abs(ATK_muti * 3);
		enemyL.push_front(Pone);
	}
	else {
		Enemy Pone(Res_planet[0], x, y, direction);
		Pone.origin_HP = Pone.HP = 100 + abs(ATK_muti * 3);
		enemyL.push_front(Pone);
	}
	enemy_num += 1;
}

bool is_remove_enemy(Enemy a) {		// �����Ƿ�Ӧ�������
	if (a.HP <= 0) {		// ����Ѫ�� <= 0ʱ�������𣬶Ե����Ƿ�Ϊboss������ͨ���˼������֣����ý�����ͬ
		if (a.is_boss) {
			player_score += (LL)90 * abs(ATK_muti) / max(1, playerAlienL.size());
			views += 450 * log10(clock() / 100) + (rand() % ((int)(views * 0.01)));
		}
		else {
			player_score += (LL)3 * abs(ATK_muti) / max(1,playerAlienL.size());
			views += 15 * log10(clock() / 100) + (rand()%((int)(views * 0.01)));
		}
		return true;
	}
	if (a.HP >= a.origin_HP * 1.5) {
		if (a.is_boss) {
			player_score += (LL)270 * abs(ATK_muti) / max(1, playerAlienL.size());
			views += 1350 * log10(clock() / 100) + (rand() % ((int)(views * 0.01)));
		}
		else {
			player_score += (LL)9 * abs(ATK_muti) / max(1, playerAlienL.size());
			views += 45 * log10(clock() / 100) + (rand() % ((int)(views * 0.01)));
		}
		return true;
	}
	if (a.rect.topleft.y < -400 || a.rect.topleft.y > 620 || a.rect.topleft.x < -100 || a.rect.topleft.x > 1200) return true;
		// ���˳����߽磬ֱ�����
	return false;	
}

void enemy_update(clock_t current_time) {	// ���˸���
	enemyL.remove_if(is_remove_enemy);		// ���Ӧ������ĵ���
	for (auto it = enemyL.begin(); it != enemyL.end(); it++) {
		(*it).update(current_time);		// ���µ���ͼ�񣨶�����
		(*it).draw();				// ���˻���
		(*it).display_HP();			// ����չʾѪ��
	}
	char s[30];
	sprintf_s(s, "Enemy Numbers:%u", enemy_num);		// չʾ�����Ѿ����ֵ�����
	outtextxy(20, 320, s);
}

void enemy_move() {		// �����ƶ�
	for (auto it = enemyL.begin(); it != enemyL.end(); it++) {
		(*it).move();
	}
}

void boss_add(int x) {			// ���boss����boss�Ƚϼ�ª
	if (x == 1) {
		Enemy Pone(Res_yuan[7], 250, -150 , 6);
		Pone.origin_HP = Pone.HP = (LL)4e4 + abs(ATK_muti * 20);
		Pone.velocity = Pointf{ 0.05,0.2 };		// boss�ٶȵ�������
		Pone.is_boss = 1;
		enemyL.push_front(Pone);
	}
	else if (x == 2) {
		Enemy Pone(Res_yuan[17], 400, -350, 6);
		Pone.origin_HP = Pone.HP = (LL)2e5 + abs(ATK_muti * 20);
		Pone.velocity = Pointf{ -0.05,0.3 };
		Pone.is_boss = 2;
		enemyL.push_front(Pone);
	}
	else if (x == 3) {
		Enemy Pone(Res_yuan[19], 300, -150, 6);
		Pone.origin_HP = Pone.HP = (LL)8e5 + abs(ATK_muti * 20);
		Pone.velocity = Pointf{ 0,0.2 };
		Pone.is_boss = 3;
		enemyL.push_front(Pone);
	}
	else if (x == 4) {
		Enemy Pone(Res_yuan[28], 400, -150, 6);
		Pone.origin_HP = Pone.HP = (LL)2e6 + abs(ATK_muti * 20);
		Pone.velocity = Pointf{ -0.02,0.2 };
		Pone.is_boss = 4;
		enemyL.push_front(Pone);
	}
}

#endif

//����
#if 1
list<Rune> runeL;		// ������������

void runeL_add_one(int x = 300, int y = 0) {		// �������
	Rune Pone(&res_runeBlue1,x,y);
	int r = rand() % 100;
	if (r < 20) Pone.effect_alien_vary = rand() % 5 + 1;	// ����Ч�����
	else if (r < 40) Pone.effect_alien_muti = (rand() % 4 + 5) * 0.2;
	else if (r < 60) {
		if (abs(ATK_muti) <= 200) Pone.effect_ATK_vary = rand() % 18 - 7;
		else Pone.effect_ATK_vary = rand() % 210 - 90;
	}
	else if (r < 80) Pone.effect_ATK_muti = (rand()%6+1) * 0.3;
	else if (r < 100) Pone.effect_enemy_add = rand()%15;
	runeL.push_front(Pone);
}

bool is_remove_rune(Rune a) {		// �����Ƿ����
	if (a.pos_rect.topleft.y > 700) return true;
	return false;
}

void runeL_update(clock_t current_time) {		// ���ĸ���
	runeL.remove_if(is_remove_rune);
	for (auto it = runeL.begin(); it != runeL.end(); it++) {
		(*it).move();
		(*it).update(current_time);
		(*it).draw();
	}
}


#endif

//��ѡһ����
#if 1
list<TBlock> tblockL;		// ѡ�񷽿�����

void tblockL_add(bool left = true,bool right = false,bool is_solo = false) {	// ѡ�񷽿���ӣ�Ĭ��������
	TBlock onea(0,100,RGB(rand()%255,rand()%255,rand()%255));
	TBlock oneb(1, 100, RGB(rand() % 255, rand() % 255, rand() % 255));
	int r = rand() % 100;

#if 1
	if (r < 20) onea.effect_alien_vary = rand() % 5 + 1;		// ѡ�񷽿�Ч�����
	else if (r < 40) onea.effect_alien_muti = (rand() % 4 + 5) * 0.2;
	else if (r < 60) {
		if (abs(ATK_muti) <= 300) onea.effect_ATK_vary = rand() % 18 - 7;
		else onea.effect_ATK_vary = rand() % 210 - 90;
	}
	else if (r < 80) onea.effect_ATK_muti = (rand() % 6 + 1) * 0.3;
	else if (r < 100) onea.effect_enemy_add = rand() % 15;

	r = rand() % 100;
	if (r < 20) oneb.effect_alien_vary = rand() % 5 + 1;
	else if (r < 40) oneb.effect_alien_muti = (rand() % 4 + 5) * 0.2;
	else if (r < 60) {
		if (abs(ATK_muti) <= 300) oneb.effect_ATK_vary = rand() % 18 - 7;
		else oneb.effect_ATK_vary = rand() % 210 - 90;
	}
	else if (r < 80) oneb.effect_ATK_muti = (rand() % 6 + 1) * 0.3;
	else if (r < 100) oneb.effect_enemy_add = rand() % 15;
#endif
	onea.is_HP = left;		// ����ѡ�񷽿��Ƿ�Ϊ��Ѫ���趨
	oneb.is_HP = right;
	if (clock() > 3 * 1000) onea.origin_HP = onea.HP = abs(100 * log10(clock() / 100) + ATK_muti * 80) * max(1,(playerAlienL.size() / 3));
	if (clock() > 3 * 1000) oneb.origin_HP = onea.HP = abs(100 * log10(clock() / 100) + ATK_muti * 80) * max(1, (playerAlienL.size() / 3));

	if (is_solo) {		// ѡ�񷽿��Ƿ�ֻ���һ��
		if (rand() % 2 == 0)
			tblockL.push_front(onea);
		else
			tblockL.push_front(oneb);
	}
	else {
		tblockL.push_front(onea);
		tblockL.push_front(oneb);
	}
}

bool is_tblockL_remove(TBlock& one) {		// ѡ�񷽿��Ƴ�
	if (one.rect.topleft.y > 700) return true;
	if (one.is_HP && (one.HP <= 0 || one.HP >= one.origin_HP * 2)) { // ѡ�񷽿鱻��ҽӴ�������ʱ������Ч��
		if (one.effect_alien_vary != 0) {
			for (int i = 0; i < one.effect_alien_vary; i += 1)
				playerAlienL_add_one();
		}
		else if (one.effect_alien_muti != 1) {
			playerAlienL_mutiply(one.effect_alien_muti);
		}
		else if (one.effect_ATK_vary != 0) {
			ATK_muti += one.effect_ATK_vary;
		}
		else if (one.effect_ATK_muti != 1) {
			ATK_muti = (int)round(ATK_muti * one.effect_ATK_muti);
		}
		else if (one.effect_enemy_add != 0) {
			for (int i = 0; i < one.effect_enemy_add; i += 1)
				enemyL_add_one();
		}
		return true;
	}
	return false;
}

void tblockL_update() {			// ѡ�񷽿����
	tblockL.remove_if(is_tblockL_remove);
	for (auto it = tblockL.begin(); it != tblockL.end(); it++) {
		it->move();
		it->draw();
	}
}
#endif

//��ײ����
#if 1

bool is_collide_rect(const Recta &r1, const Recta &r2) {		// �ж����������ڿռ����Ƿ����غϣ����ھ�����֮�����ײ���
	if ((r1.topleft.y < r2.topleft.y + r2.height && r1.topleft.y >= r2.topleft.y) ||
		(r2.topleft.y < r1.topleft.y + r1.height && r1.topleft.y <= r2.topleft.y)) {
		if ((r1.topleft.x < r2.topleft.x + r2.width && r1.topleft.x >= r2.topleft.x) ||
			(r2.topleft.x < r1.topleft.x + r1.width && r1.topleft.x <= r2.topleft.x)) {
			return true;
		}
	}
	return false;
}
bool is_collide_rect(const Recta& r1, const Recta& r2,float ratio1,float ratio2) {		// ����һ�������Ļ���������˾��μ��ٷְٵ��趨��ʹ��ײ�������
	Recta r3 = { (int)(r1.topleft.x + (1 - ratio1) * r1.width / 2) ,(int)(r1.topleft.y + (1 - ratio1) * r1.height / 2),
					(int)(ratio1 * r1.width),(int)(ratio1 * r1.height) };
	Recta r4 = { (int)(r2.topleft.x + (1 - ratio2) * r2.width / 2) ,(int)(r2.topleft.y + (1 - ratio2) * r2.height / 2),
					(int)(ratio2 * r2.width),(int)(ratio2 * r2.height) };
	if ((r3.topleft.y < r4.topleft.y + r4.height && r3.topleft.y >= r4.topleft.y) ||
		(r4.topleft.y < r3.topleft.y + r3.height && r3.topleft.y <= r4.topleft.y)) {
		if ((r3.topleft.x < r4.topleft.x + r4.width && r3.topleft.x >= r4.topleft.x) ||
			(r4.topleft.x < r3.topleft.x + r3.width && r3.topleft.x <= r4.topleft.x)) {
			return true;
		}
	}
	return false;
}


//���ʵ����ײ
void player_collide_check(PAlien &A,PAlien &B) {		// ��������֮�����ײ���
	float ratio = 1.0;
	if (playerAlienL.size() >= 3 && playerAlienL.size() <= 6) ratio = 0.9;
	else if (playerAlienL.size() <= 10) ratio = 0.8;
	else if (playerAlienL.size() <= 20) ratio = 0.7;
	else if (playerAlienL.size() <= 50) ratio = 0.6;
	else if (playerAlienL.size() <= 100) ratio = 0.5;		// �������С�˵��������٣����ò�ͬ����ײ���������
	else ratio = 0.01;
	if (is_collide_rect(A.alien.rect, B.alien.rect,ratio,ratio)) {	// ������ײ
		if (A.alien.positionf.x < B.alien.positionf.x) 
			A.alien.positionf.x -= rand()%3, B.alien.positionf.x += rand()%3;		// ���������һ���֮����������
		else {
			A.alien.positionf.x += rand()%3, B.alien.positionf.x -= rand()%3; }
		if (A.alien.positionf.y < B.alien.positionf.y) 
			A.alien.positionf.y -= rand()%2, B.alien.positionf.y += rand() % 2;
		else A.alien.positionf.y += rand() % 2, B.alien.positionf.y -= rand() % 2;
	}
}

void player_enemy_collide_check(PAlien& P,Enemy &E) {		// ��������֮�����ײ���
	Recta e = Recta{ E.rect.topleft.x - E.rect.width / 2,E.rect.topleft.y - E.rect.height / 2,
						E.rect.width,E.rect.height };
	if (is_collide_rect(P.alien.rect, e,0.5,0.5)) {	
		int minus = min(P.alien.HP, E.HP);		// ����ײ��ʹ���С�����������٣����������������
		P.alien.HP -= minus;
		E.HP -= minus;
	}
}

void bullet_enemy_collide_check(Bullet& B, Enemy& E) {		// �������ӵ�֮�����ײ���
	Recta e = Recta{E.rect.topleft.x - E.rect.width / 2,E.rect.topleft.y - E.rect.height / 2,
						E.rect.width,E.rect.height};
	if (is_collide_rect(B.rect, e, 0.8,0.8)) {
		E.HP -= B.ATK * ATK_muti;	// ����ײ��ʹ���˿�Ѫ���ӵ�ATK��0������ӵ�
		B.ATK = 0;
	}
}

void rune_player_collide_check(Rune& R, PAlien P) {		// ���������֮�����ײ���
	if (is_collide_rect(R.pos_rect, P.alien.rect, 1.5,1.5)) {
		if (R.effect_alien_vary != 0) {			// ����ײ�������Ӧ���ĵ�Ч��
			for (int i = 0; i < R.effect_alien_vary; i += 1)
				playerAlienL_add_one();
		}
		else if (R.effect_alien_muti != 1) {
			playerAlienL_mutiply(R.effect_alien_muti);
		}
		else if (R.effect_ATK_vary != 0) {
			ATK_muti += R.effect_ATK_vary;
		}
		else if (R.effect_ATK_muti != 1) {
			ATK_muti = (int)round(ATK_muti * R.effect_ATK_muti);
		}
		else if (R.effect_enemy_add != 0) {
			for (int i = 0; i < R.effect_enemy_add; i += 1)
				enemyL_add_one();
		}
		R.positionf.y = (float)1000;
	}
}

void tblock_player_collide_check(TBlock& T, PAlien& P) {	// ѡ�񷽿������֮�����ײ���
	if (is_collide_rect(T.rect, P.alien.rect, 1.0, 0.8)) {
		if (T.is_HP == false) {
			if (T.effect_alien_vary != 0) {		// ����ײ��ѡ�񷽿���Ѫ�����ã�����Ч��
				for (int i = 0; i < T.effect_alien_vary; i += 1)
					playerAlienL_add_one();
			}
			else if (T.effect_alien_muti != 1) {
				playerAlienL_mutiply(T.effect_alien_muti);
			}
			else if (T.effect_ATK_vary != 0) {
				ATK_muti += T.effect_ATK_vary;
			}
			else if (T.effect_ATK_muti != 1) {
				ATK_muti = (int)round(ATK_muti * T.effect_ATK_muti);
			}
			else if (T.effect_enemy_add != 0) {
				for (int i = 0; i < T.effect_enemy_add; i += 1)
					enemyL_add_one();
			}
			T.rect.topleft.y = 7000;
		}
		else {
			int minus = min(T.HP, P.alien.HP);		// ��ײ��ѡ�񷽿���Ѫ�����ã��۳����С��Ѫ��
			T.HP -= minus;
			P.alien.HP -= minus;
		}
	}
}

void bullet_tblock_collide_check(Bullet& B, TBlock& T) {		// �ӵ���ѡ�񷽿�֮�����ײ���
	if (is_collide_rect(B.rect, T.rect)) {
		T.HP -= B.ATK * ATK_muti;
		B.ATK = 0;
	}
}

void collide_check() {		// ���������ܵ���ײ���
	int t = 0;
	for (auto i = playerAlienL.begin(); i != playerAlienL.end(); i ++,t ++) {
		auto j = i; j++; int p = t + 1;
		for (; j != playerAlienL.end(); j ++,p++) {
			player_collide_check(*i, *j);		// ��������֮�����ײ���
		}
		for (auto it = enemyL.begin(); it != enemyL.end(); it++) {
			player_enemy_collide_check(*i, *it);	// ��������֮�����ײ���
		}
		for (auto it = runeL.begin(); it != runeL.end(); it++) {
			rune_player_collide_check(*it, *i);		// ���������֮�����ײ���
		}
		for (auto it = tblockL.begin(); it != tblockL.end(); it++) {
			tblock_player_collide_check(*it, *i);		// �����ѡ�񷽿�֮�����ײ���
		}
	}
	for (auto bu = bulletL.begin(); bu != bulletL.end(); bu++) {
		for (auto en = enemyL.begin(); en != enemyL.end(); en++) {
			bullet_enemy_collide_check(*bu,*en);		// �������ӵ�֮�����ײ���
		}
		for (auto it = tblockL.begin(); it != tblockL.end(); it++) {
			if (it->is_HP == true) bullet_tblock_collide_check(*bu, *it);	// �ӵ���ѡ�񷽿�֮�����ײ���
		}
	}
}
#endif

//����
#if 1
Utuber vtub;		// �����������󣬹����������飨������

struct Reaction {		// ����������������ʱ��ʾ
	int frame;			// ������������
	clock_t ddl;		// �������������ʱ��
};
queue<Reaction> reacQ;		// �����������������Ķ���

void vtub_addr(int _frame,clock_t _period = 3000) {		// �����������
	Reaction r = Reaction{ _frame,_period };
	if (!reacQ.empty()) r.ddl = reacQ.back().ddl + _period;		// ʹҪ��ӵ�������������һ��������ɺ󲥷�
	else r.ddl = clock() + _period;		// �������������ʱ��
	reacQ.push(r);
}

void vtub_reac_clear() {		// ���������������
	int p = reacQ.size();
	while (p--) reacQ.pop();
}

void vtub_update(clock_t current_time) {		// ������������
	if (!reacQ.empty()) {		// ��������������зǿգ����Ŷ��п�ͷ�Ķ���
		if (reacQ.front().ddl <= current_time) reacQ.pop();		// �����ѹ��ڣ����������
		if (!reacQ.empty())
			vtub.setframe(reacQ.front().frame);		// ���µ�ǰ����������
	}
	res_bg_stream.draw(652, 373);		// ��������ֱ������
	vtub.draw();		// ������������
	char s[30];
	sprintf_s(s, "ֱ���ۿ�����: %d", views);		// չʾֱ���䵱ǰ�ۿ�����
	outtextxy(1000 - textwidth(s) - 20, 300, s);
}
#endif

//����
#if 1
struct Musicv {			// �������ֽṹ�壬����Ҫ���ŵ�����/��Ч
	char path[100];		// ����·��
	clock_t ddl = 0;	// ���ֲ���ʱ��
	int length = 0;		// ���ֳ���
	bool is_played = false;		// �����Ƿ��Ѿ������Ź�

	Musicv(char* s) {		// ����·����ʼ��
		strcpy_s(path, s);
		ddl = clock();
		length = music_length(s);
		printf("%d\n", length);
	}
	Musicv(char* s, clock_t _ddl) {		
		strcpy_s(path, s);
		ddl = _ddl;
		length = music_length(s);
	}
	Musicv() {}
};
queue<Musicv> musicQ;		// ���ֲ��Ŷ���

void music_add(char* s, clock_t ddl = 0) {		// �����ֶ���ĩβ���һ������
	if (ddl == 0) ddl = clock();
	Musicv one(s, ddl);
	musicQ.push(one);
}

void music_update(clock_t current_time) {		// �������ֶ����е�����
	if (!musicQ.empty()) {
		if (current_time >= musicQ.front().ddl && musicQ.front().is_played == false) {  // ���ֲ���ʱ�䵽����δ�����Ź����򲥷����ֶ��п�ͷ����
			musicQ.front().is_played = true;
			music_play(musicQ.front().path,50,1);
		}
		if (current_time >= musicQ.front().ddl + musicQ.front().length) {	// ���ֶ��п�ͷ���ֲ�����ϣ��رղ��Ƴ�������
			music_close(musicQ.front().path);
			musicQ.pop();
		}
	}
}


Musicv back_music;		// ���ñ�������

void back_music_update(char* s,clock_t current_time = 0) {		// ���±�������
	music_close(back_music.path);
	if (current_time == 0) current_time = clock();
	back_music = Musicv(s,current_time);
}

void back_music_check(clock_t current_time) {		// �������ּ���Ƿ񲥷����
	if (current_time >= back_music.ddl + back_music.length && back_music.is_played == true) {	// �������ֲ������
		if (game_out == 0) {		// ���û�н����֣�����л���������
			int r = rand() % 100;
			if (r <= 50)
				back_music_update(wav_ctj_class[rand()%7 + 32], current_time);
			else 
				back_music_update(mp3_chun_class[rand() % 21], current_time);
		}
		else back_music.is_played = false, back_music.ddl = current_time;	// ����������Ÿñ�������
	}
	if (current_time >= back_music.ddl && back_music.is_played == false) {		// ������û�����Ź�
		back_music.is_played = true;		// ���ű�������
		music_play(back_music.path,50,1);
	}
}
#endif

#endif