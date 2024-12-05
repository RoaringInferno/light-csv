#include "light-csv_bits/file.hpp"

#include <fstream>

lcsv::csv_file::csv_file() :
    path(),
    file_header(),
    rows()
{
}

lcsv::csv_file::csv_file(const std::string &path) :
    path(path),
    file_header(),
    rows()
{
    this->read();
}

lcsv::csv_file::csv_file(const csv_header &file_header, const vector &rows) :
    path(),
    file_header(file_header),
    rows(rows)
{
}

lcsv::csv_file::csv_file(const csv_file &other) :
    path(other.path),
    file_header(other.file_header),
    rows(other.rows)
{
}

lcsv::csv_file::~csv_file()
{
}

lcsv::csv_file::reference lcsv::csv_file::at(const lcsv::csv_file::size_type index)
{
    return this->rows.at(index);
}

lcsv::csv_file::reference lcsv::csv_file::operator[](const lcsv::csv_file::size_type index)
{
    return this->rows[index];
}

lcsv::csv_file::reference lcsv::csv_file::front()
{
    return this->rows.front();
}

lcsv::csv_file::reference lcsv::csv_file::back()
{
    return this->rows.back();
}

lcsv::csv_file::pointer lcsv::csv_file::data()
{
    return this->rows.data();
}

lcsv::csv_file::const_reference lcsv::csv_file::at(const size_type index) const
{
    return this->rows.at(index);
}

lcsv::csv_file::const_reference lcsv::csv_file::operator[](const lcsv::csv_file::size_type index) const
{
    return this->rows[index];
}

lcsv::csv_file::const_reference lcsv::csv_file::front() const
{
    return this->rows.front();
}

lcsv::csv_file::const_reference lcsv::csv_file::back() const
{
    return this->rows.back();
}

lcsv::csv_file::const_pointer lcsv::csv_file::data() const
{
   return this->rows.data();
}

bool lcsv::csv_file::empty() const
{
    return this->rows.empty();
}

lcsv::csv_file::size_type lcsv::csv_file::size() const
{
    return this->rows.size();
}

lcsv::csv_file::size_type lcsv::csv_file::max_size() const
{
    return this->rows.max_size();
}

void lcsv::csv_file::reserve(const lcsv::csv_file::size_type new_capacity)
{
    this->rows.reserve(new_capacity);
}

lcsv::csv_file::size_type lcsv::csv_file::capacity() const
{
    return this->rows.capacity();
}

void lcsv::csv_file::shrink_to_fit()
{
    this->rows.shrink_to_fit();
}

void lcsv::csv_file::clear()
{
    this->rows.clear();
}

lcsv::csv_file::iterator lcsv::csv_file::insert(lcsv::csv_file::const_iterator position, lcsv::csv_file::const_reference value)
{
    return this->rows.insert(position, value);
}

lcsv::csv_file::iterator lcsv::csv_file::insert(lcsv::csv_file::const_iterator position, const vector &values)
{
    return this->rows.insert(position, values.begin(), values.end());
}

lcsv::csv_file::iterator lcsv::csv_file::erase(lcsv::csv_file::const_iterator position)
{
    return this->rows.erase(position);
}

lcsv::csv_file::iterator lcsv::csv_file::erase(lcsv::csv_file::const_iterator first, lcsv::csv_file::const_iterator last)
{
    return this->rows.erase(first, last);
}

void lcsv::csv_file::push_back(lcsv::csv_file::const_reference value)
{
    this->rows.push_back(value);
}

void lcsv::csv_file::pop_back()
{
    this->rows.pop_back();
}

void lcsv::csv_file::resize(const lcsv::csv_file::size_type new_size)
{
    this->rows.resize(new_size);
}

void lcsv::csv_file::resize(const lcsv::csv_file::size_type new_size, lcsv::csv_file::const_reference value)
{
    this->rows.resize(new_size, value);
}

void lcsv::csv_file::swap(csv_file &other)
{
    this->rows.swap(other.rows);
}

lcsv::csv_header &lcsv::csv_file::header()
{
    return this->file_header;
}

const lcsv::csv_header &lcsv::csv_file::header() const
{
    return this->file_header;
}
std::string lcsv::csv_file::get_path() const
{
    return this->path;
}

void lcsv::csv_file::set_path(const std::string &path)
{
    this->path = path;
}

void lcsv::csv_file::read()
{
    // Open file
    std::ifstream file(this->path);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + this->path);
    }
    // Read header
    std::string line;
    std::getline(file, line);
    this->file_header = csv_header(line);
    // Read rows
    while (std::getline(file, line))
    {
        this->rows.push_back(csv_row(line));
    }
}

void lcsv::csv_file::write()
{
    // Open file
    // overwrite file
    std::ofstream file(this->path, std::ios::trunc);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + this->path);
    }
    // Make string
    std::string file_string = this->to_string();
    // Write string
    file << file_string;
}

void lcsv::csv_file::write(const std::string &path)
{
    // Open file
    std::ofstream file(path);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + this->path);
    }
    // Make string
    std::string file_string = this->to_string();
    // Write string
    file << file_string;
}

std::string lcsv::csv_file::to_string() const
{
    std::string result = "";
    // Write header
    result += this->file_header.to_string() += line_delimiter;
    // Write rows
    for (const csv_row &_row : this->rows)
    {
        result += _row.to_string() += line_delimiter;
    }
    // Remove last line delimiter ("\n")
    result.pop_back();
    return result;
}

lcsv::csv_file::operator std::string() const
{
    return this->to_string();
}

lcsv::csv_file::iterator lcsv::csv_file::begin()
{
    return this->rows.begin();
}

lcsv::csv_file::iterator lcsv::csv_file::end()
{
    return this->rows.end();
}

lcsv::csv_file::const_iterator lcsv::csv_file::cbegin()
{
    return this->rows.cbegin();
}

lcsv::csv_file::const_iterator lcsv::csv_file::cend()
{
    return this->rows.cend();
}

lcsv::csv_file::reverse_iterator lcsv::csv_file::rbegin()
{
    return this->rows.rbegin();
}

lcsv::csv_file::reverse_iterator lcsv::csv_file::rend()
{
    return this->rows.rend();
}

lcsv::csv_file::const_reverse_iterator lcsv::csv_file::crbegin()
{
    return this->rows.crbegin();
}

lcsv::csv_file::const_reverse_iterator lcsv::csv_file::crend()
{
    return this->rows.crend();
}
