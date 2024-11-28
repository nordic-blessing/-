#pragma once
#include "common.h"
//===============================================================================================
// 名称：播放音乐
// 作者：nordic-blessing
// 时间：2023/12/6/0:56am
// 主要功能：播放指定音乐
// 格式：
// 		musicplay("music/音乐名字.mp3", 是否重复播放(true/false), 音量, 是否停止播放);
//===============================================================================================
void musicplay(const char* music, bool isRepeat, int volume = -1, bool stop = false)
{
    char cmd[100] = ""; // 用于存储命令字符串的缓冲区
    // 使用 sprintf 将打开音乐的命令字符串格式化并存储到 cmd 缓冲区中
    sprintf_s(cmd, "open %s alias bgm%s", music, music);
    mciSendString(cmd, NULL, 0, NULL); // 调用 mciSendString 函数执行命令
    // 使用 sprintf 将播放音乐的命令字符串格式化并存储到 cmd 缓冲区中
    sprintf_s(cmd, "play bgm%s %s", music, isRepeat ? "repeat" : " ");
    mciSendString(cmd, NULL, 0, NULL); // 调用 mciSendString 函数执行命令
    if (volume != -1)
    {
         // 使用 sprintf 将设置音量的命令字符串格式化并存储到 cmd 缓冲区中
        sprintf_s(cmd, "setaudio bgm%s volume to %d", music, volume);
         mciSendString(cmd, NULL, 0, NULL); // 调用 mciSendString 函数执行命令
    }
    if (stop == true)
    {
        // 使用 sprintf 将播放音乐的命令字符串格式化并存储到 cmd 缓冲区中
        sprintf_s(cmd, "stop bgm%s", music);
        mciSendString(cmd, NULL, 0, NULL); // 调用 mciSendString 函数执行命令
    }
}