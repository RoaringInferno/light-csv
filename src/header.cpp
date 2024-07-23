#include "light-csv/header.hpp"
#include "internal/csv-line-reader.hpp"

lcsv::header::header() :
    column_names()
{
}

lcsv::header::header(const std::string &header_line) :
    column_names()
{
    lcsv::csv_line_reader reader(header_line);
    do {
        this->column_names.push_back(reader.read_cell());
        if (reader.right_separator_position() != reader.end()) { break; }
        reader.advance();
    } while (true);
}

lcsv::header::header(const vector &column_names) :
    column_names(column_names)
{
}

lcsv::header::header(const header &other) :
    column_names(other.column_names)
{
}

lcsv::header::~header()
{
}

std::string lcsv::header::to_string() const
{
    std::string result = "";
    for (const std::string &c : this->column_names) {
        result += c + ",";
    }
    return result;
}

lcsv::header::operator std::string() const
{
    return this->to_string();
}

lcsv::header::reference lcsv::header::at(const lcsv::header::size_type index)
{
    return this->column_names.at(index);
}

lcsv::header::reference lcsv::header::operator[](const lcsv::header::size_type index)
{
    return this->column_names[index];
}

lcsv::header::reference lcsv::header::front()
{
    return this->column_names.front();
}

lcsv::header::reference lcsv::header::back()
{
    return this->column_names.back();
}

lcsv::header::pointer lcsv::header::data()
{
    return this->column_names.data();
}

bool lcsv::header::empty() const
{
    return this->column_names.empty();
}

lcsv::header::size_type lcsv::header::size() const
{
    this->column_names.size();
}

lcsv::header::size_type lcsv::header::max_size() const
{
    return this->column_names.max_size();
}

void lcsv::header::reserve(const lcsv::header::size_type new_capacity)
{
    this->column_names.reserve(new_capacity);
}

lcsv::header::size_type lcsv::header::capacity() const
{
    this->column_names.capacity();
}

void lcsv::header::shrink_to_fit()
{
    this->column_names.shrink_to_fit();
}

void lcsv::header::clear()
{
    this->column_names.clear();
}

lcsv::header::iterator lcsv::header::insert(lcsv::header::const_iterator position, lcsv::header::const_reference value)
{
    return this->column_names.insert(position, value);
}

lcsv::header::iterator lcsv::header::insert(lcsv::header::const_iterator position, lcsv::header::reference &value)
{
    return this->column_names.insert(position, value);
}

lcsv::header::iterator lcsv::header::insert(lcsv::header::const_iterator position, const vector &values)
{
    return this->column_names.insert(position, values.begin(), values.end());
}

lcsv::header::iterator lcsv::header::erase(lcsv::header::const_iterator position)
{
    return this->column_names.erase(position);
}

lcsv::header::iterator lcsv::header::erase(lcsv::header::const_iterator first, lcsv::header::const_iterator last)
{
    return this->column_names.erase(first, last);
}

void lcsv::header::push_back(lcsv::header::const_reference value)
{
    this->column_names.push_back(value);
}

void lcsv::header::pop_back()
{
    this->column_names.pop_back();
}

void lcsv::header::resize(const lcsv::header::size_type new_size)
{
    this->column_names.resize(new_size);
}

void lcsv::header::resize(const lcsv::header::size_type new_size, lcsv::header::const_reference value)
{
    this->column_names.resize(new_size, value);
}

void lcsv::header::swap(header &other)
{
    this->column_names.swap(other.column_names);
}

lcsv::header::iterator lcsv::header::begin()
{
    return this->column_names.begin();
}

lcsv::header::iterator lcsv::header::end()
{
    return this->column_names.end();
}

lcsv::header::const_iterator lcsv::header::cbegin()
{
    return this->column_names.cbegin();
}

lcsv::header::const_iterator lcsv::header::cend()
{
    return this->column_names.cend();
}

lcsv::header::reverse_iterator lcsv::header::rbegin()
{
    return this->column_names.rbegin();
}

lcsv::header::reverse_iterator lcsv::header::rend()
{
    return this->column_names.rend();
}

lcsv::header::const_reverse_iterator lcsv::header::crbegin()
{
    return this->column_names.crbegin();
}

lcsv::header::const_reverse_iterator lcsv::header::crend()
{
    return this->column_names.crend();
}
