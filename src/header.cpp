#include "light-csv_bits/header.hpp"
#include "light-csv_bits/cell.hpp"
#include "internal/csv-line-reader.hpp"

lcsv::csv_header::csv_header() :
    column_names()
{
}

#include <iostream>

lcsv::csv_header::csv_header(const std::string &header_line) :
    column_names()
{
    lcsv::csv_line_reader reader(header_line);
    do {
        this->column_names.push_back(lcsv::csv_cell::csv_decode(reader.read_cell()));
        if (reader.right_separator_position() == reader.end()) { break; }
        reader.advance();
    } while (true);
}

lcsv::csv_header::csv_header(const vector &column_names) :
    column_names(column_names)
{
}

lcsv::csv_header::csv_header(const csv_header &other) :
    column_names(other.column_names)
{
}

lcsv::csv_header::~csv_header()
{
}

std::string lcsv::csv_header::to_string() const
{
    std::string result = "";
    for (const std::string &col : this->column_names) {
        result += col + ",";
    }
    result.pop_back();
    return result;
}

lcsv::csv_header::operator std::string() const
{
    return this->to_string();
}

lcsv::csv_header::reference lcsv::csv_header::at(const lcsv::csv_header::size_type index)
{
    return this->column_names.at(index);
}

lcsv::csv_header::reference lcsv::csv_header::operator[](const lcsv::csv_header::size_type index)
{
    return this->column_names[index];
}

lcsv::csv_header::reference lcsv::csv_header::front()
{
    return this->column_names.front();
}

lcsv::csv_header::reference lcsv::csv_header::back()
{
    return this->column_names.back();
}

lcsv::csv_header::pointer lcsv::csv_header::data()
{
    return this->column_names.data();
}

lcsv::csv_header::const_reference lcsv::csv_header::at(const lcsv::csv_header::size_type index) const
{
    return this->column_names.at(index);
}

lcsv::csv_header::const_reference lcsv::csv_header::operator[](const lcsv::csv_header::size_type index) const
{
    return this->column_names[index];
}

lcsv::csv_header::const_reference lcsv::csv_header::front() const
{
    return this->column_names.front();
}

lcsv::csv_header::const_reference lcsv::csv_header::back() const
{
    return this->column_names.back();
}

lcsv::csv_header::const_pointer lcsv::csv_header::data() const
{
    return this->column_names.data();
}

bool lcsv::csv_header::empty() const
{
    return this->column_names.empty();
}

lcsv::csv_header::size_type lcsv::csv_header::size() const
{
    return this->column_names.size();
}

lcsv::csv_header::size_type lcsv::csv_header::max_size() const
{
    return this->column_names.max_size();
}

void lcsv::csv_header::reserve(const lcsv::csv_header::size_type new_capacity)
{
    this->column_names.reserve(new_capacity);
}

lcsv::csv_header::size_type lcsv::csv_header::capacity() const
{
    return this->column_names.capacity();
}

void lcsv::csv_header::shrink_to_fit()
{
    this->column_names.shrink_to_fit();
}

void lcsv::csv_header::clear()
{
    this->column_names.clear();
}

lcsv::csv_header::iterator lcsv::csv_header::insert(lcsv::csv_header::const_iterator position, lcsv::csv_header::const_reference value)
{
    return this->column_names.insert(position, value);
}

lcsv::csv_header::iterator lcsv::csv_header::insert(lcsv::csv_header::const_iterator position, const vector &values)
{
    return this->column_names.insert(position, values.begin(), values.end());
}

lcsv::csv_header::iterator lcsv::csv_header::erase(lcsv::csv_header::const_iterator position)
{
    return this->column_names.erase(position);
}

lcsv::csv_header::iterator lcsv::csv_header::erase(lcsv::csv_header::const_iterator first, lcsv::csv_header::const_iterator last)
{
    return this->column_names.erase(first, last);
}

void lcsv::csv_header::push_back(lcsv::csv_header::const_reference value)
{
    this->column_names.push_back(value);
}

void lcsv::csv_header::pop_back()
{
    this->column_names.pop_back();
}

void lcsv::csv_header::resize(const lcsv::csv_header::size_type new_size)
{
    this->column_names.resize(new_size);
}

void lcsv::csv_header::resize(const lcsv::csv_header::size_type new_size, lcsv::csv_header::const_reference value)
{
    this->column_names.resize(new_size, value);
}

void lcsv::csv_header::swap(csv_header &other)
{
    this->column_names.swap(other.column_names);
}

lcsv::csv_header::iterator lcsv::csv_header::begin()
{
    return this->column_names.begin();
}

lcsv::csv_header::iterator lcsv::csv_header::end()
{
    return this->column_names.end();
}

lcsv::csv_header::const_iterator lcsv::csv_header::cbegin()
{
    return this->column_names.cbegin();
}

lcsv::csv_header::const_iterator lcsv::csv_header::cend()
{
    return this->column_names.cend();
}

lcsv::csv_header::reverse_iterator lcsv::csv_header::rbegin()
{
    return this->column_names.rbegin();
}

lcsv::csv_header::reverse_iterator lcsv::csv_header::rend()
{
    return this->column_names.rend();
}

lcsv::csv_header::const_reverse_iterator lcsv::csv_header::crbegin()
{
    return this->column_names.crbegin();
}

lcsv::csv_header::const_reverse_iterator lcsv::csv_header::crend()
{
    return this->column_names.crend();
}
