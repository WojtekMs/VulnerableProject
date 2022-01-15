#include "tstat/ArgParser.hpp"

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

TEST(ArgParserTest, ShouldThrowInvalidArgumentWhenNoCommandGiven)
{
    std::string input{"no command given"};
    EXPECT_THROW(ArgParser parser(input), std::invalid_argument);
}

TEST(ArgParserTest, ShouldThrowLogicErrorWhenEmptyInput)
{
    std::string input{""};
    EXPECT_THROW(ArgParser parser(input), std::logic_error);
}

TEST(ArgParserTest, ShouldThrowInvalidArgumentWhenNoCommandGivenCLI)
{
    char* argv[] = {const_cast<char*>("program_name"),
                    const_cast<char*>("no"),
                    const_cast<char*>("command"),
                    const_cast<char*>("given")};
    int argc = 4;
    EXPECT_THROW(ArgParser parser(argv, argc), std::invalid_argument);
}

TEST(ArgParserTest, ShouldThrowLogicErrorWhenEmptyInputCLI)
{
    char* argv[] = {const_cast<char*>("program_name")};
    int argc = 1;
    EXPECT_THROW(ArgParser parser(argv, argc), std::logic_error);
}

TEST(ArgParserTest, ShouldParseArgs)
{
    std::string input{"start writing_essays"};
    std::string expectedCommand{"start"};
    std::vector<std::string> expectedCommandArgs{"writing_essays"};
    std::string expectedArgsAsString{"start writing_essays "};
    ArgParser args(input);
    EXPECT_EQ(expectedCommand, args.getCommand());
    EXPECT_EQ(expectedCommandArgs, args.getCommandArgs());
    EXPECT_EQ(expectedArgsAsString, args.getArgsAsString());
}

TEST(ArgParserTest, ShouldParseArgsCLI)
{
    char* argv[] = {const_cast<char*>("program_name"),
                    const_cast<char*>("start"),
                    const_cast<char*>("writing_essays")};
    int argc = 3;
    std::string expectedCommand{"start"};
    std::vector<std::string> expectedCommandArgs{"writing_essays"};
    std::string expectedArgsAsString{"start writing_essays "};
    ArgParser args(argv, argc);
    EXPECT_EQ(expectedCommand, args.getCommand());
    EXPECT_EQ(expectedCommandArgs, args.getCommandArgs());
    EXPECT_EQ(expectedArgsAsString, args.getArgsAsString());
}

TEST(ArgParserTest, CommandArgsShouldBeEmptyWhenOnlyCommandIsGiven)
{
    std::string input{"start"};
    std::string expectedCommand{"start"};
    std::vector<std::string> expectedCommandArgs{};
    std::string expectedArgsAsString{"start "};
    ArgParser args(input);
    EXPECT_EQ(expectedCommand, args.getCommand());
    EXPECT_EQ(expectedCommandArgs, args.getCommandArgs());
    EXPECT_EQ(expectedArgsAsString, args.getArgsAsString());
}
