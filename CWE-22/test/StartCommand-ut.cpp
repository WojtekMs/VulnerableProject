#include "networking/IServer.hpp"
#include "tstat/CommandError.hpp"
#include "tstat/StartCommand.hpp"
#include "tstat/TimeCounter.hpp"

#include <gtest/gtest.h>

class MockServer : public networking::IServer
{
   public:
    void accept_connections() {}
    void send_data(const std::string&) const {}
    std::string receive_data() const { return {}; }
};

class StartCommandTest : public ::testing::Test
{
   protected:
    TimeCounter counter{};
    MockServer server{};
};

TEST_F(StartCommandTest, ShouldThrowCommandErrorWhenNoArgumentSupplied)
{
    std::vector<std::string> args{};
    EXPECT_THROW(StartCommand comm(counter, server, args), CommandError);
}

TEST_F(StartCommandTest, ShouldThrowCommandErrorWhenMoreArgumentsSupplied)
{
    std::vector<std::string> args{"writing", "dancing"};
    EXPECT_THROW(StartCommand comm(counter, server, args), CommandError);
}
