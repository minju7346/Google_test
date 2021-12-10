#include "gtest/gtest.h"
#include "pch.h"
#include "../DWS_Error/AlarmControl.c"
class CheckAlarmTestSuite : public testing::Test { //201912343  ������
protected:
	void SetUp() {
		m.M_TS = 0;
		m.M_ALS = 0;
		m.ALARM_INDI_ON = 1;
		t.second = 0;
		t.centisecond = 0;
	}
	void TearDown() {}

	ALARM r;
	MODE m;
	TIME t;
};

TEST_F(CheckAlarmTestSuite, CheckAlarmTest1) { //201912343 ������

	r.month = 0;
	r.day = 0;
	t.hour = 1;
	r.hour = 1; //r.hour == t.hour��� �����Ͽ� �Ҵ�
	t.minute = 2;
	r.minute = 2; //r.minute == t.minute��� �����Ͽ� �Ҵ�

	CheckAlarm(&r, &m, &t);

	EXPECT_EQ(r.CHECK_ALARM, 1);
	EXPECT_TRUE(true);
}

TEST_F(CheckAlarmTestSuite, CheckAlarmTest2) { //201912343 ������

	r.month = 0;
	t.day = 1;
	r.day = 1; //r.day == t.day��� �����Ͽ� �Ҵ�
	t.hour = 2;
	r.hour = 2; //r.hour == t.hour��� �����Ͽ� �Ҵ�
	t.minute = 3;
	r.minute = 3; //r.minute == t.minute��� �����Ͽ� �Ҵ�

	CheckAlarm(&r, &m, &t);

	EXPECT_EQ(r.CHECK_ALARM, 1);
	EXPECT_TRUE(true);
}
TEST_F(CheckAlarmTestSuite, CheckAlarmTest3) { //201912343 ������

	t.month = 1;
	r.month = 1; //r.month == t.month��� �����Ͽ� �Ҵ�
	r.day = 0;
	t.hour = 2;
	r.hour = 2; //r.hour == t.hour��� �����Ͽ� �Ҵ�
	t.minute = 3;
	r.minute = 3; //r.minute == t.minute��� �����Ͽ� �Ҵ�

	CheckAlarm(&r, &m, &t);

	EXPECT_EQ(r.CHECK_ALARM, 1);
	EXPECT_TRUE(true);
}
TEST_F(CheckAlarmTestSuite, CheckAlarmTest4) { //201912343 ������

	t.month = 1;
	r.month = 1; //r.month == t.month��� �����Ͽ� �Ҵ�
	t.day = 2;
	r.day = 2; //r.day == t.day��� �����Ͽ� �Ҵ�
	t.hour = 3;
	r.hour = 3; //r.hour == t.hour��� �����Ͽ� �Ҵ�
	t.minute = 4;
	r.minute = 4; //r.minute == t.minute��� �����Ͽ� �Ҵ�

	CheckAlarm(&r, &m, &t);

	EXPECT_EQ(r.CHECK_ALARM, 1);
	EXPECT_TRUE(true);
}

int main(int argc, char** argv) { //201912343 ������
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}