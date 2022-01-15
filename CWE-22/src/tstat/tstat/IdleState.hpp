#pragma once

#include "tstat/IState.hpp"

class TimeCounter;

class IdleState : public IState
{
    TimeCounter& counter_;

   public:
    IdleState() = delete;
    explicit IdleState(TimeCounter&);
    void start(const std::string&) override;
    void stop() override;
    void abort() override;
    void save() override;
    std::string getElapsedTime() const override;
    std::string getFilePath() const override;
    std::string getCurrentStateInfo() const noexcept override;
};
