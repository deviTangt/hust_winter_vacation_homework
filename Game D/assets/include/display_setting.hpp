#ifndef DISPLAY_SETTING_HPP
#define DISPLAY_SETTING_HPP

using namespace std;


// 该文件负责消息出来相关功能



// 判断当前有哪些字母键和数字键被按下，用位记录
void getkeyConsole(int* alpha, int* num) {
	for (char c = 'A'; c <= 'Z'; c += 1) {
		if (GetKeyState(c) & 0x8000) *alpha |= 1 << (c - 'A');
	}
	for (char c = '0'; c <= '9'; c += 1) {
		if (GetKeyState(c) & 0x8000) *num |= 1 << (c - '0');
	}
}

char info_xy[30],info_button[30];		// 要显示的信息：鼠标坐标，键盘输入
void display_mouse(ExMessage msg,bool pos_display = true, bool button_display = true) {  // 展示鼠标信息
	if (msg.message) {
		if (pos_display) {
			sprintf_s(info_xy, "MOUSE POSITION: %d , %d", msg.x, msg.y);  // 展示鼠标坐标信息
		}

		if (button_display) {
			if (msg.message == WM_LBUTTONDOWN)		// 展示鼠标按键信息
				strcpy_s(info_button, "Status: "), strcat_s(info_button, "LeftButtonDown");
			else if (msg.message == WM_MBUTTONDOWN) 
				strcpy_s(info_button, "Status: "), strcat_s(info_button, "MiddleButtonDown");
			else if (msg.message == WM_RBUTTONDOWN) 
				strcpy_s(info_button, "Status: "), strcat_s(info_button, "RightButtonDown");
			else if (msg.message == WM_MOUSEWHEEL) 
				strcpy_s(info_button, "Status: "), strcat_s(info_button, "MouseWheel");
			else if (msg.message == WM_LBUTTONDBLCLK) 
				strcpy_s(info_button, "Status: "), strcat_s(info_button, "LeftDoubleClick");
			else if (msg.message == WM_RBUTTONDBLCLK) 
				strcpy_s(info_button, "Status: "), strcat_s(info_button, "RightDoubleClick");
		}
	}
	outtextxy(20, 200, info_xy);		// 展示鼠标坐标信息
	outtextxy(20, 220, info_button);	// 展示鼠标按键信息
}

char info[30] = "KEYDOWN: ", add[3] = "";	// 展示键盘按键信息，包括数字键，字母键与小键盘上下左右键
void display_key(ExMessage msg) {
	if (msg.message) {
		if (msg.message == WM_KEYDOWN) {
				strcpy_s(info, "KEYDOWN: "); strcpy_s(add, "");
				if (GetKeyState(VK_UP) & 0x8000) strcat_s(info, "Up");
				else if (GetKeyState(VK_DOWN) & 0x8000) strcat_s(info, "Down");
				else if (GetKeyState(VK_LEFT) & 0x8000) strcat_s(info, "Left");
				else if (GetKeyState(VK_RIGHT) & 0x8000) strcat_s(info, "Right");
				else if (GetKeyState(VK_SPACE) & 0x8000) strcat_s(info, "Space");
				else if (msg.vkcode >= 'A' && msg.vkcode <= 'Z') sprintf_s(info, "%s%c", info, msg.vkcode);
				else if (msg.vkcode >= '0' && msg.vkcode <= '9') sprintf_s(info, "%s%c", info, msg.vkcode);
		}
	}
	outtextxy(20, 240, info);		// 展示键盘按键信息
}

#endif