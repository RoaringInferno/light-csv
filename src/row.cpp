#include "light-csv/row.hpp"

lcsv::row::row() :
    cells()
{
}

lcsv::row::row(const std::string &row_line) :
    cells()
{
    // TODO: Implement
}

lcsv::row::row(const vector &cells) :
    cells(cells)
{
}

lcsv::row::row(const row &other) :
    cells(other.cells)
{
}

lcsv::row::~row()
{
}

std::string lcsv::row::to_string() const
{
    std::string result = "";
    for (const cell &c : this->cells) {
        result += c.to_string() + ",";
    }
    return result;
}

lcsv::row::operator std::string() const
{
    return this->to_string();
}

lcsv::row::reference lcsv::row::at(const lcsv::row::size_type index)
{
    return this->cells.at(index);
}

lcsv::row::reference lcsv::row::operator[](const lcsv::row::size_type index)
{
    return this->cells[index];
}

lcsv::row::reference lcsv::row::front()
{
    return this->cells.front();
}

lcsv::row::reference lcsv::row::back()
{
    return this->cells.back();
}

lcsv::row::pointer lcsv::row::data()
{
    return this->cells.data();
}

bool lcsv::row::empty() const
{
    return this->cells.empty();
}

lcsv::row::size_type lcsv::row::size() const
{
    return this->cells.size();
}

lcsv::row::size_type lcsv::row::max_size() const
{
    return this->cells.max_size();
}

void lcsv::row::reserve(const lcsv::row::size_type new_capacity)
{
    this->cells.reserve(new_capacity);
}

lcsv::row::size_type lcsv::row::capacity() const
{
    return this->cells.capacity();
}

void lcsv::row::shrink_to_fit()
{
    this->cells.shrink_to_fit();
}

void lcsv::row::clear()
{
    this->cells.clear();
}

lcsv::row::iterator lcsv::row::insert(lcsv::row::const_iterator position, lcsv::row::const_reference value)
{
    return this->cells.insert(position, value);
}

lcsv::row::iterator lcsv::row::insert(lcsv::row::const_iterator position, lcsv::row::reference &value)
{
    return lcsv::row::iterator();
}

lcsv::row::iterator lcsv::row::insert(lcsv::row::const_iterator position, const vector &values)
{
    return this->cells.insert(position, values.begin(), values.end());
}

lcsv::row::iterator lcsv::row::erase(lcsv::row::const_iterator position)
{
    return this->cells.erase(position);
}

lcsv::row::iterator lcsv::row::erase(lcsv::row::const_iterator first, lcsv::row::const_iterator last)
{
    return this->cells.erase(first, last);
}

void lcsv::row::push_back(lcsv::row::const_reference value)
{
    this->cells.push_back(value);
}

void lcsv::row::pop_back()
{
    this->cells.pop_back();
}

void lcsv::row::resize(const lcsv::row::size_type new_size)
{
    this->cells.resize(new_size);
}

void lcsv::row::resize(const lcsv::row::size_type new_size, lcsv::row::const_reference value)
{
    this->cells.resize(new_size, value);
}

void lcsv::row::swap(row &other)
{
    this->cells.swap(other.cells);
}

lcsv::row::iterator lcsv::row::begin()
{
    return this->cells.begin();
}

lcsv::row::iterator lcsv::row::end()
{
    return this->cells.end();
}

lcsv::row::const_iterator lcsv::row::cbegin()
{
    return this->cells.cbegin();
}

lcsv::row::const_iterator lcsv::row::cend()
{
    return this->cells.cend();
}

lcsv::row::reverse_iterator lcsv::row::rbegin()
{
    return this->cells.rbegin();
}

lcsv::row::reverse_iterator lcsv::row::rend()
{
    return this->cells.rend();
}

lcsv::row::const_reverse_iterator lcsv::row::crbegin()
{
    return this->cells.crbegin();
}

lcsv::row::const_reverse_iterator lcsv::row::crend()
{
    return this->cells.crend();
}
