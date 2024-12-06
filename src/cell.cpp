#include "light-csv_bits/cell.hpp"
#include "light-csv_bits/row.hpp"

bool contains_special_characters(const std::string& value)
{
    if (value.find_first_of(",\"") != std::string::npos) { return true; }
    return false;
}

std::string lcsv::csv_cell::csv_decode(const std::string& value)
{
    std::string result;
    if (value == "") // Empty string
    {
        return "";
    }
    if (contains_special_characters(value)) // Enclosed in quotes
    {
        result = value.substr(1, value.size() - 2);
    } else
    {
        return value;
    }

    // Replace double double quotes with single double quotes
    size_t pos = 0;
    while ((pos = result.find("\"\"", pos)) != std::string::npos)
    {
        result.replace(pos, 2, "\"");
        pos += 1;
    }
    return result;
}
std::string lcsv::csv_cell::csv_encode(const std::string& value)
{
    if (value == "") // Empty string
    {
        return "";
    }
    if (!contains_special_characters(value)) // No special characters
    {
        return value;
    }
    std::string result =  value;
    // Replace single double quotes with double double quotes
    size_t pos = 0;
    while ((pos = result.find("\"", pos)) != std::string::npos)
    {
        result.replace(pos, 1, "\"\"");
        pos += 2;
    }
    return "\"" + result + "\"";
}

lcsv::csv_cell::csv_cell() = default;

lcsv::csv_cell::csv_cell(const_reference value) :
    value(csv_decode(value))
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
    return csv_encode(this->value);
}

lcsv::csv_cell::operator std::string() const
{
    return this->value;
}

lcsv::csv_cell &lcsv::csv_cell::operator=(const_reference value)
{
    if (this->value != value) {
        this->value = value;
    }
    return *this;
}

lcsv::csv_cell &lcsv::csv_cell::operator=(const csv_cell &other)
{
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

bool lcsv::csv_cell::operator==(const_reference value) const
{
    return this->value == value;
}

bool lcsv::csv_cell::operator==(const csv_cell &other) const
{
    return this->value == other.value;
}
