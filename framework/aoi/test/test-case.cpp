#include "gtest/gtest.h"
#include "aoi/aoi.h"
#include "config_generated/ari.pb.h"

class AOITest : public testing::Test {
protected:
    void SetUp() override {
        a = 0;
    }

    int a;
};

TEST_F(AOITest, SetUp) {
    EXPECT_EQ(a, 0);
}

TEST_F(AOITest, Initialize) {
    bool result = aoi::AOI::GetInstance()->Initialize();
    EXPECT_EQ(result, true);
}