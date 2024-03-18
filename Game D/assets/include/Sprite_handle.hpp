#ifndef SPRITE_HANDLE
#define SPRITE_HANDLE
#include "MySprites.hpp"
#include <list>


// 该文件主要用于精灵类的处理及相关功能
// 如设置道路移动，玩家与玩家间碰撞箱体积检测等


// 定义道路方块结构
#if 1
struct Ares {		// 每个道路方块结构的大小为32 * 32
	MySprite* msptr = NULL;			// 道路方块结构所对应的源精灵类
	int x, y, frame = 0;			// 道路方块结构在屏幕上的坐标与位图帧的值
	Ares(MySprite* nmsptr = NULL, int nx = 0, int ny = 0, int nframe = 0) {		// 道路方块结构初始化
		msptr = nmsptr, x = nx, y = ny, frame = nframe;
	}
};
Ares road_map[15][20];		// 定义道路，为二维数组，由若干道路方块结构组成，道路长为14 * 32，宽为19 * 32


void res_road_add() {		// 初始化道路二维数组，为每个元素设置对应的道路方块
	for (int i = 0; i <= 13; i += 1) {
		for (int j = 0; j <= 18; j += 1) {
			int frame1 = rand() % 360;
			int frame2 = rand() % 360;
			road_map[i][j] = Ares{ &res_city1,0,0,frame1};
		}
	}
}


clock_t road_last_time = 0;	// 道路更新的上一次时间

void res_road_update(clock_t current_time,int ticks = 250) {	// 道路更新，ticks表示道路更新的时间间隔
	if (current_time > road_last_time + ticks) {
		road_last_time = current_time;
		for (int i = 0; i < 13; i += 1) {
			for (int j = 18; j >= 1; j -= 1) {
				road_map[i][j] = road_map[i][j - 1];		// 使道路由上到下流动
			}
			road_map[i][0] = Ares{ &res_city1,0,0,rand() % 360 };	// 道路最上端随机生成新的道路方块
		}
	}

	for (int i = 0; i < 13; i += 1) {
		for (int j = 0; j <= 18; j += 1) {
			(*road_map[i][j].msptr).drawf(100 + i * 32, j * 32, road_map[i][j].frame); // 绘制道路方块
		}
	}
}
#endif

//玩家
#if 1
LL player_score = 0;	// 玩家得分（通过消灭怪物来得分）

struct PAlien { PlayerAlien alien; };	// 定义玩家小人（alien即玩家操作的外星小人）
list<PAlien> playerAlienL;		// 玩家小人的链表
int playerAlienL_len[2] = { 0 };	// 玩家外星小人level0与level1的数量（玩家小人足够多时会合成大外星小人（level1））
list<Bullet> bulletL;				// 玩家小人发出的子弹链表

void playerAlienL_add_one(int x = 300,int y = 600,int level = 0) {		// 添加一个玩家小人C
	PlayerAlien Pone(rand()%5 * 2,level);		// 生成一个随机样式（颜色）的玩家小人，并设置级别默认为0（最小）
	if (x == 300 && y == 600 && playerAlienL.size()) {	// 未指定xy坐标并玩家小人个数非0时
		auto paptr = playerAlienL.end();
		paptr--;
		x = paptr->alien.rect.topleft.x;		// 让新的玩家小人生成在玩家小人链表最后的玩家小人附近
		y = paptr->alien.rect.topleft.y;
	}
	Pone.positionf = Pointf{ (float)x,(float)y };
	if (level == 0 && playerAlienL_len[0] < 60) playerAlienL.push_front(PAlien{ Pone});	// 防止过于卡顿，限制玩家小人数量
	else if (level == 1 && playerAlienL_len[1] < 30) playerAlienL.push_back(PAlien{ Pone });
	playerAlienL_len[level] += 1;		// 让对应的level的玩家小人数量+1
}

void playerAlineL_merge() {				// 合并玩家小人    玩家小人足够多时会合成大外星小人（level1）
	if (playerAlienL.size() >= 50 && playerAlienL_len[1] < 30) {
		while (playerAlienL_len[0] >= 30) {
			playerAlienL_len[0] -= 4;
			for (int i = 0; i < 4; i += 1) 
				if (!playerAlienL.empty())
					playerAlienL.pop_front();
			playerAlienL_add_one(300, 450, 1);  // 生成的的玩家小人（level1） 
		}
	}
}

void playerAlienL_mutiply(float muti) {// 使玩家小人数量乘以倍数，若无小人则添加一个小人 
	int n = (int)(playerAlienL_len[0] * (muti - 1));		// 乘以倍数后应该添加到的玩家小人数量
	for (int i = 0; i < n; i += 1) {
		playerAlienL_add_one();
	}
	if (playerAlienL_len[0] == 0) playerAlienL_add_one();	// 若无小人则添加一个小人 
}


void player_shoot(int x,int y,int width,int height,int ATK) {  // 使玩家小人发射子弹
	Bullet one = Bullet{ x,y,width,height,ATK };		// 创建一个子弹
	bulletL.push_front(one);		// 将子弹添加到子弹链表中
}

clock_t last_shoot_time = 0;		// 上次子弹发射时间
clock_t shoot_dps = 300;			// 设置子弹发射的时间间隔

bool is_remove_alien(PAlien a) {		// 判断玩家小人是否该清除（移除链表），只在下面的玩家小人更新函数中使用
	if (a.alien.HP <= 0) {		// HP <= 0 代表被消灭
		playerAlienL_len[a.alien.level] -= 1;
		return true;
	}
	return false;
}

void player_alien_update(clock_t current_time) {		// 玩家小人更新函数
	playerAlienL.remove_if(is_remove_alien);		// 判断玩家小人是否该清除（移除链表）
	for (auto it = playerAlienL.begin(); it != playerAlienL.end(); it++) {		// 遍历玩家小人链表
		(*it).alien.update(current_time);		// 玩家小人更新（更新动画）
		(*it).alien.draw();			// 玩家小人绘制
		if (current_time > last_shoot_time + shoot_dps) {	// 玩家小人发射子弹
			player_shoot((*it).alien.rect.topleft.x, (*it).alien.rect.topleft.y - 20, 3, 8, (*it).alien.HP / 10);
		} // 发射子弹
	}
	if (current_time > last_shoot_time + shoot_dps) {
		last_shoot_time = current_time;		// 更新玩家小人上次发射子弹的时间
	}
	char s[30];
	sprintf_s(s,"Alien Numbers:%d", playerAlienL.size());	// 展示玩家小人当前的数量
	outtextxy(20, 300, s);
	sprintf_s(s, "ATK:%d", ATK_muti);			// 展示玩家小人的攻击力
	outtextxy(20, 340, s);
	sprintf_s(s, "SCORE: %d", player_score);	// 展示玩家得分
	outtextxy(20, 360, s);
}


void player_alien_move() {	// 玩家小人移动
	playerAlineL_merge();		// 玩家小人合并（如果满足条件的话）
	for (auto it = playerAlienL.begin(); it != playerAlienL.end(); it ++) {
		(*it).alien.move();
	}
}

void check_player_move(int key_alpha) {		// 根据键盘的输入情况来判断玩家小人是否移动，以及移动方向
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
		(*it).alien.setdirection(direction);		// 更新玩家小人移动方向（-1表示静止）
	}
}


bool is_bullet_remove(Bullet one) {		// 判断子弹是否应当被清除
	if (one.rect.topleft.y < -20 || one.ATK <= 0) return true;		// 子弹超出边界或已经射击到目标（ATK会置为0），移除
	return false;
}

void bullet_update() {		// 子弹更新
	bulletL.remove_if(is_bullet_remove);
	for (auto it = bulletL.begin(); it != bulletL.end(); it++) {
		(*it).update();
	}
}
#endif

//敌人
#if 1
int enemy_num = 0;		// 敌人数量
list<Enemy> enemyL;		// 定义敌人链表

void enemyL_add_one(int x = 0, int y = 0,int direction = 6) {	// 添加敌人
	if (x == 0) x = rand() % 400 + 100;		// 设置敌人x坐标
	if (direction == 6) {		// 由上到下移动的只有一种敌人
		Enemy Pone(Res_animal[rand() % 10], x, y);		// 动物头敌人
		if (clock() > 3 * 1000) Pone.origin_HP = Pone.HP = 3 * (clock() / 1000) + 100 * log10(clock() / 300) + ATK_muti * 5;
		enemyL.push_front(Pone);		// 敌人血量设置根据实际需求而定
	}
	else if (direction == 0) {
		int r = rand() % 100;
		if (r <= 10) {
			Enemy Pone(Res_planet[rand()%10], x, y, direction);		// 陨星敌人
			Pone.origin_HP = Pone.HP = 100 + abs(ATK_muti * 2);
			enemyL.push_front(Pone);
		}
		else if (r <= 60) {
			int p = rand() % 41;
			while (p == 7 || p == 17 || p == 19 || p == 28) p = rand() % 41;
			Enemy Pone(Res_yuan[p], x, y, direction);		// 一堆图片
			Pone.origin_HP = Pone.HP = 100 + abs(ATK_muti * 2);
			enemyL.push_front(Pone);
		}
		else {
			Enemy Pone(Res_tanks_bullet[rand()%4], x, y, direction);		// 坦克与坦克子弹的敌人
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

bool is_remove_enemy(Enemy a) {		// 敌人是否应当被清除
	if (a.HP <= 0) {		// 敌人血量 <= 0时代表被消灭，对敌人是否为boss还是普通敌人加以区分，所得奖励不同
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
		// 敌人超出边界，直接清除
	return false;	
}

void enemy_update(clock_t current_time) {	// 敌人更新
	enemyL.remove_if(is_remove_enemy);		// 清除应当清除的敌人
	for (auto it = enemyL.begin(); it != enemyL.end(); it++) {
		(*it).update(current_time);		// 更新敌人图像（动画）
		(*it).draw();				// 敌人绘制
		(*it).display_HP();			// 敌人展示血量
	}
	char s[30];
	sprintf_s(s, "Enemy Numbers:%u", enemy_num);		// 展示敌人已经出现的数量
	outtextxy(20, 320, s);
}

void enemy_move() {		// 敌人移动
	for (auto it = enemyL.begin(); it != enemyL.end(); it++) {
		(*it).move();
	}
}

void boss_add(int x) {			// 添加boss，但boss比较简陋
	if (x == 1) {
		Enemy Pone(Res_yuan[7], 250, -150 , 6);
		Pone.origin_HP = Pone.HP = (LL)4e4 + abs(ATK_muti * 20);
		Pone.velocity = Pointf{ 0.05,0.2 };		// boss速度单独处理
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

//铭文
#if 1
list<Rune> runeL;		// 设置铭文链表

void runeL_add_one(int x = 300, int y = 0) {		// 铭文添加
	Rune Pone(&res_runeBlue1,x,y);
	int r = rand() % 100;
	if (r < 20) Pone.effect_alien_vary = rand() % 5 + 1;	// 铭文效果随机
	else if (r < 40) Pone.effect_alien_muti = (rand() % 4 + 5) * 0.2;
	else if (r < 60) {
		if (abs(ATK_muti) <= 200) Pone.effect_ATK_vary = rand() % 18 - 7;
		else Pone.effect_ATK_vary = rand() % 210 - 90;
	}
	else if (r < 80) Pone.effect_ATK_muti = (rand()%6+1) * 0.3;
	else if (r < 100) Pone.effect_enemy_add = rand()%15;
	runeL.push_front(Pone);
}

bool is_remove_rune(Rune a) {		// 铭文是否清除
	if (a.pos_rect.topleft.y > 700) return true;
	return false;
}

void runeL_update(clock_t current_time) {		// 铭文更新
	runeL.remove_if(is_remove_rune);
	for (auto it = runeL.begin(); it != runeL.end(); it++) {
		(*it).move();
		(*it).update(current_time);
		(*it).draw();
	}
}


#endif

//二选一方块
#if 1
list<TBlock> tblockL;		// 选择方块链表

void tblockL_add(bool left = true,bool right = false,bool is_solo = false) {	// 选择方块添加（默认两个）
	TBlock onea(0,100,RGB(rand()%255,rand()%255,rand()%255));
	TBlock oneb(1, 100, RGB(rand() % 255, rand() % 255, rand() % 255));
	int r = rand() % 100;

#if 1
	if (r < 20) onea.effect_alien_vary = rand() % 5 + 1;		// 选择方块效果随机
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
	onea.is_HP = left;		// 设置选择方块是否为有血量设定
	oneb.is_HP = right;
	if (clock() > 3 * 1000) onea.origin_HP = onea.HP = abs(100 * log10(clock() / 100) + ATK_muti * 80) * max(1,(playerAlienL.size() / 3));
	if (clock() > 3 * 1000) oneb.origin_HP = onea.HP = abs(100 * log10(clock() / 100) + ATK_muti * 80) * max(1, (playerAlienL.size() / 3));

	if (is_solo) {		// 选择方块是否只添加一个
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

bool is_tblockL_remove(TBlock& one) {		// 选择方块移除
	if (one.rect.topleft.y > 700) return true;
	if (one.is_HP && (one.HP <= 0 || one.HP >= one.origin_HP * 2)) { // 选择方块被玩家接触或消灭时，给与效果
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

void tblockL_update() {			// 选择方块更新
	tblockL.remove_if(is_tblockL_remove);
	for (auto it = tblockL.begin(); it != tblockL.end(); it++) {
		it->move();
		it->draw();
	}
}
#endif

//碰撞箱检测
#if 1

bool is_collide_rect(const Recta &r1, const Recta &r2) {		// 判断两个矩形在空间上是否有重合，用于精灵类之间的碰撞检测
	if ((r1.topleft.y < r2.topleft.y + r2.height && r1.topleft.y >= r2.topleft.y) ||
		(r2.topleft.y < r1.topleft.y + r1.height && r1.topleft.y <= r2.topleft.y)) {
		if ((r1.topleft.x < r2.topleft.x + r2.width && r1.topleft.x >= r2.topleft.x) ||
			(r2.topleft.x < r1.topleft.x + r1.width && r1.topleft.x <= r2.topleft.x)) {
			return true;
		}
	}
	return false;
}
bool is_collide_rect(const Recta& r1, const Recta& r2,float ratio1,float ratio2) {		// 在上一个函数的基础上添加了矩形检测百分百的设定，使碰撞检测更灵活
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


//玩家实体碰撞
void player_collide_check(PAlien &A,PAlien &B) {		// 玩家与玩家之间的碰撞检测
	float ratio = 1.0;
	if (playerAlienL.size() >= 3 && playerAlienL.size() <= 6) ratio = 0.9;
	else if (playerAlienL.size() <= 10) ratio = 0.8;
	else if (playerAlienL.size() <= 20) ratio = 0.7;
	else if (playerAlienL.size() <= 50) ratio = 0.6;
	else if (playerAlienL.size() <= 100) ratio = 0.5;		// 根据玩家小人的数量多少，设置不同的碰撞检测灵敏度
	else ratio = 0.01;
	if (is_collide_rect(A.alien.rect, B.alien.rect,ratio,ratio)) {	// 若相碰撞
		if (A.alien.positionf.x < B.alien.positionf.x) 
			A.alien.positionf.x -= rand()%3, B.alien.positionf.x += rand()%3;		// 令玩家与另一玩家之间拉开距离
		else {
			A.alien.positionf.x += rand()%3, B.alien.positionf.x -= rand()%3; }
		if (A.alien.positionf.y < B.alien.positionf.y) 
			A.alien.positionf.y -= rand()%2, B.alien.positionf.y += rand() % 2;
		else A.alien.positionf.y += rand() % 2, B.alien.positionf.y -= rand() % 2;
	}
}

void player_enemy_collide_check(PAlien& P,Enemy &E) {		// 玩家与敌人之间的碰撞检测
	Recta e = Recta{ E.rect.topleft.x - E.rect.width / 2,E.rect.topleft.y - E.rect.height / 2,
						E.rect.width,E.rect.height };
	if (is_collide_rect(P.alien.rect, e,0.5,0.5)) {	
		int minus = min(P.alien.HP, E.HP);		// 若碰撞，使玩家小人生命力减少，与敌人生命力抵消
		P.alien.HP -= minus;
		E.HP -= minus;
	}
}

void bullet_enemy_collide_check(Bullet& B, Enemy& E) {		// 敌人与子弹之间的碰撞检测
	Recta e = Recta{E.rect.topleft.x - E.rect.width / 2,E.rect.topleft.y - E.rect.height / 2,
						E.rect.width,E.rect.height};
	if (is_collide_rect(B.rect, e, 0.8,0.8)) {
		E.HP -= B.ATK * ATK_muti;	// 若碰撞，使敌人扣血，子弹ATK置0以清除子弹
		B.ATK = 0;
	}
}

void rune_player_collide_check(Rune& R, PAlien P) {		// 玩家与铭文之间的碰撞检测
	if (is_collide_rect(R.pos_rect, P.alien.rect, 1.5,1.5)) {
		if (R.effect_alien_vary != 0) {			// 若碰撞，给与对应铭文的效果
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

void tblock_player_collide_check(TBlock& T, PAlien& P) {	// 选择方块与玩家之间的碰撞检测
	if (is_collide_rect(T.rect, P.alien.rect, 1.0, 0.8)) {
		if (T.is_HP == false) {
			if (T.effect_alien_vary != 0) {		// 若碰撞且选择方块无血量设置，给与效果
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
			int minus = min(T.HP, P.alien.HP);		// 碰撞但选择方块有血量设置，扣除玩家小人血量
			T.HP -= minus;
			P.alien.HP -= minus;
		}
	}
}

void bullet_tblock_collide_check(Bullet& B, TBlock& T) {		// 子弹与选择方块之间的碰撞检测
	if (is_collide_rect(B.rect, T.rect)) {
		T.HP -= B.ATK * ATK_muti;
		B.ATK = 0;
	}
}

void collide_check() {		// 各精灵类总的碰撞检测
	int t = 0;
	for (auto i = playerAlienL.begin(); i != playerAlienL.end(); i ++,t ++) {
		auto j = i; j++; int p = t + 1;
		for (; j != playerAlienL.end(); j ++,p++) {
			player_collide_check(*i, *j);		// 玩家与玩家之间的碰撞检测
		}
		for (auto it = enemyL.begin(); it != enemyL.end(); it++) {
			player_enemy_collide_check(*i, *it);	// 玩家与敌人之间的碰撞检测
		}
		for (auto it = runeL.begin(); it != runeL.end(); it++) {
			rune_player_collide_check(*it, *i);		// 玩家与铭文之间的碰撞检测
		}
		for (auto it = tblockL.begin(); it != tblockL.end(); it++) {
			tblock_player_collide_check(*it, *i);		// 玩家与选择方块之间的碰撞检测
		}
	}
	for (auto bu = bulletL.begin(); bu != bulletL.end(); bu++) {
		for (auto en = enemyL.begin(); en != enemyL.end(); en++) {
			bullet_enemy_collide_check(*bu,*en);		// 敌人与子弹之间的碰撞检测
		}
		for (auto it = tblockL.begin(); it != tblockL.end(); it++) {
			if (it->is_HP == true) bullet_tblock_collide_check(*bu, *it);	// 子弹与选择方块之间的碰撞检测
		}
	}
}
#endif

//主播
#if 1
Utuber vtub;		// 定义主播对象，管理主播表情（或动作）

struct Reaction {		// 定义主播动作的延时表示
	int frame;			// 主播动作类型
	clock_t ddl;		// 主播动作的完成时间
};
queue<Reaction> reacQ;		// 欲发生的主播动作的队列

void vtub_addr(int _frame,clock_t _period = 3000) {		// 添加主播动作
	Reaction r = Reaction{ _frame,_period };
	if (!reacQ.empty()) r.ddl = reacQ.back().ddl + _period;		// 使要添加的主播动作在上一个动作完成后播放
	else r.ddl = clock() + _period;		// 主播动作的完成时间
	reacQ.push(r);
}

void vtub_reac_clear() {		// 清除主播动作队列
	int p = reacQ.size();
	while (p--) reacQ.pop();
}

void vtub_update(clock_t current_time) {		// 主播动作更新
	if (!reacQ.empty()) {		// 如果主播动作队列非空，播放队列开头的动作
		if (reacQ.front().ddl <= current_time) reacQ.pop();		// 动作已过期，清除出队列
		if (!reacQ.empty())
			vtub.setframe(reacQ.front().frame);		// 更新当前的主播动作
	}
	res_bg_stream.draw(652, 373);		// 绘制主播直播背景
	vtub.draw();		// 绘制主播动作
	char s[30];
	sprintf_s(s, "直播观看人数: %d", views);		// 展示直播间当前观看人数
	outtextxy(1000 - textwidth(s) - 20, 300, s);
}
#endif

//音乐
#if 1
struct Musicv {			// 定义音乐结构体，管理要播放的音乐/音效
	char path[100];		// 音乐路径
	clock_t ddl = 0;	// 音乐播放时间
	int length = 0;		// 音乐长度
	bool is_played = false;		// 音乐是否已经被播放过

	Musicv(char* s) {		// 音乐路径初始化
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
queue<Musicv> musicQ;		// 音乐播放队列

void music_add(char* s, clock_t ddl = 0) {		// 在音乐队列末尾添加一首音乐
	if (ddl == 0) ddl = clock();
	Musicv one(s, ddl);
	musicQ.push(one);
}

void music_update(clock_t current_time) {		// 播放音乐队列中的音乐
	if (!musicQ.empty()) {
		if (current_time >= musicQ.front().ddl && musicQ.front().is_played == false) {  // 音乐播放时间到达且未被播放过，则播放音乐队列开头音乐
			musicQ.front().is_played = true;
			music_play(musicQ.front().path,50,1);
		}
		if (current_time >= musicQ.front().ddl + musicQ.front().length) {	// 音乐队列开头音乐播放完毕，关闭并移除该音乐
			music_close(musicQ.front().path);
			musicQ.pop();
		}
	}
}


Musicv back_music;		// 设置背景音乐

void back_music_update(char* s,clock_t current_time = 0) {		// 更新背景音乐
	music_close(back_music.path);
	if (current_time == 0) current_time = clock();
	back_music = Musicv(s,current_time);
}

void back_music_check(clock_t current_time) {		// 背景音乐检测是否播放完毕
	if (current_time >= back_music.ddl + back_music.length && back_music.is_played == true) {	// 背景音乐播放完毕
		if (game_out == 0) {		// 如果没有进入结局，随机切换背景音乐
			int r = rand() % 100;
			if (r <= 50)
				back_music_update(wav_ctj_class[rand()%7 + 32], current_time);
			else 
				back_music_update(mp3_chun_class[rand() % 21], current_time);
		}
		else back_music.is_played = false, back_music.ddl = current_time;	// 否则继续播放该背景音乐
	}
	if (current_time >= back_music.ddl && back_music.is_played == false) {		// 背景音没被播放过
		back_music.is_played = true;		// 播放背景音乐
		music_play(back_music.path,50,1);
	}
}
#endif

#endif