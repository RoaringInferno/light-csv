#include "internal/csv-line-reader.hpp"

lcsv::csv_line_reader::csv_line_reader() :
    csv_string(),
    left_separator(),
    right_separator(),
    column_number()
{
}

#include <iostream>

lcsv::csv_line_reader::csv_line_reader(const std::string &csv_string) :
    csv_string(csv_string),
    left_separator(),
    right_separator(),
    column_number(0)
{
    left_separator = this->csv_string.begin();
    right_separator = find_next_separator(this->csv_string.begin()); // Find the first separator
}

lcsv::csv_line_reader::csv_line_reader(const csv_line_reader &other) :
    csv_string(other.csv_string),
    left_separator(),
    right_separator(),
    column_number(other.column_number)
{
    left_separator = this->csv_string.begin();
    right_separator = this->csv_string.begin();
}

lcsv::csv_line_reader::~csv_line_reader()    
{
}

lcsv::csv_line_reader::const_iterator lcsv::csv_line_reader::find_next_separator(lcsv::csv_line_reader::const_iterator start) const
{
    while (*start != this->separator && start != this->csv_string.end())
    {
        start++;
    }
    return start;
}

lcsv::csv_line_reader::const_reverse_iterator lcsv::csv_line_reader::find_previous_separator(lcsv::csv_line_reader::const_reverse_iterator start) const
{
    while (*start != this->separator && start != this->csv_string.rend())
    {
        start++;
    }
    return start;
}

lcsv::csv_line_reader::reference lcsv::csv_line_reader::at(const lcsv::csv_line_reader::size_type index)
{
    return this->csv_string.at(index);
}

lcsv::csv_line_reader::reference lcsv::csv_line_reader::operator[](const lcsv::csv_line_reader::size_type index)
{
    return this->csv_string[index];
}

bool lcsv::csv_line_reader::empty() const
{
    return this->csv_string.empty();
}

lcsv::csv_line_reader::size_type lcsv::csv_line_reader::size() const
{
    return this->csv_string.size();
}

lcsv::csv_line_reader::const_iterator lcsv::csv_line_reader::left_separator_position() const
{
    return this->left_separator;
}

lcsv::csv_line_reader::const_iterator lcsv::csv_line_reader::right_separator_position() const
{
    return this->right_separator;
}

lcsv::csv_line_reader::size_type lcsv::csv_line_reader::block_size() const
{
    // Optimization: return this->right_separator - this->left_separator;
    return this->right_separator_position() - this->left_separator_position();
}

lcsv::csv_line_reader::iterator lcsv::csv_line_reader::begin()
{
    return this->csv_string.begin();
}

lcsv::csv_line_reader::iterator lcsv::csv_line_reader::end()
{
    return this->csv_string.end();
}

lcsv::csv_line_reader::const_iterator lcsv::csv_line_reader::cbegin() const
{
    return this->csv_string.cbegin();
}
lcsv::csv_line_reader::const_iterator lcsv::csv_line_reader::cend() const
{
    return this->csv_string.cend();
}
lcsv::csv_line_reader::reverse_iterator lcsv::csv_line_reader::rbegin()
{
    return this->csv_string.rbegin();
}
lcsv::csv_line_reader::reverse_iterator lcsv::csv_line_reader::rend()
{
    return this->csv_string.rend();
}
lcsv::csv_line_reader::const_reverse_iterator lcsv::csv_line_reader::crbegin() const
{
    return this->csv_string.crbegin();
}
lcsv::csv_line_reader::const_reverse_iterator lcsv::csv_line_reader::crend() const
{
    return this->csv_string.crend();
}
std::string lcsv::csv_line_reader::read_cell() const
{
    std::string result = "";
    const_iterator read_head = this->left_separator;
    while (read_head != this->right_separator)
    {
        if (*read_head != 13)
        {
            result += *read_head;
        }
        read_head++;
    }
    return result;
}

void lcsv::csv_line_reader::advance()
{
    if (this->right_separator == this->csv_string.end())
    {
        return;
    }
    this->left_separator = this->right_separator + 1;
    this->right_separator = find_next_separator(this->left_separator);
    this->column_number++;
}

void lcsv::csv_line_reader::retreat()
{
    if (this->left_separator == this->csv_string.begin())
    {
        return;
    }
    this->right_separator = this->left_separator - 1; // The right separator is on the left separator
    // Reversing the right separator points to the character right before the left separator
    // Search to the beginning of the string (rend = reverse end, so the beginning from the reverse perspective)
    // Search for the separator ',
    // The result is a reverse iterator, pointing to the left separator
    // Convert the reverse iterator to a forward iterator, now pointing to the character immediately following the left separator
    // If there was no separator before the left separator, the left separator is now the beginning of the string (The reversed iterator was looking past the beginning of the string, at rend())
    this->left_separator = this->find_previous_separator(std::make_reverse_iterator(this->right_separator)).base(); // Find the previous separator
    this->column_number--;
}

lcsv::csv_line_reader::size_type lcsv::csv_line_reader::get_column_number() const
{
    return this->column_number;
}

void lcsv::csv_line_reader::set_column_number(const lcsv::csv_line_reader::size_type column_number)
{
    this->column_number = column_number;
}
