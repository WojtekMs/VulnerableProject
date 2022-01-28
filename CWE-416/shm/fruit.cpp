#include <iostream>
#include "fruit.hpp"

Fruit::Fruit(const std::string &name, size_t amount, size_t basePrice, Time *time, size_t expiry_date, size_t time_elapsed)
    : Cargo(name, amount, basePrice, time), time_elapsed_(time_elapsed), expiry_date_(expiry_date)
{}

Fruit::~Fruit()
{
    // this->time_.detach(this);
}

size_t Fruit::getPrice() const
{
    return static_cast<size_t>(basePrice_ * ((size_t)(expiry_date_ - time_elapsed_)) / expiry_date_);
}

Cargo &Fruit::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}

Cargo &Fruit::operator-=(size_t amount)
{
    if (amount_ < amount)
    {
        amount_ = 0;
    }
    else
    {
        amount_ -= amount;
    }
    return *this;
}

bool Fruit::operator==(const Cargo &other) const
{
    try
    {
        const Fruit &other_fruit = dynamic_cast<const Fruit &>(other);
        return Cargo::operator==(other) && expiry_date_ == other_fruit.expiry_date_;
    }
    catch (std::bad_cast &)
    {
        return false;
    }
}

void Fruit::nextDay(size_t elapsedTime)
{
    time_elapsed_ += elapsedTime;
    if (time_elapsed_ >= expiry_date_)
    {
        basePrice_ = 0;
    }
}

Cargo *Fruit::clone()
{
    return new Fruit(*this);
}