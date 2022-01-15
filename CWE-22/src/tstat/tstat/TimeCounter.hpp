#pragma once

#include "tstat/IdleState.hpp"

#include <chrono>
#include <memory>

class IState;

namespace networking
{
class IServer;
}
class TimeCounter
{
    std::chrono::time_point<std::chrono::system_clock> start_{};
    std::chrono::time_point<std::chrono::system_clock> stop_{};
    std::string task_name_{};
    std::unique_ptr<IState> counter_state_{std::make_unique<IdleState>(*this)};

    friend class IdleState;
    friend class CountingState;
    friend class StoppedState;

    void reset() noexcept;
   public:
    TimeCounter() = default;
    void start(const std::string& task_name);
    void stop();
    void abort();
    void save();
    std::string getElapsedTime() const;
    std::string getFilePath() const;
    std::string getCurrentStateInfo() const noexcept;
};
