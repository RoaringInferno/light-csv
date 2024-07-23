#include "light-csv/cell.hpp"
#include "row.hpp"
#include "cell.hpp"

lcsv::cell::cell() :
    value("")
{
}

lcsv::cell::cell(const_reference value) :
    value(value)
{
}

lcsv::cell::cell(const cell &other) = default;

lcsv::cell::~cell()
{
}

std::string lcsv::cell::get_value() const
{
    return this->value;
}

void lcsv::cell::set_value(const_reference value)
{
    this->value = value;
}

lcsv::cell::pointer lcsv::cell::data()
{
    return &this->value;
}

bool lcsv::cell::is_empty() const
{
    return this->value != "";
}

std::string lcsv::cell::to_string() const
{
    return this->value;
}

lcsv::cell::operator std::string() const
{
    return this->value;
}

lcsv::cell &lcsv::cell::operator=(const cell &other)
{
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

bool lcsv::cell::operator==(const cell &other) const
{
    return this->value == other.value;
}
