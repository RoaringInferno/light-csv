#include "csv-line-reader.hpp"

lcsv::csv_line_reader::csv_line_reader() :
    csv_string(),
    left_separator(),
    right_separator(),
    column_number()
{
}

lcsv::csv_line_reader::csv_line_reader(const std::string &csv_string) :
    csv_string(csv_string),
    left_separator(this->csv_string.begin()),
    right_separator(this->csv_string.begin()),
    column_number(0)
{
}

lcsv::csv_line_reader::csv_line_reader(const csv_line_reader &other) :
    csv_string(other.csv_string),
    left_separator(this->csv_string.begin()),
    right_separator(this->csv_string.begin()),
    column_number(other.column_number)
{
}

lcsv::csv_line_reader::~csv_line_reader()    
{
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

lcsv::csv_line_reader::size_type lcsv::csv_line_reader::left_separator_position() const
{
    return this->left_separator - this->csv_string.begin();
}

lcsv::csv_line_reader::size_type lcsv::csv_line_reader::right_separator_position() const
{
    return this->right_separator - this->csv_string.begin();
}

lcsv::csv_line_reader::size_type lcsv::csv_line_reader::block_size() const
{
    // Optimization: return this->right_separator - this->left_separator;
    return this->right_separator_position() - this->left_separator_position();
}

std::string lcsv::csv_line_reader::read_cell() const
{
    return std::string(this->left_separator, this->right_separator);
}

void lcsv::csv_line_reader::next_cell()
{
    // TODO: Implement
}

void lcsv::csv_line_reader::previous_cell()
{
    // TODO: Implement
}

lcsv::csv_line_reader::size_type lcsv::csv_line_reader::get_column_number() const
{
    return this->column_number;
}

void lcsv::csv_line_reader::set_column_number(const lcsv::csv_line_reader::size_type column_number)
{
    this->column_number = column_number;
}
