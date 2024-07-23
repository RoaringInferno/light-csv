#include "light-csv/cell.hpp"
#include "light-csv/row.hpp"

lcsv::csv_cell::csv_cell() :
    value("")
{
}

lcsv::csv_cell::csv_cell(const_reference value) :
    value(value)
{
}

lcsv::csv_cell::csv_cell(const csv_cell &other) = default;

lcsv::csv_cell::~csv_cell()
{
}

std::string lcsv::csv_cell::get_value() const
{
    return this->value;
}

void lcsv::csv_cell::set_value(const_reference value)
{
    this->value = value;
}

lcsv::csv_cell::pointer lcsv::csv_cell::data()
{
    return &this->value;
}

bool lcsv::csv_cell::is_empty() const
{
    return this->value != "";
}

std::string lcsv::csv_cell::to_string() const
{
    return this->value;
}

lcsv::csv_cell::operator std::string() const
{
    return this->value;
}

lcsv::csv_cell &lcsv::csv_cell::operator=(const csv_cell &other)
{
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

bool lcsv::csv_cell::operator==(const csv_cell &other) const
{
    return this->value == other.value;
}
