#include "light-csv_bits/row.hpp"
#include "internal/csv-line-reader.hpp"

lcsv::csv_row::csv_row() :
    cells()
{
}

lcsv::csv_row::csv_row(const std::string &row_line) :
    cells()
{
    lcsv::csv_line_reader reader(row_line);
    do {
        this->cells.push_back(lcsv::csv_cell(reader.read_cell()));
        if (reader.right_separator_position() == reader.end()) { break; }
        reader.advance();
    } while (true);
}

lcsv::csv_row::csv_row(const vector &cells) :
    cells(cells)
{
}

lcsv::csv_row::csv_row(const csv_row &other) :
    cells(other.cells)
{
}

lcsv::csv_row::~csv_row()
{
}

std::string lcsv::csv_row::to_string() const
{
    std::string result = "";
    for (const csv_cell &c : this->cells) {
        result += c.to_string() + ",";
    }
    result.pop_back();
    return result;
}

lcsv::csv_row::operator std::string() const
{
    return this->to_string();
}

lcsv::csv_row::reference lcsv::csv_row::at(const lcsv::csv_row::size_type index)
{
    return this->cells.at(index);
}

lcsv::csv_row::reference lcsv::csv_row::operator[](const lcsv::csv_row::size_type index)
{
    return this->cells[index];
}

lcsv::csv_row::reference lcsv::csv_row::front()
{
    return this->cells.front();
}

lcsv::csv_row::reference lcsv::csv_row::back()
{
    return this->cells.back();
}

lcsv::csv_row::pointer lcsv::csv_row::data()
{
    return this->cells.data();
}

lcsv::csv_row::const_reference lcsv::csv_row::at(const lcsv::csv_row::size_type index) const
{
    return this->cells.at(index);
}

lcsv::csv_row::const_reference lcsv::csv_row::operator[](const lcsv::csv_row::size_type index) const
{
    return this->cells[index];
}

lcsv::csv_row::const_reference lcsv::csv_row::front() const
{
    return this->cells.front();
}

lcsv::csv_row::const_reference lcsv::csv_row::back() const
{
    return this->cells.back();
}

lcsv::csv_row::const_pointer lcsv::csv_row::data() const
{
    return this->cells.data();
}

bool lcsv::csv_row::empty() const
{
    return this->cells.empty();
}

lcsv::csv_row::size_type lcsv::csv_row::size() const
{
    return this->cells.size();
}

lcsv::csv_row::size_type lcsv::csv_row::max_size() const
{
    return this->cells.max_size();
}

void lcsv::csv_row::reserve(const lcsv::csv_row::size_type new_capacity)
{
    this->cells.reserve(new_capacity);
}

lcsv::csv_row::size_type lcsv::csv_row::capacity() const
{
    return this->cells.capacity();
}

void lcsv::csv_row::shrink_to_fit()
{
    this->cells.shrink_to_fit();
}

void lcsv::csv_row::clear()
{
    this->cells.clear();
}

lcsv::csv_row::iterator lcsv::csv_row::insert(lcsv::csv_row::const_iterator position, lcsv::csv_row::const_reference value)
{
    return this->cells.insert(position, value);
}

lcsv::csv_row::iterator lcsv::csv_row::insert(lcsv::csv_row::const_iterator position, const vector &values)
{
    return this->cells.insert(position, values.begin(), values.end());
}

lcsv::csv_row::iterator lcsv::csv_row::erase(lcsv::csv_row::const_iterator position)
{
    return this->cells.erase(position);
}

lcsv::csv_row::iterator lcsv::csv_row::erase(lcsv::csv_row::const_iterator first, lcsv::csv_row::const_iterator last)
{
    return this->cells.erase(first, last);
}

void lcsv::csv_row::push_back(lcsv::csv_row::const_reference value)
{
    this->cells.push_back(value);
}

void lcsv::csv_row::emplace_back(csv_cell::value_type &&value)
{
    this->cells.emplace_back(value);
}

void lcsv::csv_row::pop_back()
{
    this->cells.pop_back();
}

void lcsv::csv_row::resize(const lcsv::csv_row::size_type new_size)
{
    this->cells.resize(new_size);
}

void lcsv::csv_row::resize(const lcsv::csv_row::size_type new_size, lcsv::csv_row::const_reference value)
{
    this->cells.resize(new_size, value);
}

void lcsv::csv_row::swap(csv_row &other)
{
    this->cells.swap(other.cells);
}

lcsv::csv_row::iterator lcsv::csv_row::begin()
{
    return this->cells.begin();
}

lcsv::csv_row::iterator lcsv::csv_row::end()
{
    return this->cells.end();
}

lcsv::csv_row::const_iterator lcsv::csv_row::cbegin()
{
    return this->cells.cbegin();
}

lcsv::csv_row::const_iterator lcsv::csv_row::cend()
{
    return this->cells.cend();
}

lcsv::csv_row::reverse_iterator lcsv::csv_row::rbegin()
{
    return this->cells.rbegin();
}

lcsv::csv_row::reverse_iterator lcsv::csv_row::rend()
{
    return this->cells.rend();
}

lcsv::csv_row::const_reverse_iterator lcsv::csv_row::crbegin()
{
    return this->cells.crbegin();
}

lcsv::csv_row::const_reverse_iterator lcsv::csv_row::crend()
{
    return this->cells.crend();
}

lcsv::csv_row::csv_row(const std::vector<std::string>& cells) :
    cells(cells.size())
{
    for (size_t i = 0; i < cells.size(); i++) {
        this->cells[i] = lcsv::csv_cell(cells[i]);
    }
}

lcsv::csv_row::csv_row(const std::vector<std::string> &&cells) :
    cells(cells.size())
{
    for (size_t i = 0; i < cells.size(); i++) {
        this->cells[i] = std::move(lcsv::csv_cell(cells[i]));
    }
}