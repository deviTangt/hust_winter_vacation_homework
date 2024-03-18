#ifndef MUSIC_HANDLE_H
#define MUSIC_HANDLE_H
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

// 该文件负责音乐相关部分
// 包括音乐文件路径的宏定义，以及用windows api对音乐进行播放，暂停等操作的函数定义

// 音乐文件宏定义
#if 1
#define wav_ctj0 "res\\music\\CTJAudioClip\\BIOS_HDD0.wav"
#define wav_ctj1 "res\\music\\CTJAudioClip\\BIOS_piko1.wav"
#define wav_ctj2 "res\\music\\CTJAudioClip\\bluescreen2.wav"
#define wav_ctj3 "res\\music\\CTJAudioClip\\Boot.wav3"
#define wav_ctj4 "res\\music\\CTJAudioClip\\Boot_Caution4.wav"
#define wav_ctj5 "res\\music\\CTJAudioClip\\chari5.wav"
#define wav_ctj6 "res\\music\\CTJAudioClip\\charin6.wav"
#define wav_ctj7 "res\\music\\CTJAudioClip\\command_execute7.wav"
#define wav_ctj8 "res\\music\\CTJAudioClip\\day_start8.wav"
#define wav_ctj9 "res\\music\\CTJAudioClip\\Dialog9.wav"

#define wav_ctj10 "res\\music\\CTJAudioClip\\dosa10.wav"
#define wav_ctj11 "res\\music\\CTJAudioClip\\endHaishin11.wav"
#define wav_ctj12 "res\\music\\CTJAudioClip\\ending_dead12.wav"
#define wav_ctj13 "res\\music\\CTJAudioClip\\ending_ginga13.wav3"
#define wav_ctj14 "res\\music\\CTJAudioClip\\ending_ideon14.wav"
#define wav_ctj15 "res\\music\\CTJAudioClip\\ending_kenjo15.wav"
#define wav_ctj16 "res\\music\\CTJAudioClip\\endng_normal16.wav"
#define wav_ctj17 "res\\music\\CTJAudioClip\\event_emo17.wav"
#define wav_ctj18 "res\\music\\CTJAudioClip\\event_happy18.wav"
#define wav_ctj19 "res\\music\\CTJAudioClip\\event_kincho19.wav"

#define wav_ctj20 "res\\music\\CTJAudioClip\\event_yami20.wav"
#define wav_ctj21 "res\\music\\CTJAudioClip\\game_start21.wav"
#define wav_ctj22 "res\\music\\CTJAudioClip\\gamePlay22.wav3"
#define wav_ctj23 "res\\music\\CTJAudioClip\\haisin_superchat23.wav"
#define wav_ctj24 "res\\music\\CTJAudioClip\\happydeai24.wav"
#define wav_ctj25 "res\\music\\CTJAudioClip\\internetoverdose_offvocal_sabi25.wav"
#define wav_ctj26 "res\\music\\CTJAudioClip\\internetoverdose_offvocal26.wav"
#define wav_ctj27 "res\\music\\CTJAudioClip\\InternetOverdose227.wav"
#define wav_ctj28 "res\\music\\CTJAudioClip\\InternetOverdose8bit28.wav"
#define wav_ctj29 "res\\music\\CTJAudioClip\\InternetOverdose8bit29.wav"

#define wav_ctj30 "res\\music\\CTJAudioClip\\jine_recieve30.wav"
#define wav_ctj31 "res\\music\\CTJAudioClip\\jine_send_stamp31.wav"
#define wav_ctj32 "res\\music\\CTJAudioClip\\mainloop_emoarranged32.wav3"
#define wav_ctj33 "res\\music\\CTJAudioClip\\mainloop_kenjo33.wav"
#define wav_ctj34 "res\\music\\CTJAudioClip\\mainloop_middle34.wav"
#define wav_ctj35 "res\\music\\CTJAudioClip\\mainloop_normal35.wav"
#define wav_ctj36 "res\\music\\CTJAudioClip\\mainloop_normaledarranged36.wav"
#define wav_ctj37 "res\\music\\CTJAudioClip\\mainloop_shuban37.wav"
#define wav_ctj38 "res\\music\\CTJAudioClip\\mainloop_yami38.wav"
#define wav_ctj39 "res\\music\\CTJAudioClip\\OP_PV39.wav"

#define wav_ctj40 "res\\music\\CTJAudioClip\\renewal40.wav"
#define wav_ctj41 "res\\music\\CTJAudioClip\\result_start41.wav"
#define wav_ctj42 "res\\music\\CTJAudioClip\\status_down42.wav3"
#define wav_ctj43 "res\\music\\CTJAudioClip\\status_up43.wav"
#define wav_ctj44 "res\\music\\CTJAudioClip\\stress_down44.wav"
#define wav_ctj45 "res\\music\\CTJAudioClip\\stress_up_lv145.wav"
#define wav_ctj46 "res\\music\\CTJAudioClip\\stress_up_lv246.wav"
#define wav_ctj47 "res\\music\\CTJAudioClip\\stress_up_lv347.wav"
#define wav_ctj48 "res\\music\\CTJAudioClip\\Tetehen48.wav"
#define wav_ctj49 "res\\music\\CTJAudioClip\\zevent_yami49.wav"

#define wav_ctj50 "res\\music\\CTJAudioClip\\zzarazaranoise_lv250.wav"
#define wav_ctj51 "res\\music\\CTJAudioClip\\zzugozugozugo51.wav"
#define wav_ctj52 "res\\music\\CTJAudioClip\\zzugyaaaann52.wav3"
#define wav_ctj53 "res\\music\\CTJAudioClip\\zheartbeat53.wav"
#define wav_ctj54 "res\\music\\CTJAudioClip\\zgagagagaga54.wav"
#define wav_ctj55 "res\\music\\CTJAudioClip\\zhorrornoise_A55.wav"

char* wav_ctj_class[56] = { wav_ctj0,wav_ctj1,wav_ctj2,wav_ctj3,wav_ctj4,wav_ctj5,wav_ctj6,wav_ctj7,wav_ctj8,wav_ctj9,
							wav_ctj10,wav_ctj11,wav_ctj12,wav_ctj13,wav_ctj14,wav_ctj15,wav_ctj16,wav_ctj17,wav_ctj18,wav_ctj19,
							wav_ctj20,wav_ctj21,wav_ctj22,wav_ctj23,wav_ctj24,wav_ctj25,wav_ctj26,wav_ctj27,wav_ctj28,wav_ctj29,
							wav_ctj30,wav_ctj31,wav_ctj32,wav_ctj33,wav_ctj34,wav_ctj35,wav_ctj36,wav_ctj37,wav_ctj38,wav_ctj39,
							wav_ctj40,wav_ctj41,wav_ctj42,wav_ctj43,wav_ctj44,wav_ctj45,wav_ctj46,wav_ctj47,wav_ctj48,wav_ctj49,
							wav_ctj50,wav_ctj51,wav_ctj52,wav_ctj53,wav_ctj54,wav_ctj55 };
#endif

// 音乐文件宏定义
#if 1
#define mp3_chun0 "res\\music\\SHEN\\「UndertaleHopes.mp3"
#define mp3_chun1 "res\\music\\SHEN\\DT.mp3"
#define mp3_chun2 "res\\music\\SHEN\\Fri-Strengthofwill.mp3"
#define mp3_chun3 "res\\music\\SHEN\\hith.mp3"
#define mp3_chun4 "res\\music\\SHEN\\Onemoretime萝卜子.mp3"
#define mp3_chun5 "res\\music\\SHEN\\UTHisTheme.mp3"
#define mp3_chun6 "res\\music\\SHEN\\Warmasp.mp3"
#define mp3_chun7 "res\\music\\SHEN\\第二碑半价.mp3"
#define mp3_chun8 "res\\music\\SHEN\\飞-致我们的星辰大海.mp3"
#define mp3_chun9 "res\\music\\SHEN\\风与约定【派蒙x荧】.mp3"

#define mp3_chun10 "res\\music\\SHEN\\胡桃[人生态度].mp3"
#define mp3_chun11 "res\\music\\SHEN\\骄傲的少年.mp3"
#define mp3_chun12 "res\\music\\SHEN\\决意.mp3"
#define mp3_chun13 "res\\music\\SHEN\\可莉[可].mp33"
#define mp3_chun14 "res\\music\\SHEN\\狂妄之人3D.mp3"
#define mp3_chun15 "res\\music\\SHEN\\萝卜子咳秋莎.mp3"
#define mp3_chun16 "res\\music\\SHEN\\若能化作星座[喜多中翻].mp3"
#define mp3_chun17 "res\\music\\SHEN\\为希望与梦想勾指起誓.mp3"
#define mp3_chun18 "res\\music\\SHEN\\小吉祥草[小城夏天].mp3"
#define mp3_chun19 "res\\music\\SHEN\\追梦赤子心.mp3"

#define mp3_chun20 "res\\music\\SHEN\\Miharu.mp3"

char* mp3_chun_class[21] = { mp3_chun0,mp3_chun1,mp3_chun2,mp3_chun3,mp3_chun4,mp3_chun5,mp3_chun6,mp3_chun7,mp3_chun8,mp3_chun9,
							mp3_chun10,mp3_chun11,mp3_chun12,mp3_chun13,mp3_chun14,mp3_chun15,mp3_chun16,mp3_chun17,mp3_chun18,mp3_chun19,
							mp3_chun20 };
#endif

//音乐播放类
#if 1
inline void rect_check(MCIERROR& ret) {  // 接受MCIERROR错误参数，根据是否为空决定是否在控制台里输入错误信息
	if (ret) {
		char err[100];
		mciGetErrorString(ret, err, sizeof(err));
		puts(err);		// 输出错误消息
	}
}

void music_play(const char* filename, const int volume = 50, const int seek = 0) {  // 播放音乐
	char path_opt[100];

	sprintf_s(path_opt, "open %s", filename);		// 打开音乐文件
	puts(path_opt);
	MCIERROR ret = mciSendString(path_opt, NULL, 0, NULL);
	rect_check(ret);

	if (0) {		// 调整音乐音量
		sprintf_s(path_opt, "setaudio %s volume to %d", filename, volume * 10);
		ret = mciSendString(path_opt, NULL, 0, NULL);
		rect_check(ret);
	}

	if (seek) {		// 调整音乐播放位置
		sprintf_s(path_opt, "seek %s to %d",filename,  seek);
		ret = mciSendString(path_opt, NULL, 0, NULL);
		rect_check(ret);
	}

	sprintf_s(path_opt, "play %s", filename);		// 播放音乐
	ret = mciSendString(path_opt, 0, 0, 0);
	rect_check(ret);
}

void music_repeat_check(const char* filename) {		// 循环播放音乐的判断，如果音乐已播放到末尾，重新从开头播放音乐
	char length[100],path_opt[100],now[100];

	sprintf_s(path_opt, "status %s length", filename);		// 记录音乐长度
	mciSendString(path_opt, length, 100, 0);

	sprintf_s(path_opt, "status %s position", filename);	// 记录音乐当前位置
	mciSendString(path_opt, now, 100, 0);

	if (atoi(now) >= atoi(length)) {		// 若播放到末尾，重新播放音乐
		sprintf_s(path_opt, "seek %s to 0", filename);
		mciSendString(path_opt, 0, 0, 0);
		sprintf_s(path_opt, "play %s", filename);
		mciSendString(path_opt, 0, 0, 0);
	}
}

void music_pause(const char* filename) {		// 暂停音乐
	char path_opt[100];

	sprintf_s(path_opt, "pause %s", filename);
	puts(path_opt);
	MCIERROR ret = mciSendString(path_opt, NULL, 0, NULL);
	rect_check(ret);
}

void music_resume(const char* filename) {	// 重新播放音乐
	char path_opt[100];

	sprintf_s(path_opt, "resume %s", filename);
	puts(path_opt);
	MCIERROR ret = mciSendString(path_opt, NULL, 0, NULL);
	rect_check(ret);
}

void music_close(const char* filename) {		// 关闭音乐文件
	char path_opt[100];

	sprintf_s(path_opt, "close %s", filename);
	puts(path_opt);
	MCIERROR ret = mciSendString(path_opt, NULL, 0, NULL);
	rect_check(ret);
}

int music_length(const char* filename) {		// 获取音乐长度
	char length[100], path_opt[100];

	sprintf_s(path_opt, "open %s", filename);
	mciSendString(path_opt, NULL, 0, NULL);

	sprintf_s(path_opt, "status %s length", filename);
	mciSendString(path_opt, length, 100, 0);

	sprintf_s(path_opt, "close %s", filename);
	mciSendString(path_opt, NULL, 0, NULL);

	return atoi(length);
}
#endif





#endif