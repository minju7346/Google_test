/*Functions.h*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Data.h"

///////////버튼///////////// - ETC.c
void ButtonIdentification(char button[], int button_info[]);

////////////초기화 관련 함수///////////////// - ETC.c
void InitSwitchSection(MODE *md);
void Initialize(TIME *t, STOPWATCH *st, MODE *md, ALARM *r);
void InitALSwitchSection(MODE *md);   //in etc.c

///////////화면출력 관련함수///////////////// - ETC.c
void gotoxy(int x, int y);
void PrintWatchCase(void);
void RemoveLine(void);
void SetColor(int colFront, int colBack);
void setcursortype(int cur_t);
//////////////////////////////////////

////////////////////////////////////////////////////
/////////////디스플레이 컨트롤러 관련 함수////////////
///////////////////////////////////////////////////
void DisplayControl(TIME *t, STOPWATCH *st, MODE *md, int button_info, ALARM *r);

int leapYear(int i);
int calwday(int year, int month, int day);
void IncreaseCurrentTime(TIME *a);///////////////////////////////////////여기까진 놉

void DisplayCurrentTime(TIME *time,MODE *mode);
void PrintWatchNum(char *s1,char *s2,char *s3,char *s4,char *s5,char *s6,char *s7,char *s8, int indi);

void DisplaySetting(TIME *time,MODE *mode);;//----------------------------------------X
void PrintSettingNum(char *s1,char *s2,char *s3,char *s4,char *s5,char *s6,char *s7,char *s8,MODE *mode, int indi);

void SwitchSection(MODE *md);//------------------------------------------------------detect!!!!!!!!!!!!!!!!!!!!!!

void IncreaseValue(MODE *m, TIME *t);//----------------------------------------X

void DisplayStopwatch(TIME *time,STOPWATCH *stopwatch,MODE *mode);//----------------------------------------X
void PrintStopWatch(char *s1,char *s2,char *s3,char *s4,char *s5,char *s6,char *s7,char *s8,MODE *mode, int indi);//----------------------------------------X

void RunStopwatch(STOPWATCH *sw);//----------------------------------------X

void RecordLapTime(STOPWATCH *sw, MODE *md);//----------------------------------------X

void StopwatchReset(STOPWATCH *sw); //------------------------------------------------------detect!!!!!!!!!!!!!!!!!!!!!!

void LapTimeReset(STOPWATCH *sw, MODE *md);//-----------------------------------------------detect!!!!!!!!!!!!!!!!!!!!!!



void PrintAlarm(char *s1,char *s2,char *s3,char *s4,char *s5,char *s6,int indi);//----------------------------------------X
void DisplayAlarm(ALARM *r, MODE *mode);//--------------------------------------------------detect!!!!!!!!!!!!!!!!!!!!!!

void PrintAlarmSet(char *s1,char *s2,char *s3,char *s4,char *s5,char *s6, MODE *mode, int indi);//----------------------------------------X
void DisplayAlarmSetting(ALARM *r, MODE *mode);//----------------------------------------------------X

void SwitchSectionAlarm(MODE *m);//--------------------------------------------------detect!!!!!!!!!!!!!!!!!!!!!!
void IncreaseAlarmValue(ALARM *r, MODE *m);//--------------------------------------- detect!!!!!!!!!!!!!!!!!!!!!!
void AlarmIndicator(MODE *m);//--------------------------------------------------detect!!!!!!!!!!!!!!!!!!!!!!
///////////////////////////////////////////////
////////////////////////////////////


////////////////////////////light 컨트롤러////////////////////////
//////////////////////////////////////////////////////
void TurnOnTheLight(MODE *md);//----------------------------------------X
void TurnOffTheLight(MODE *md);//----------------------------------------X
void LightControl(int Button, MODE * md, ALARM *r);//--------------------------------------detect!!!!!!!!!!!!!!!!!!!!!!


//////////////alarm controller//////////////////////////////
void CheckAlarm(ALARM *r, MODE *m, TIME *t);//---------------------------------------------detect!!!!!!!!!!!!!!!!!!!!!!
void AlarmOff(ALARM *r);//----------------------------------------X
void Bell();//----------------------------------------X
void AlarmControl (ALARM *r,MODE *m, TIME *t, int buttoninfo1, int buttoninfo2);//----------------------------------------X
/////////////////////////////////////////////////
#endif
