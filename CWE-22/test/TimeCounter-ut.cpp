#include "tstat/TimeCounter.hpp"
#include "tstat/config.hpp"
#include "tstat/utils.hpp"

#include <gtest/gtest.h>
#include <thread>

class TimeCounterTest : public ::testing::Test {
    protected:
    TimeCounter counter{};
};

TEST_F(TimeCounterTest, GetElapsedTimeShouldReturnElapsedTime)
{
    std::string expectedElapsedTime{"00:00:02"};
    counter.start("bob");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    counter.stop();
    EXPECT_EQ(expectedElapsedTime, counter.getElapsedTime());
}

TEST_F(TimeCounterTest, GetElapsedTimeShouldReturn_00_00_00_WhenIdle)
{
    std::string expectedElapsedTime{"00:00:00"};
    EXPECT_EQ(expectedElapsedTime, counter.getElapsedTime());
}

TEST_F(TimeCounterTest, GetFilePathShouldReturnLogSavePathAndTaskNameWhenCounting)
{
    using namespace std::string_literals;
    std::string taskName{"dancing"};
    std::string expectedFilePath{config::log_save_path + "/"s + taskName + "/"s + utils::getCurrentDate()};
    counter.start(taskName);
    EXPECT_EQ(expectedFilePath, counter.getFilePath());
}

TEST_F(TimeCounterTest, GetFilePathShouldReturnEmptyStringWhenCounterIsIdle)
{
    std::string expectedFilePath{};
    EXPECT_EQ(expectedFilePath, counter.getFilePath());
}
