#ifndef MYLIBRARY_HPP
#define MYLIBRARY_HPP

#include "mask_handle.hpp"
#define pi 3.1415926
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <graphics.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <list>

// 该文件负责定义精灵类以及各种衍生类的部分
// 包括精灵类的属性，初始化，绘制函数，运动函数，更新函数等


#if 1
struct Point {
    int x, y;
    Point(int nx = 0, int ny = 0) {
        x = nx, y = ny;
    }
}; // 定义一个点结构体，存储坐标信息，xy坐标为整形

struct Pointf {
    float x, y;
    Pointf(float nx = 0, float ny = 0) {
        x = nx, y = ny;
    }
}; // 定义点，xy坐标为浮点数型


struct Recta {
    Point topleft;
    int width, height;
    Recta(int nx = 0, int ny = 0, int nwidth = 0, int nheight = 0) {
        topleft.x = nx, topleft.y = ny, width = nwidth, height = nheight;
    }
}; // 定义一个矩阵数据结构体，一个矩阵包括它的左上角坐标，长度与宽度

struct Recta2 {
    int left,top, right,bottom;
}; // 定义一个矩阵的另一种表示形式，即左上角坐标+左下角坐标
    // 两种矩阵类型视情况使用


// 下面一个模块主要用于处理角度转动，位图旋转领域的相关操作，此游戏中不需要，故以下可省略
#if 1
// calculates velocity of an angle
Pointf angular_velocity(float angle) {
    Pointf vel(0, 0);
    float rad = (float)(angle * 180 / pi);
    vel.x = cos(rad);
    vel.y = sin(rad);
    return vel;
}

//calculates angle between two points
float target_angle(int x1, int y1, int x2, int y2) {
    int delta_x = x2 - x1;
    int delta_y = y2 - y1;
    float angle_radians = (float)atan2(delta_y, delta_x);
    float angle_degrees = (float)(angle_radians * pi / 180);
    return angle_degrees;
}
float target_angle(Point a,Point b) {
    int delta_x = b.x - a.x;
    int delta_y = b.y - a.y;
    float angle_radians = (float)atan2(delta_y, delta_x);
    float angle_degrees = (float)(angle_radians * pi / 180);
    return angle_degrees;
}

// wraps a degree angle at boundary
float wrap_angle(float angle) {
    while (angle >= 360) angle -= 360;
    while (angle < 0) angle += 360;
    return abs(angle);
}
#endif //结束


#endif

class MySprite {    // 定义一个精灵类，即一个实体对象，可以是一个玩家操纵对象，敌人，也可以是构成道路的小方块等
public:             // 这样做的好处是方便管理对象，并易于掌控对象的图形更新，位移等操作
    IMAGE master_image;    // 精灵类图像
    Recta arect;            // 精灵类源图像的矩形大小（即master_image的矩阵大小）
    Recta rect;             // 精灵类图像在屏幕中的实际存在位置（矩阵）
    Recta2 restrict_rect = { -1,-1,-1,-1 };  // 精灵类在屏幕中的限制范围，如玩家操作对象（下简称玩家）在一个约定范围内移动，不得超过
    int frame = 0;          // 精灵类当前的位图帧
    int old_frame = -1;     // 精灵类上一次的位图帧（此游戏中未使用）
    int frame_width = 1;    // 精灵类的位图帧宽度
    int frame_height = 1;   // 精灵类的位图帧高度
    int first_frame = 0;    // 精灵类的第一个位图帧
    int last_frame = 0;     // 精灵类的最后一个位图帧
    int columns = 1;        // 精灵类的位图帧的列数
    clock_t last_time = 0;  // 精灵类上一次更新时的时间
    int direction = -1;     // 精灵类的方向（用于移动）（0为向右，1右上，2向上，以此类推）
    Pointf vspeed = { 1.0,1.0 };        // 精灵类的速度因子
    Pointf velocity = {0,0};            // 精灵类的速度
    float rotation = 0.0;               // 精灵类的旋转角（此游戏中未使用）
    float old_rotation = 0.0;           // 精灵类的旧旋转角（此游戏中未使用）
    Pointf positionf = { 0,0 };         // 精灵类的位置（在rect的基础上多设一个浮点数坐标有利于提高游戏计算精度）

public:
    int getx() { return rect.topleft.x; }   //设置x坐标（此游戏中未使用）
    void setx(int value) { rect.topleft.x = value; }  // 得到x坐标（此游戏中未使用）

    int gety() { return rect.topleft.y; }
    void sety(int value) { rect.topleft.y = value; }

    Point getpos() { return rect.topleft; }
    void setpos(Point pos) { rect.topleft = pos; }

    void setframe(int fframe,int lframe) { first_frame = fframe,last_frame = lframe;}; // 设置精灵类当前的位图帧宽度

    void setdirection(int d) { // 设置精灵类的方向
        if (direction != d) {
            direction = d;
            setspeed();   // 设置方向后调整速度
        }
    }

    void setspeed() {       // 设置精灵类的速度
        switch (direction) {
        case 0: velocity.x = 1.0 * vspeed.x,    velocity.y = 0;                 break;      //右
        case 1: velocity.x = 1.0 * vspeed.x,    velocity.y = -1.0 * vspeed.y;   break;      //右上
        case 2: velocity.x = 0,                 velocity.y = -1.0 * vspeed.y;   break;      //上
        case 3: velocity.x = -1.0 * vspeed.x,   velocity.y = -1.0 * vspeed.y;   break;      //左上
        case 4: velocity.x = -1.0 * vspeed.x,    velocity.y = 0;                break;      //左
        case 5: velocity.x = -1.0 * vspeed.x,    velocity.y = 1.0 * vspeed.y;   break;      //左下
        case 6: velocity.x = 0,                 velocity.y = 1.0 * vspeed.y;    break;      //下
        case 7: velocity.x = 1.0 * vspeed.x,    velocity.y = 1.0 * vspeed.y;    break;      //右下
        }
    }

    void move() {           // 对精灵类实现移动操作
        if (direction != -1) {   // 新位置 = 旧位置 + 速度
            positionf.x += velocity.x;   
            positionf.y += velocity.y;
        }
        if (restrict_rect.top != -1) {  // 对精灵类的移动范围（如果有的话）进行约束
            int  top = restrict_rect.top, left = restrict_rect.left,
                bottom = restrict_rect.bottom, right = restrict_rect.right;
            if (positionf.x <= left + rect.width / 2)       // 精灵类的rect坐标实际代表重心，需要考虑实际情况
                positionf.x = left + rect.width / 2;        // 如果当前精灵类的x坐标小于限定范围，则将x坐标置为临界值
            else if (positionf.x >= right - rect.width / 2)
                positionf.x = right - rect.width / 2;
            if (positionf.y >= bottom - rect.height / 2)
                positionf.y = bottom - rect.height / 2;
            else if (positionf.y <= top + rect.height / 2)
                positionf.y = top + rect.height / 2;
        }
        rect.topleft = Point{ (int)positionf.x,(int)positionf.y };      // 更新精灵类的rect坐标，即精灵类的位置
    }

    MySprite(char* filename, int width = 0, int height = 0, int columns = 1,int awidth = 0,int aheight = 0,int k2 = 1,int k1 = 1,int nframe = 0) {
        load(filename, width * k1 / k2, height * k1 / k2, columns, awidth * k1 / k2, aheight * k1 / k2,nframe);
    }   // 对精灵类进行初始化，需要提供精灵类的位图文件地址，（后面可选）单位图帧宽，高，列数，源图像总宽，高，缩放比例，扩大比例，是否固定位图帧
    MySprite(int k2, int k1,char* filename){  // 重载初始化，需提供缩放比例，扩大比例，位图文件地址
        loadimage(&master_image, filename);     // 这样初始化得到的精灵类只有单一图像，没有动图效果
        int awidth = master_image.getwidth();  // 自动计算精灵类的位图总宽，高
        int aheight = master_image.getheight();
        load(filename, awidth * k1 / k2, aheight * k1 / k2, 1, awidth * k1 / k2, aheight * k1 / k2);
    }
    MySprite(bool is, int awidth, int aheight, char* filename) {    // 另一个初始化重载，手动确定精灵类的位图总宽，高
        loadimage(&master_image, filename);
        int width = master_image.getwidth();
        int height = master_image.getheight();
        load(filename, width, height, 1, awidth, aheight);
    }
    MySprite(){}

    // 加载精灵类的源图像，参数有源图像路径，（后可选）位图帧宽，高，列数，总宽，总高，是否固定位图帧
    void load(char* filename, int width = 0, int height = 0, int columns = 1, int awidth = 0, int aheight = 0,int nframe = 0) {
        loadimage(&master_image, filename, awidth, aheight, true);      
        if (!(awidth == 0 || aheight == 0)) arect = Recta{ 0,0,awidth,aheight };   // 根据参数确定arect属性
        else arect = Recta{ 0,0,master_image.getwidth(),master_image.getheight()};  // 如果使用默认参数，则根据源图像大小自动确定arect属性
        set_image(width, height, columns,nframe);      // 设立图像
    }

    // 设立图像，参数有精灵类一个位图帧的宽，高，列数，及是否固定位图帧
    void set_image(int nwidth = 0, int nheight = 0, int ncolumns = 1,int nframe = 0) {
        if (nwidth == 0 || nheight == 0) {
            frame_width = arect.width;  // 默认参数下，位图帧宽高等于源图像总宽，高
            frame_height = arect.height;
        }
        else {
            frame_width = nwidth;   // 否则依据给定的位图帧宽高来计算源图像中有多少个位图帧
            frame_height = nheight;
            last_frame = (arect.width / nwidth) * (arect.height / nheight) - 1;  // 位图帧数 = (源图像宽 / 位图帧宽) *  (源图像高 / 位图帧高)
            if (nframe != 0) setframe(nframe,nframe);  // 若固定位图帧数，则使精灵类的首末位图帧相等，不会更新为其他位图帧
            rect = Recta(0, 0, frame_width, frame_height); // 初始化rect属性
            columns = ncolumns;
        }
    }

    void update(int current_time, int rate = 500) { // 更新动画（更新位图帧）
        if (last_frame > first_frame) {
            // 更新动画帧数
            if (current_time > last_time + rate) {  // 当与上次更新间隔大于动画帧更新频率时才更新动画
                frame += 1;
                if (frame > last_frame) frame = first_frame;
                last_time = current_time;
                // 只在帧改变时更新图像
                int frame_x = (frame % columns) * frame_width;
                int frame_y = (frame / columns) * frame_height;
                rect = Recta(frame_x, frame_y, frame_width, frame_height);
                old_frame = frame;
            }
        }
        else frame = first_frame;
    }

    void draw(int x,int y) {  // 绘画精灵类
        putimage_mask(x,y,frame_width,frame_height,&master_image,rect.topleft.x,rect.topleft.y);
    }
    void draw(int x, int y,clock_t current_time,int ticks = 30) {  // 绘画精灵类，但有时间间隔，此处效果不好，舍弃
        if (current_time > last_time + ticks) {
            putimage_mask(x, y, frame_width, frame_height, &master_image, rect.topleft.x, rect.topleft.y);
        }
    }
    void drawf(int x, int y, int nframe) {  // 绘画某一特定位图帧
        int frame_x = (nframe % columns) * frame_width;
        int frame_y = (nframe / columns) * frame_height;
        putimage_mask(x, y, frame_width, frame_height, &master_image, frame_x, frame_y);
    }
};

#include "MySprites.hpp"

int ATK_muti = 1;       // 定义玩家攻击力乘数因子
int views = 0;          // 定义直播观看人数
int game_out = 0;       // 定义游戏结局是否被触发（触发则为对应结局数字）
clock_t game_out_ddl = 0;   // 定义游戏结局响应时的触发时间（需game_out非0才触发）

//子弹
class Bullet {  // 定义玩家射出的子弹的类
public:
    Recta rect;   // 子弹有矩阵属性
    LL ATK;        // 子弹的攻击力属性
    int speed;      // 子弹的速度
    Bullet(int x, int y, int nwidth, int nheight, int nATK,int nspeed = 5) {
        rect.topleft = { x,y }, rect.width = nwidth, rect.height = nheight, ATK = nATK, speed = nspeed;
    }   // 初始化子弹对象

    void update() {  // 对子弹进行更新
        rect.topleft.y -= speed;  // 子弹移动
        COLORREF last_color = getfillcolor();
        setfillcolor(RGB(rand()%255,rand()%255,rand()%255));  // 令子弹颜色随机
        solidrectangle(rect.topleft.x, rect.topleft.y, rect.topleft.x + rect.width, rect.topleft.y + rect.height);
                // 子弹是一个矩形图像，直接用easyx的矩形创建函数绘制
        setfillcolor(last_color);  
    }
};


//玩家
class PlayerAlien :public MySprite {  // 定义玩家操作角色的类，继承自精灵类
public:
    IMAGE master_image2;  // 模拟动画，多定义了一个源图像
    LL HP = 10;     // 玩家对象的血量
    int index = 0;     // 玩家对象的索引（没用到）
    int level = 0;      // 玩家对象的级别
public:
    PlayerAlien(int nindex = 0,int nlevel = 0) {  // 初始化玩家对象
        while (nindex >= 9) nindex -= 9;
        index = nindex;
        level = nlevel;

        HP *= (int)pow(4, level);
        master_image = (*Res_alien[index + 10 * level]).master_image; 
        master_image2 = (*Res_alien[index + 1 + 10 * level]).master_image;

        rect  = Recta{ 0,0,master_image.getwidth(),master_image.getheight() };
        first_frame = 0, last_frame = 1;
        vspeed = Pointf{ 2.0,2.0 };
        restrict_rect = { 100,300,516,600};  // 设置玩家对象移动范围
    }

    void update(int current_time, int rate = 100) {
        //更新动画
        if (current_time > last_time + rate) {
            last_time = current_time;
            frame += 1;
            if (frame > last_frame) frame = first_frame;
        }
    }

    void draw() { // 绘制图像
        if (frame == 0) putimage_mask(rect.topleft.x - rect.width / 2, rect.topleft.y - rect.height / 2, &master_image);
        else putimage_mask(rect.topleft.x - rect.width / 2, rect.topleft.y - rect.height / 2, &master_image2);
    }

    void draw(clock_t current_time, int ticks = 30) { // 绘制图像，但使用更新频率来约束
        if (current_time > last_time + ticks) {
            last_time = current_time;
            if (frame == 0) putimage_mask(rect.topleft.x - rect.width / 2, rect.topleft.y - rect.height / 2, &master_image);
            else putimage_mask(rect.topleft.x - rect.width / 2, rect.topleft.y - rect.height / 2, &master_image2);
        }
    }
};


//敌人
class Enemy :public MySprite {  // 定义敌人对象
public:
    int origin_HP = 100;  // 敌人初始血量
    int HP = 100;       // 敌人当前血量
    int is_boss = 0;    // 顾名思义
public:
    Enemy(MySprite *res,int x,int y,int direction = 6) {  // 初始化敌人对象，需要提供一个精灵类指针用于复制图像
        master_image = res -> master_image;
        rect = Recta{ 0,0,master_image.getwidth(),master_image.getheight() };
        first_frame = 0, last_frame = 0;
        vspeed = Pointf{ 2.0,2.0 };
        positionf = Pointf{ (float)x,(float)y };
        setdirection(direction);   // 初始化敌人的位置与移动方向
        rect.topleft = Point{ (int)positionf.x,(int)positionf.y };
    }

    void update(int current_time, int rate = 100) { // 更新
        if (current_time > last_time + rate) {
            last_time = current_time;
            frame += 1;
            if (frame > last_frame) frame = first_frame;
        }
    }

    void move() { // 移动
        if (direction != -1) {
            positionf.x += velocity.x;
            positionf.y += velocity.y;
        }
        rect.topleft = Point{ (int)positionf.x,(int)positionf.y };
    }

    void draw() { // 绘制
        putimage_mask(rect.topleft.x - rect.width / 2, rect.topleft.y - rect.height / 2, &master_image);
    }
    void draw(clock_t current_time, int ticks = 30) {
        if (current_time > last_time + ticks) {
            last_time = current_time;
            putimage_mask(rect.topleft.x - rect.width / 2, rect.topleft.y - rect.height / 2, &master_image);
        }
    }

    void display_HP() {     // 展示敌人的当前血量
        char s[10];
        sprintf_s(s, "%d", HP);
        outtextxy(rect.topleft.x - textwidth(s) / 2, rect.topleft.y + rect.height / 4, s);
    }
};


//铭文
class Rune :public MySprite{  // 定义铭文类，玩家接触后会获得特殊效果
public:
    Recta pos_rect;         // 屏幕中位置
    LL effect_alien_vary = 0;       // 使玩家对象增/减
    float effect_alien_muti = 1;    // 使玩家对象乘以x
    LL effect_ATK_vary = 0;         // 使玩家攻击力加/减
    float effect_ATK_muti = 1;      // 使玩家攻击力乘以
    int effect_enemy_add = 0;       // 使场上敌人数加

    Rune(MySprite *res, int x, int y) {  // 初始化铭文类对象
        master_image = res->master_image;
        arect = res->arect;
        rect = res->rect;
        frame_width = res->frame_width;
        frame_height = res->frame_height;
        first_frame = res->first_frame;
        last_frame = res->last_frame;
        columns = res->columns;

        vspeed = Pointf{ 2.0,2.0 };
        positionf = Pointf{ (float)x,(float)y };
        pos_rect.topleft = Point{ (int)positionf.x,(int)positionf.y };  // 设置铭文类对象在屏幕中的位置
        setdirection(6);   // 铭文类对象由上到下掉落
    }

    void move() {  // 铭文类对象移动
        if (direction != -1) {
            positionf.x += velocity.x;
            positionf.y += velocity.y;
        }
        pos_rect.topleft = Point{ (int)positionf.x,(int)positionf.y };
    }

    void update(int current_time, int rate = 500) {   // 铭文类对象更新
        if (current_time > last_time + rate) {
            frame = rand()%35;
            if (frame > last_frame) frame = first_frame;
            last_time = current_time;

            int frame_x = (frame % columns) * frame_width;
            int frame_y = (frame / columns) * frame_height;
            rect = Recta(frame_x, frame_y, frame_width, frame_height);
            old_frame = frame;
        }
    }

    void draw() {      // 铭文类对象绘制
            putimage_mask(pos_rect.topleft.x - rect.width / 2, pos_rect.topleft.y - rect.height / 2,
                frame_width, frame_height, &master_image, rect.topleft.x, rect.topleft.y);
            if (effect_alien_vary != 0) {   // 铭文类对象绘制增益/减益的文字显示  如 +5 / -5
                char s[20];
                sprintf_s(s, "%+d", effect_alien_vary);
                outtextxy(pos_rect.topleft.x - textwidth(s) / 2, pos_rect.topleft.y + rect.height / 4, s);
            }
            else if (effect_alien_muti != 1) {      // 铭文类对象绘制增益/减益的文字显示  如 ^5
                char s[20];
                sprintf_s(s, "^%.1f", effect_alien_muti);
                outtextxy(pos_rect.topleft.x - textwidth(s) / 2, pos_rect.topleft.y + rect.height / 4, s);
            }
            else if (effect_ATK_vary != 0) {        // 铭文类对象绘制增益/减益的文字显示  如 ATK+5
                char s[20];
                sprintf_s(s, "ATK%+d", effect_ATK_vary);
                outtextxy(pos_rect.topleft.x - textwidth(s) / 2, pos_rect.topleft.y + rect.height / 4, s);
            }
            else if (effect_ATK_muti != 1) {           // 铭文类对象绘制增益/减益的文字显示  如 ATK^5
                char s[20];
                sprintf_s(s, "ATK^%.1f", effect_ATK_muti);
                outtextxy(pos_rect.topleft.x - textwidth(s) / 2, pos_rect.topleft.y + rect.height / 4, s);
            }
            else if (effect_enemy_add != 0) {       // 铭文类对象绘制增益/减益的文字显示  如 E+5
                char s[20];
                sprintf_s(s, "E%+d", effect_enemy_add);
                outtextxy(pos_rect.topleft.x - textwidth(s) / 2, pos_rect.topleft.y + rect.height / 4, s);
            }
            
    }
};

//二选一方块
class TBlock{       // 定义选择方块类，效果同铭文类一样
public:
    Recta rect;
    LL effect_alien_vary = 0;
    float effect_alien_muti = 1;
    LL effect_ATK_vary = 0;
    float effect_ATK_muti = 1;
    int effect_enemy_add = 0;
    COLORREF color;         // 方块类对象的颜色
    Pointf  velocity = Pointf{ 0,1.0 };
    bool is_HP = false;     // 方块类对象是否需要靠攻击来摧毁，默认为靠接触即可拾取，定义为true时玩家碰到会掉血
    int origin_HP = 100;
    int HP = 100;

    TBlock(int direction = 0, int HP = 100, COLORREF _color = RGB(40,0,0)) {        // 方块类对象定义
        if (direction == 0) rect.topleft.x = 100, rect.topleft.y = 0, rect.width = 208, rect.height = 40;
        else rect.topleft.x = 100 + 208, rect.topleft.y = 0, rect.width = 208, rect.height = 40;
        color = _color;
    }

    void move() {           // 方块类对象移动
        rect.topleft.x += velocity.x;
        rect.topleft.y += velocity.y;
    }

    void draw() {           // 方块类对象绘制
        setfillcolor(color);
        setlinecolor(WHITE);    // 设置线条颜色
        fillrectangle(rect.topleft.x, rect.topleft.y, rect.topleft.x + rect.width, rect.topleft.y + rect.height);
        // 填充矩形，表示方块类对象

        char s[20];
        if (is_HP) {    // 如果选择方块类对象拥有HP属性，则在屏幕上显示HP的值
            sprintf_s(s, "%d", HP);
            outtextxy(rect.topleft.x + rect.width / 2 - textwidth(s) / 2, rect.topleft.y + rect.height / 4 * 3, s);
        }

        if (effect_alien_vary != 0) {       // 同铭文类的效果显示
            sprintf_s(s, "%+d", effect_alien_vary);
            outtextxy(rect.topleft.x + rect.width / 2 - textwidth(s) / 2, rect.topleft.y + rect.height / 4, s);
        }
        else if (effect_alien_muti != 1) {
            sprintf_s(s, "^%.1f", effect_alien_muti);
            outtextxy(rect.topleft.x + rect.width / 2 - textwidth(s) / 2, rect.topleft.y + rect.height / 4, s);
        }
        else if (effect_ATK_vary != 0) {
            sprintf_s(s, "ATK%+d", effect_ATK_vary);
            outtextxy(rect.topleft.x + rect.width / 2 - textwidth(s) / 2, rect.topleft.y + rect.height / 4, s);
        }
        else if (effect_ATK_muti != 1) {
            sprintf_s(s, "ATK^%.1f", effect_ATK_muti);
            outtextxy(rect.topleft.x + rect.width / 2 - textwidth(s) / 2, rect.topleft.y + rect.height / 4, s);
        }
        else if (effect_enemy_add != 0) {       // 同上
            sprintf_s(s, "E%+d", effect_enemy_add);
            outtextxy(rect.topleft.x + rect.width / 2 - textwidth(s) / 2, rect.topleft.y + rect.height / 4, s);
        }

    }

};

//主播
class Utuber :public MySprite {     // 定义主播类，用于管理主播的表情
public:
    int frame = 2;          // 主播的当前位图帧
    int last_frame = 37;

    void update(int current_time, int rate = 1000) {        // 主播类更新，每次更新使当前帧+1（该函数用于测试，实际不用）
        if (current_time > last_time + rate) {      // 设置更新间隔
                frame += 1;         
                if (frame > last_frame) frame = first_frame;
                last_time = current_time;
                master_image = Res_ctj[frame]->master_image;
        }
    }

    void setframe(int nframe) {    // 设置主播类位图帧
        frame = nframe;
        master_image = Res_ctj[frame]->master_image;
    }

    void draw() {       // 主播类表情绘制
        putimage_mask(650, 387, &master_image);
    }
};
#endif


