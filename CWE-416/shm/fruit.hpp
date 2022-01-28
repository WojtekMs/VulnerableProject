#pragma once
#include "cargo.hpp"

// Class responsible for fruit representing in game

class Fruit : public Cargo
{
public:
    Fruit(const std::string &name, size_t amount, size_t basePrice, Time *time, size_t expiry_date, size_t time_elapsed);
    virtual ~Fruit() override;

    // override from Cargo
    size_t getPrice() const override;
    const std::string &getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

    Cargo* clone() override;
    Cargo &operator+=(size_t) override;
    Cargo &operator-=(size_t) override;
    bool operator==(const Cargo &) const override;
    
    size_t getTimeElapsed() const { return time_elapsed_; }
    size_t getExpiryDate() const { return expiry_date_; }

    void nextDay(size_t) override;

protected:
    size_t time_elapsed_{0};
    size_t expiry_date_;
};