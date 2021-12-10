#include "gtest/gtest.h"
#include "pch.h"
#include "../DWS_Error/LightControl.c"
#include "../DWS_Error/ETC.c"

static ALARM r;
static MODE md;
static l_state state;

TEST(LightControlTestSuite, LightOnTest) { //201912343 Â÷¹ÎÁÖ

	state = LIGHT_OFF;
	int button_info = 4;
	r.CHECK_ALARM = 0;
	LightControl(button_info, &md, &r);
	EXPECT_EQ(md.LIGHT_STATE, 1);
	EXPECT_TRUE(true);
}

TEST(LightControlTestSuite, LightOffTest) { //201912343 Â÷¹ÎÁÖ

	state = LIGHT_ON;
	int button_info = 0; //button_info != 4
	LightControl(button_info, &md, &r);
	for (int i = 0; i < 100000000; i++) {} // 2ÃÊ ÀÌ»óÀÇ µô·¹ÀÌ
	EXPECT_EQ(md.LIGHT_STATE, 0);
	EXPECT_TRUE(true);
}

int main(int argc, char** argv) { //201912343 Â÷¹ÎÁÖ
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}