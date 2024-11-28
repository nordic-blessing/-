#pragma once
#include "common.h"
//===============================================================================================
// ���ƣ���������
// ���ߣ�nordic-blessing
// ʱ�䣺2023/12/6/0:56am
// ��Ҫ���ܣ�����ָ������
// ��ʽ��
// 		musicplay("music/��������.mp3", �Ƿ��ظ�����(true/false), ����, �Ƿ�ֹͣ����);
//===============================================================================================
void musicplay(const char* music, bool isRepeat, int volume = -1, bool stop = false)
{
    char cmd[100] = ""; // ���ڴ洢�����ַ����Ļ�����
    // ʹ�� sprintf �������ֵ������ַ�����ʽ�����洢�� cmd ��������
    sprintf_s(cmd, "open %s alias bgm%s", music, music);
    mciSendString(cmd, NULL, 0, NULL); // ���� mciSendString ����ִ������
    // ʹ�� sprintf ���������ֵ������ַ�����ʽ�����洢�� cmd ��������
    sprintf_s(cmd, "play bgm%s %s", music, isRepeat ? "repeat" : " ");
    mciSendString(cmd, NULL, 0, NULL); // ���� mciSendString ����ִ������
    if (volume != -1)
    {
         // ʹ�� sprintf �����������������ַ�����ʽ�����洢�� cmd ��������
        sprintf_s(cmd, "setaudio bgm%s volume to %d", music, volume);
         mciSendString(cmd, NULL, 0, NULL); // ���� mciSendString ����ִ������
    }
    if (stop == true)
    {
        // ʹ�� sprintf ���������ֵ������ַ�����ʽ�����洢�� cmd ��������
        sprintf_s(cmd, "stop bgm%s", music);
        mciSendString(cmd, NULL, 0, NULL); // ���� mciSendString ����ִ������
    }
}