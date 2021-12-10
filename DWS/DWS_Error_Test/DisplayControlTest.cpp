#include "gtest/gtest.h"
#include "pch.h"
#include "../DWS_Error/DisplayControl.c"
#include "../DWS_Error/ETC.c"

static ALARM r;
static STOPWATCH sw;
static MODE md;
static TIME a;

TEST(StopwatchResetTestSuite, StopwatchResetTest) { //201912343 離團輿
	sw.C_second = 1;
	sw.second = 1;
	sw.minute = 1;
	StopwatchReset(&sw);
	EXPECT_EQ(sw.C_second, 0);
	EXPECT_EQ(sw.second, 0);
	EXPECT_EQ(sw.minute, 0);
	EXPECT_TRUE(true);
}
TEST(LapTimeResetTestSuite, LapTimeResetTest) { //201912343 離團輿
	sw.Lap_Cse = 1;
	sw.Lap_min = 1;
	sw.Lap_se = 1;
	md.LAP_ON = 1;
	LapTimeReset(&sw, &md);
	EXPECT_EQ(sw.Lap_min, 0);
	EXPECT_EQ(sw.Lap_se, 0);
	EXPECT_EQ(sw.Lap_Cse, 0);
	EXPECT_EQ(md.LAP_ON, 0);
	EXPECT_TRUE(true);
}

TEST(InitALSwitchSectionTestSuite, InitALSwitchSectionTest) { //201912343 離團輿
	md.AL_day = 2;
	md.AL_hour = 2;
	md.AL_minute = 2;
	md.AL_month = 2;
	md.M_ALS = 1;
	DisplayAlarm(&r, &md);
	EXPECT_EQ(md.AL_day, 0);
	EXPECT_EQ(md.AL_hour, 1);
	EXPECT_EQ(md.AL_minute, 0);
	EXPECT_EQ(md.AL_month, 0);
	EXPECT_EQ(md.M_ALS, 0);
	EXPECT_TRUE(true);
}
TEST(SwitchSectionAlarmTestSuite, SwitchSectionAlarmTest) { //201912343 離團輿
	md.AL_hour = 1;
	md.AL_minute = 0;
	md.AL_month = 0;
	md.AL_day = 0;
	SwitchSectionAlarm(&md);
	EXPECT_EQ(md.AL_minute, 1);
	SwitchSectionAlarm(&md);
	EXPECT_EQ(md.AL_month, 1);
	SwitchSectionAlarm(&md);
	EXPECT_EQ(md.AL_day, 1);
	SwitchSectionAlarm(&md);
	EXPECT_EQ(md.AL_hour, 1);
	EXPECT_TRUE(true);
}
TEST(AlarmIndicatorTestSuite, AlarmIndicatorTest1) { //201912343 離團輿
	md.ALARM_INDI_ON = 0;
	AlarmIndicator(&md);
	EXPECT_EQ(md.ALARM_INDI_ON, 1);
	EXPECT_TRUE(true);
}
TEST(AlarmIndicatorTestSuite, AlarmIndicatorTest2) { //201912343 離團輿
	md.ALARM_INDI_ON = 1;
	AlarmIndicator(&md);
	EXPECT_EQ(md.ALARM_INDI_ON, 0);
	EXPECT_TRUE(true);
}

TEST(IncreaseAlarmValueTestSuite, IncreaseAlarmValueTest1) { //201912343 離團輿
	r.hour = 23;
	md.AL_hour = 1;
	IncreaseAlarmValue(&r, &md);
	EXPECT_EQ(r.hour, 0);
	EXPECT_TRUE(true);
}
TEST(IncreaseAlarmValueTestSuite, IncreaseAlarmValueTest2) { //201912343 離團輿
	r.minute = 59;
	md.AL_hour = 0;
	md.AL_minute = 1;
	IncreaseAlarmValue(&r, &md);
	EXPECT_EQ(r.minute, 0);
	EXPECT_TRUE(true);
}
TEST(IncreaseAlarmValueTestSuite, IncreaseAlarmValueTest3) { //201912343 離團輿
	r.month = 12;
	md.AL_month = 1;
	md.AL_hour = 0;
	md.AL_minute = 0;
	IncreaseAlarmValue(&r, &md);
	EXPECT_EQ(r.month, 1);
	EXPECT_TRUE(true);
}
TEST(IncreaseAlarmValueTestSuite, IncreaseAlarmValueTest4) { //201912343 離團輿
	r.month = 1;
	r.day = 31;
	md.AL_day = 1;
	md.AL_month = 0;
	md.AL_hour = 0;
	md.AL_minute = 0;
	IncreaseAlarmValue(&r, &md);
	EXPECT_EQ(r.day, 1);
	r.month = 4;
	r.day = 30;
	IncreaseAlarmValue(&r, &md);
	EXPECT_EQ(r.day, 1);
	r.month = 2;
	r.day = 29;
	IncreaseAlarmValue(&r, &md);
	EXPECT_EQ(r.day, 1);
	EXPECT_TRUE(true);
}
TEST(SwitchSectionTestSuite, SwitchSectionTest) { //201912343 離團輿
	md.TS_second = 1;
	md.TS_hour = 0;
	md.TS_minute = 0;
	md.TS_year = 0;
	md.TS_month = 0;
	md.TS_day = 0;
	SwitchSection(&md);
	EXPECT_EQ(md.TS_hour, 1);
	SwitchSection(&md);
	EXPECT_EQ(md.TS_minute, 1);
	SwitchSection(&md);
	EXPECT_EQ(md.TS_year, 1);
	SwitchSection(&md);
	EXPECT_EQ(md.TS_month, 1);
	SwitchSection(&md);
	EXPECT_EQ(md.TS_day, 1);
	SwitchSection(&md);
	EXPECT_EQ(md.TS_second, 1);
	EXPECT_TRUE(true);
}
TEST(IncreaseCurrentTimeTestSuite, IncreaseCurrentTimeTest1) { //201912343 離團輿
	a.centisecond = 99;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.centisecond, 0);
	a.centisecond = 99;
	a.second = 59;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.second, 0);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.minute, 0);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 23;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.hour, 0);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 23;
	a.wday = 6;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.wday, 0);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 23;
	a.day = 31;
	a.month = 1;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.day, 1);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 23;
	a.day = 31;
	a.month = 1;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.day, 1);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 23;
	a.day = 30;
	a.month = 4;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.day, 1);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 23;
	a.day = 28;
	a.month = 2;
	a.year = 2015;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.day, 1);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 23;
	a.day = 31;
	a.month = 12;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.month, 1);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 23;
	a.day = 31;
	a.month = 12;
	a.year = 2099;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.year, 2012);
	EXPECT_TRUE(true);
}
TEST(IncreaseCurrentTimeTestSuite, IncreaseCurrentTimeTest2) { //201912343 離團輿
	a.centisecond = 99;
	a.second = 0;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.second, 1);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 0;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.minute, 1);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 0;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.hour, 1);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 23;
	a.wday = 0;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.wday, 1);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 23;
	a.day = 1;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.day, 2);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 23;
	a.day = 31;
	a.month = 1;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.month, 2);
	a.centisecond = 99;
	a.second = 59;
	a.minute = 59;
	a.hour = 23;
	a.day = 31;
	a.month = 12;
	a.year = 2012;
	IncreaseCurrentTime(&a);
	EXPECT_EQ(a.year, 2013);
	EXPECT_TRUE(true);
}
int main(int argc, char** argv) { //201912343 離團輿
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}