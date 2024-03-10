
#include "ari/buffer.h"

#include "gtest/gtest.h"

TEST(BufferTest, BufferSetTest) {
    std::string data = "hello,world";
    ari::Buffer buffer(data.size(), data.c_str());
    std::string bufferString = buffer.Raw();
    EXPECT_EQ(data, bufferString);
}

TEST(BufferTest, BufferAppendTest) {
    std::string data = "hello,world";
    ari::Buffer buffer;
    EXPECT_EQ(true, buffer.Append(data.size(), data.c_str()));
    std::string bufferString = buffer.Raw();
    EXPECT_EQ(data, bufferString);
    std::string data2 = "!!!";
    EXPECT_EQ(true, buffer.Append(data2.size(), data2.c_str()));
    bufferString = buffer.Raw();
    EXPECT_EQ(data.append(data2), bufferString);
}