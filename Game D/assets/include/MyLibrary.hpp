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

// ���ļ������徫�����Լ�����������Ĳ���
// ��������������ԣ���ʼ�������ƺ������˶����������º�����


#if 1
struct Point {
    int x, y;
    Point(int nx = 0, int ny = 0) {
        x = nx, y = ny;
    }
}; // ����һ����ṹ�壬�洢������Ϣ��xy����Ϊ����

struct Pointf {
    float x, y;
    Pointf(float nx = 0, float ny = 0) {
        x = nx, y = ny;
    }
}; // ����㣬xy����Ϊ��������


struct Recta {
    Point topleft;
    int width, height;
    Recta(int nx = 0, int ny = 0, int nwidth = 0, int nheight = 0) {
        topleft.x = nx, topleft.y = ny, width = nwidth, height = nheight;
    }
}; // ����һ���������ݽṹ�壬һ����������������Ͻ����꣬��������

struct Recta2 {
    int left,top, right,bottom;
}; // ����һ���������һ�ֱ�ʾ��ʽ�������Ͻ�����+���½�����
    // ���־������������ʹ��


// ����һ��ģ����Ҫ���ڴ���Ƕ�ת����λͼ��ת�������ز���������Ϸ�в���Ҫ�������¿�ʡ��
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
#endif //����


#endif

class MySprite {    // ����һ�������࣬��һ��ʵ����󣬿�����һ����Ҳ��ݶ��󣬵��ˣ�Ҳ�����ǹ��ɵ�·��С�����
public:             // �������ĺô��Ƿ��������󣬲������ƿض����ͼ�θ��£�λ�ƵȲ���
    IMAGE master_image;    // ������ͼ��
    Recta arect;            // ������Դͼ��ľ��δ�С����master_image�ľ����С��
    Recta rect;             // ������ͼ������Ļ�е�ʵ�ʴ���λ�ã�����
    Recta2 restrict_rect = { -1,-1,-1,-1 };  // ����������Ļ�е����Ʒ�Χ������Ҳ��������¼����ң���һ��Լ����Χ���ƶ������ó���
    int frame = 0;          // �����൱ǰ��λͼ֡
    int old_frame = -1;     // ��������һ�ε�λͼ֡������Ϸ��δʹ�ã�
    int frame_width = 1;    // �������λͼ֡���
    int frame_height = 1;   // �������λͼ֡�߶�
    int first_frame = 0;    // ������ĵ�һ��λͼ֡
    int last_frame = 0;     // ����������һ��λͼ֡
    int columns = 1;        // �������λͼ֡������
    clock_t last_time = 0;  // ��������һ�θ���ʱ��ʱ��
    int direction = -1;     // ������ķ��������ƶ�����0Ϊ���ң�1���ϣ�2���ϣ��Դ����ƣ�
    Pointf vspeed = { 1.0,1.0 };        // ��������ٶ�����
    Pointf velocity = {0,0};            // ��������ٶ�
    float rotation = 0.0;               // ���������ת�ǣ�����Ϸ��δʹ�ã�
    float old_rotation = 0.0;           // ������ľ���ת�ǣ�����Ϸ��δʹ�ã�
    Pointf positionf = { 0,0 };         // �������λ�ã���rect�Ļ����϶���һ�����������������������Ϸ���㾫�ȣ�

public:
    int getx() { return rect.topleft.x; }   //����x���꣨����Ϸ��δʹ�ã�
    void setx(int value) { rect.topleft.x = value; }  // �õ�x���꣨����Ϸ��δʹ�ã�

    int gety() { return rect.topleft.y; }
    void sety(int value) { rect.topleft.y = value; }

    Point getpos() { return rect.topleft; }
    void setpos(Point pos) { rect.topleft = pos; }

    void setframe(int fframe,int lframe) { first_frame = fframe,last_frame = lframe;}; // ���þ����൱ǰ��λͼ֡���

    void setdirection(int d) { // ���þ�����ķ���
        if (direction != d) {
            direction = d;
            setspeed();   // ���÷��������ٶ�
        }
    }

    void setspeed() {       // ���þ�������ٶ�
        switch (direction) {
        case 0: velocity.x = 1.0 * vspeed.x,    velocity.y = 0;                 break;      //��
        case 1: velocity.x = 1.0 * vspeed.x,    velocity.y = -1.0 * vspeed.y;   break;      //����
        case 2: velocity.x = 0,                 velocity.y = -1.0 * vspeed.y;   break;      //��
        case 3: velocity.x = -1.0 * vspeed.x,   velocity.y = -1.0 * vspeed.y;   break;      //����
        case 4: velocity.x = -1.0 * vspeed.x,    velocity.y = 0;                break;      //��
        case 5: velocity.x = -1.0 * vspeed.x,    velocity.y = 1.0 * vspeed.y;   break;      //����
        case 6: velocity.x = 0,                 velocity.y = 1.0 * vspeed.y;    break;      //��
        case 7: velocity.x = 1.0 * vspeed.x,    velocity.y = 1.0 * vspeed.y;    break;      //����
        }
    }

    void move() {           // �Ծ�����ʵ���ƶ�����
        if (direction != -1) {   // ��λ�� = ��λ�� + �ٶ�
            positionf.x += velocity.x;   
            positionf.y += velocity.y;
        }
        if (restrict_rect.top != -1) {  // �Ծ�������ƶ���Χ������еĻ�������Լ��
            int  top = restrict_rect.top, left = restrict_rect.left,
                bottom = restrict_rect.bottom, right = restrict_rect.right;
            if (positionf.x <= left + rect.width / 2)       // �������rect����ʵ�ʴ������ģ���Ҫ����ʵ�����
                positionf.x = left + rect.width / 2;        // �����ǰ�������x����С���޶���Χ����x������Ϊ�ٽ�ֵ
            else if (positionf.x >= right - rect.width / 2)
                positionf.x = right - rect.width / 2;
            if (positionf.y >= bottom - rect.height / 2)
                positionf.y = bottom - rect.height / 2;
            else if (positionf.y <= top + rect.height / 2)
                positionf.y = top + rect.height / 2;
        }
        rect.topleft = Point{ (int)positionf.x,(int)positionf.y };      // ���¾������rect���꣬���������λ��
    }

    MySprite(char* filename, int width = 0, int height = 0, int columns = 1,int awidth = 0,int aheight = 0,int k2 = 1,int k1 = 1,int nframe = 0) {
        load(filename, width * k1 / k2, height * k1 / k2, columns, awidth * k1 / k2, aheight * k1 / k2,nframe);
    }   // �Ծ�������г�ʼ������Ҫ�ṩ�������λͼ�ļ���ַ���������ѡ����λͼ֡���ߣ�������Դͼ���ܿ��ߣ����ű���������������Ƿ�̶�λͼ֡
    MySprite(int k2, int k1,char* filename){  // ���س�ʼ�������ṩ���ű��������������λͼ�ļ���ַ
        loadimage(&master_image, filename);     // ������ʼ���õ��ľ�����ֻ�е�һͼ��û�ж�ͼЧ��
        int awidth = master_image.getwidth();  // �Զ����㾫�����λͼ�ܿ���
        int aheight = master_image.getheight();
        load(filename, awidth * k1 / k2, aheight * k1 / k2, 1, awidth * k1 / k2, aheight * k1 / k2);
    }
    MySprite(bool is, int awidth, int aheight, char* filename) {    // ��һ����ʼ�����أ��ֶ�ȷ���������λͼ�ܿ���
        loadimage(&master_image, filename);
        int width = master_image.getwidth();
        int height = master_image.getheight();
        load(filename, width, height, 1, awidth, aheight);
    }
    MySprite(){}

    // ���ؾ������Դͼ�񣬲�����Դͼ��·���������ѡ��λͼ֡���ߣ��������ܿ��ܸߣ��Ƿ�̶�λͼ֡
    void load(char* filename, int width = 0, int height = 0, int columns = 1, int awidth = 0, int aheight = 0,int nframe = 0) {
        loadimage(&master_image, filename, awidth, aheight, true);      
        if (!(awidth == 0 || aheight == 0)) arect = Recta{ 0,0,awidth,aheight };   // ���ݲ���ȷ��arect����
        else arect = Recta{ 0,0,master_image.getwidth(),master_image.getheight()};  // ���ʹ��Ĭ�ϲ����������Դͼ���С�Զ�ȷ��arect����
        set_image(width, height, columns,nframe);      // ����ͼ��
    }

    // ����ͼ�񣬲����о�����һ��λͼ֡�Ŀ��ߣ����������Ƿ�̶�λͼ֡
    void set_image(int nwidth = 0, int nheight = 0, int ncolumns = 1,int nframe = 0) {
        if (nwidth == 0 || nheight == 0) {
            frame_width = arect.width;  // Ĭ�ϲ����£�λͼ֡��ߵ���Դͼ���ܿ���
            frame_height = arect.height;
        }
        else {
            frame_width = nwidth;   // �������ݸ�����λͼ֡���������Դͼ�����ж��ٸ�λͼ֡
            frame_height = nheight;
            last_frame = (arect.width / nwidth) * (arect.height / nheight) - 1;  // λͼ֡�� = (Դͼ��� / λͼ֡��) *  (Դͼ��� / λͼ֡��)
            if (nframe != 0) setframe(nframe,nframe);  // ���̶�λͼ֡������ʹ���������ĩλͼ֡��ȣ��������Ϊ����λͼ֡
            rect = Recta(0, 0, frame_width, frame_height); // ��ʼ��rect����
            columns = ncolumns;
        }
    }

    void update(int current_time, int rate = 500) { // ���¶���������λͼ֡��
        if (last_frame > first_frame) {
            // ���¶���֡��
            if (current_time > last_time + rate) {  // �����ϴθ��¼�����ڶ���֡����Ƶ��ʱ�Ÿ��¶���
                frame += 1;
                if (frame > last_frame) frame = first_frame;
                last_time = current_time;
                // ֻ��֡�ı�ʱ����ͼ��
                int frame_x = (frame % columns) * frame_width;
                int frame_y = (frame / columns) * frame_height;
                rect = Recta(frame_x, frame_y, frame_width, frame_height);
                old_frame = frame;
            }
        }
        else frame = first_frame;
    }

    void draw(int x,int y) {  // �滭������
        putimage_mask(x,y,frame_width,frame_height,&master_image,rect.topleft.x,rect.topleft.y);
    }
    void draw(int x, int y,clock_t current_time,int ticks = 30) {  // �滭�����࣬����ʱ�������˴�Ч�����ã�����
        if (current_time > last_time + ticks) {
            putimage_mask(x, y, frame_width, frame_height, &master_image, rect.topleft.x, rect.topleft.y);
        }
    }
    void drawf(int x, int y, int nframe) {  // �滭ĳһ�ض�λͼ֡
        int frame_x = (nframe % columns) * frame_width;
        int frame_y = (nframe / columns) * frame_height;
        putimage_mask(x, y, frame_width, frame_height, &master_image, frame_x, frame_y);
    }
};

#include "MySprites.hpp"

int ATK_muti = 1;       // ������ҹ�������������
int views = 0;          // ����ֱ���ۿ�����
int game_out = 0;       // ������Ϸ����Ƿ񱻴�����������Ϊ��Ӧ������֣�
clock_t game_out_ddl = 0;   // ������Ϸ�����Ӧʱ�Ĵ���ʱ�䣨��game_out��0�Ŵ�����

//�ӵ�
class Bullet {  // �������������ӵ�����
public:
    Recta rect;   // �ӵ��о�������
    LL ATK;        // �ӵ��Ĺ���������
    int speed;      // �ӵ����ٶ�
    Bullet(int x, int y, int nwidth, int nheight, int nATK,int nspeed = 5) {
        rect.topleft = { x,y }, rect.width = nwidth, rect.height = nheight, ATK = nATK, speed = nspeed;
    }   // ��ʼ���ӵ�����

    void update() {  // ���ӵ����и���
        rect.topleft.y -= speed;  // �ӵ��ƶ�
        COLORREF last_color = getfillcolor();
        setfillcolor(RGB(rand()%255,rand()%255,rand()%255));  // ���ӵ���ɫ���
        solidrectangle(rect.topleft.x, rect.topleft.y, rect.topleft.x + rect.width, rect.topleft.y + rect.height);
                // �ӵ���һ������ͼ��ֱ����easyx�ľ��δ�����������
        setfillcolor(last_color);  
    }
};


//���
class PlayerAlien :public MySprite {  // ������Ҳ�����ɫ���࣬�̳��Ծ�����
public:
    IMAGE master_image2;  // ģ�⶯�����ඨ����һ��Դͼ��
    LL HP = 10;     // ��Ҷ����Ѫ��
    int index = 0;     // ��Ҷ����������û�õ���
    int level = 0;      // ��Ҷ���ļ���
public:
    PlayerAlien(int nindex = 0,int nlevel = 0) {  // ��ʼ����Ҷ���
        while (nindex >= 9) nindex -= 9;
        index = nindex;
        level = nlevel;

        HP *= (int)pow(4, level);
        master_image = (*Res_alien[index + 10 * level]).master_image; 
        master_image2 = (*Res_alien[index + 1 + 10 * level]).master_image;

        rect  = Recta{ 0,0,master_image.getwidth(),master_image.getheight() };
        first_frame = 0, last_frame = 1;
        vspeed = Pointf{ 2.0,2.0 };
        restrict_rect = { 100,300,516,600};  // ������Ҷ����ƶ���Χ
    }

    void update(int current_time, int rate = 100) {
        //���¶���
        if (current_time > last_time + rate) {
            last_time = current_time;
            frame += 1;
            if (frame > last_frame) frame = first_frame;
        }
    }

    void draw() { // ����ͼ��
        if (frame == 0) putimage_mask(rect.topleft.x - rect.width / 2, rect.topleft.y - rect.height / 2, &master_image);
        else putimage_mask(rect.topleft.x - rect.width / 2, rect.topleft.y - rect.height / 2, &master_image2);
    }

    void draw(clock_t current_time, int ticks = 30) { // ����ͼ�񣬵�ʹ�ø���Ƶ����Լ��
        if (current_time > last_time + ticks) {
            last_time = current_time;
            if (frame == 0) putimage_mask(rect.topleft.x - rect.width / 2, rect.topleft.y - rect.height / 2, &master_image);
            else putimage_mask(rect.topleft.x - rect.width / 2, rect.topleft.y - rect.height / 2, &master_image2);
        }
    }
};


//����
class Enemy :public MySprite {  // ������˶���
public:
    int origin_HP = 100;  // ���˳�ʼѪ��
    int HP = 100;       // ���˵�ǰѪ��
    int is_boss = 0;    // ����˼��
public:
    Enemy(MySprite *res,int x,int y,int direction = 6) {  // ��ʼ�����˶�����Ҫ�ṩһ��������ָ�����ڸ���ͼ��
        master_image = res -> master_image;
        rect = Recta{ 0,0,master_image.getwidth(),master_image.getheight() };
        first_frame = 0, last_frame = 0;
        vspeed = Pointf{ 2.0,2.0 };
        positionf = Pointf{ (float)x,(float)y };
        setdirection(direction);   // ��ʼ�����˵�λ�����ƶ�����
        rect.topleft = Point{ (int)positionf.x,(int)positionf.y };
    }

    void update(int current_time, int rate = 100) { // ����
        if (current_time > last_time + rate) {
            last_time = current_time;
            frame += 1;
            if (frame > last_frame) frame = first_frame;
        }
    }

    void move() { // �ƶ�
        if (direction != -1) {
            positionf.x += velocity.x;
            positionf.y += velocity.y;
        }
        rect.topleft = Point{ (int)positionf.x,(int)positionf.y };
    }

    void draw() { // ����
        putimage_mask(rect.topleft.x - rect.width / 2, rect.topleft.y - rect.height / 2, &master_image);
    }
    void draw(clock_t current_time, int ticks = 30) {
        if (current_time > last_time + ticks) {
            last_time = current_time;
            putimage_mask(rect.topleft.x - rect.width / 2, rect.topleft.y - rect.height / 2, &master_image);
        }
    }

    void display_HP() {     // չʾ���˵ĵ�ǰѪ��
        char s[10];
        sprintf_s(s, "%d", HP);
        outtextxy(rect.topleft.x - textwidth(s) / 2, rect.topleft.y + rect.height / 4, s);
    }
};


//����
class Rune :public MySprite{  // ���������࣬��ҽӴ����������Ч��
public:
    Recta pos_rect;         // ��Ļ��λ��
    LL effect_alien_vary = 0;       // ʹ��Ҷ�����/��
    float effect_alien_muti = 1;    // ʹ��Ҷ������x
    LL effect_ATK_vary = 0;         // ʹ��ҹ�������/��
    float effect_ATK_muti = 1;      // ʹ��ҹ���������
    int effect_enemy_add = 0;       // ʹ���ϵ�������

    Rune(MySprite *res, int x, int y) {  // ��ʼ�����������
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
        pos_rect.topleft = Point{ (int)positionf.x,(int)positionf.y };  // �����������������Ļ�е�λ��
        setdirection(6);   // ������������ϵ��µ���
    }

    void move() {  // ����������ƶ�
        if (direction != -1) {
            positionf.x += velocity.x;
            positionf.y += velocity.y;
        }
        pos_rect.topleft = Point{ (int)positionf.x,(int)positionf.y };
    }

    void update(int current_time, int rate = 500) {   // ������������
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

    void draw() {      // ������������
            putimage_mask(pos_rect.topleft.x - rect.width / 2, pos_rect.topleft.y - rect.height / 2,
                frame_width, frame_height, &master_image, rect.topleft.x, rect.topleft.y);
            if (effect_alien_vary != 0) {   // ����������������/�����������ʾ  �� +5 / -5
                char s[20];
                sprintf_s(s, "%+d", effect_alien_vary);
                outtextxy(pos_rect.topleft.x - textwidth(s) / 2, pos_rect.topleft.y + rect.height / 4, s);
            }
            else if (effect_alien_muti != 1) {      // ����������������/�����������ʾ  �� ^5
                char s[20];
                sprintf_s(s, "^%.1f", effect_alien_muti);
                outtextxy(pos_rect.topleft.x - textwidth(s) / 2, pos_rect.topleft.y + rect.height / 4, s);
            }
            else if (effect_ATK_vary != 0) {        // ����������������/�����������ʾ  �� ATK+5
                char s[20];
                sprintf_s(s, "ATK%+d", effect_ATK_vary);
                outtextxy(pos_rect.topleft.x - textwidth(s) / 2, pos_rect.topleft.y + rect.height / 4, s);
            }
            else if (effect_ATK_muti != 1) {           // ����������������/�����������ʾ  �� ATK^5
                char s[20];
                sprintf_s(s, "ATK^%.1f", effect_ATK_muti);
                outtextxy(pos_rect.topleft.x - textwidth(s) / 2, pos_rect.topleft.y + rect.height / 4, s);
            }
            else if (effect_enemy_add != 0) {       // ����������������/�����������ʾ  �� E+5
                char s[20];
                sprintf_s(s, "E%+d", effect_enemy_add);
                outtextxy(pos_rect.topleft.x - textwidth(s) / 2, pos_rect.topleft.y + rect.height / 4, s);
            }
            
    }
};

//��ѡһ����
class TBlock{       // ����ѡ�񷽿��࣬Ч��ͬ������һ��
public:
    Recta rect;
    LL effect_alien_vary = 0;
    float effect_alien_muti = 1;
    LL effect_ATK_vary = 0;
    float effect_ATK_muti = 1;
    int effect_enemy_add = 0;
    COLORREF color;         // ������������ɫ
    Pointf  velocity = Pointf{ 0,1.0 };
    bool is_HP = false;     // ����������Ƿ���Ҫ���������ݻ٣�Ĭ��Ϊ���Ӵ�����ʰȡ������Ϊtrueʱ����������Ѫ
    int origin_HP = 100;
    int HP = 100;

    TBlock(int direction = 0, int HP = 100, COLORREF _color = RGB(40,0,0)) {        // �����������
        if (direction == 0) rect.topleft.x = 100, rect.topleft.y = 0, rect.width = 208, rect.height = 40;
        else rect.topleft.x = 100 + 208, rect.topleft.y = 0, rect.width = 208, rect.height = 40;
        color = _color;
    }

    void move() {           // ����������ƶ�
        rect.topleft.x += velocity.x;
        rect.topleft.y += velocity.y;
    }

    void draw() {           // ������������
        setfillcolor(color);
        setlinecolor(WHITE);    // ����������ɫ
        fillrectangle(rect.topleft.x, rect.topleft.y, rect.topleft.x + rect.width, rect.topleft.y + rect.height);
        // �����Σ���ʾ���������

        char s[20];
        if (is_HP) {    // ���ѡ�񷽿������ӵ��HP���ԣ�������Ļ����ʾHP��ֵ
            sprintf_s(s, "%d", HP);
            outtextxy(rect.topleft.x + rect.width / 2 - textwidth(s) / 2, rect.topleft.y + rect.height / 4 * 3, s);
        }

        if (effect_alien_vary != 0) {       // ͬ�������Ч����ʾ
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
        else if (effect_enemy_add != 0) {       // ͬ��
            sprintf_s(s, "E%+d", effect_enemy_add);
            outtextxy(rect.topleft.x + rect.width / 2 - textwidth(s) / 2, rect.topleft.y + rect.height / 4, s);
        }

    }

};

//����
class Utuber :public MySprite {     // ���������࣬���ڹ��������ı���
public:
    int frame = 2;          // �����ĵ�ǰλͼ֡
    int last_frame = 37;

    void update(int current_time, int rate = 1000) {        // ��������£�ÿ�θ���ʹ��ǰ֡+1���ú������ڲ��ԣ�ʵ�ʲ��ã�
        if (current_time > last_time + rate) {      // ���ø��¼��
                frame += 1;         
                if (frame > last_frame) frame = first_frame;
                last_time = current_time;
                master_image = Res_ctj[frame]->master_image;
        }
    }

    void setframe(int nframe) {    // ����������λͼ֡
        frame = nframe;
        master_image = Res_ctj[frame]->master_image;
    }

    void draw() {       // ������������
        putimage_mask(650, 387, &master_image);
    }
};
#endif


