#include "gtest/gtest.h"
#include "aoi/aoi.h"
#include "config_generated/ari.pb.h"

class AOITest : public testing::Test {
protected:
    void SetUp() override {
        result = aoi::AOI::GetInstance()->Initialize();
    }

    bool result;
};

TEST_F(AOITest, SetUp) {
    EXPECT_EQ(result, true);
}

TEST_F(AOITest, Initialize) {
    bool result = aoi::AOI::GetInstance()->Initialize();
    EXPECT_EQ(result, true);
}