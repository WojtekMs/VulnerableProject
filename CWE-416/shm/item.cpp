#include "item.hpp"
#include "Time.hpp"

Item::Item(const std::string &name, size_t amount, size_t basePrice, Time *time, Rarity rarity)
    : Cargo(name, amount, basePrice, time), rarity_(rarity)
{
}

size_t Item::getPrice() const
{
    return basePrice_ * static_cast<int>(rarity_);
}

Cargo &Item::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}

Cargo &Item::operator-=(size_t amount)
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

bool Item::operator==(const Cargo &other) const
{

    try
    {
        const Item &other_item = dynamic_cast<const Item &>(other);
        return Cargo::operator==(other) && rarity_ == other_item.rarity_;
    }
    catch (std::bad_cast &)
    {
        return false;
    }
}

void Item::nextDay(size_t elapsedTime)
{
    basePrice_ += elapsedTime;
}
Cargo *Item::clone()
{
    return new Item(*this);
}