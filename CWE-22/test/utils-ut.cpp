#include "tstat/utils.hpp"

#include <gtest/gtest.h>
#include <thread>
#include <ctime>
#include <sstream>

TEST(UtilsTest, ParseArgsShouldReturnVectorOfArgumentsFromString)
{
    std::string input{"start dancing writing_essays drinking"};
    std::vector<std::string> expectedOutput{"start",
                                            "dancing",
                                            "writing_essays",
                                            "drinking"};
    EXPECT_EQ(expectedOutput, utils::parseArgs(input));
}

TEST(UtilsTest, ParseArgsShouldReturnEmptyVectorWhenEmptyString)
{
    std::string input{""};
    std::vector<std::string> expectedOutput{};
    EXPECT_EQ(expectedOutput, utils::parseArgs(input));
}

TEST(UtilsTest, JoinShouldTakeVariadicNumberOfArguments)
{
    auto actualOutput = utils::join('/', "home", "wojtek", "networking");
    actualOutput = utils::join('/', "home");
    actualOutput = utils::join('/', "home", "wojtek");
    actualOutput = utils::join('/', "home", "wojtek", "networking", "donkey");
}

TEST(UtilsTest, JoinShouldNotAddCharacterAtTheEndOfTheString)
{
    std::string expectedOutput{"home/wojtek/networking"};
    auto actualOutput = utils::join('/', "home", "wojtek", "networking");
    EXPECT_EQ(expectedOutput, actualOutput);
}


TEST(UtilsTest, JoinShouldWorkWithManyCharacters)
{
    std::vector<char> characters{'?', '-', '_'};
    std::string expectedOutput1{"home?wojtek?networking"};
    std::string expectedOutput2{"bob-networking"};
    std::string expectedOutput3{"jack_heidel_fun_networking_work"};
    auto actualOutput1 = utils::join(characters[0], "home", "wojtek", "networking");
    auto actualOutput2 = utils::join(characters[1], "bob", "networking");
    auto actualOutput3 = utils::join(characters[2], "jack", "heidel", "fun", "networking", "work");
    EXPECT_EQ(expectedOutput1, actualOutput1);
    EXPECT_EQ(expectedOutput2, actualOutput2);
    EXPECT_EQ(expectedOutput3, actualOutput3);
}

TEST(UtilsTest, GetElapsedTimeShouldReturnElapsedTime)
{
    std::string expectedOutput{"00:00:02"};
    auto start = std::chrono::system_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto stop = std::chrono::system_clock::now();
    auto actualOutput = utils::getElapsedTime(stop, start);
    EXPECT_EQ(expectedOutput, actualOutput);
}

TEST(UtilsTest, GetCurrentDateShouldReturnDay_Month_Year)
{
    std::stringstream stream{};
    auto time = std::time(nullptr);
    //example: 26_04_2021
    stream << std::put_time(std::localtime(&time), "%d_%m_%Y");
    auto expectedOutput = stream.str();
    auto actualOutput = utils::getCurrentDate();
    EXPECT_EQ(expectedOutput, actualOutput);
}
