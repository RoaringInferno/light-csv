#include "file.hpp"

lcsv::file::file() :
    path(),
    file_header(),
    rows()
{
}

lcsv::file::file(const std::string &path) :
    path(path),
    file_header(),
    rows()
{
    this->read();
}

lcsv::file::file(const header &file_header, const vector &rows) :
    path(),
    file_header(file_header),
    rows(rows)
{
}

lcsv::file::file(const file &other) :
    path(other.path),
    file_header(other.file_header),
    rows(other.rows)
{
}

lcsv::file::~file()
{
}

lcsv::file::reference lcsv::file::at(const lcsv::file::size_type index)
{
    return this->rows.at(index);
}

lcsv::file::reference lcsv::file::operator[](const lcsv::file::size_type index)
{
    return this->rows[index];
}

lcsv::file::reference lcsv::file::front()
{
    return this->rows.front();
}

lcsv::file::reference lcsv::file::back()
{
    return this->rows.back();
}

lcsv::file::pointer lcsv::file::data()
{
    return this->rows.data();
}

bool lcsv::file::empty() const
{
    return this->rows.empty();
}

lcsv::file::size_type lcsv::file::size() const
{
    return this->rows.size();
}

lcsv::file::size_type lcsv::file::max_size() const
{
    return this->rows.max_size();
}

void lcsv::file::reserve(const lcsv::file::size_type new_capacity)
{
    this->rows.reserve(new_capacity);
}

lcsv::file::size_type lcsv::file::capacity() const
{
    return this->rows.capacity();
}

void lcsv::file::shrink_to_fit()
{
    this->rows.shrink_to_fit();
}

void lcsv::file::clear()
{
    this->rows.clear();
}

lcsv::file::iterator lcsv::file::insert(lcsv::file::const_iterator position, lcsv::file::const_reference value)
{
    return this->rows.insert(position, value);
}

lcsv::file::iterator lcsv::file::insert(lcsv::file::const_iterator position, lcsv::file::reference &value)
{
    return this->rows.insert(position, value);
}

lcsv::file::iterator lcsv::file::insert(lcsv::file::const_iterator position, const vector &values)
{
    return this->rows.insert(position, values.begin(), values.end());
}

lcsv::file::iterator lcsv::file::erase(lcsv::file::const_iterator position)
{
    return this->rows.erase(position);
}

lcsv::file::iterator lcsv::file::erase(lcsv::file::const_iterator first, lcsv::file::const_iterator last)
{
    return this->rows.erase(first, last);
}

void lcsv::file::push_back(lcsv::file::const_reference value)
{
    this->rows.push_back(value);
}

void lcsv::file::pop_back()
{
    this->rows.pop_back();
}

void lcsv::file::resize(const lcsv::file::size_type new_size)
{
    this->rows.resize(new_size);
}

void lcsv::file::resize(const lcsv::file::size_type new_size, lcsv::file::const_reference value)
{
    this->rows.resize(new_size, value);
}

void lcsv::file::swap(file &other)
{
    this->rows.swap(other.rows);
}

lcsv::header &lcsv::file::get_header()
{
    return this->file_header;
}

void lcsv::file::set_header(const header &h)
{
    this->file_header = h;
}

std::string lcsv::file::get_path() const
{
    return this->path;
}

void lcsv::file::set_path(const std::string &path)
{
    this->path = path;
}

void lcsv::file::read()
{
    // TODO: Implement
}

void lcsv::file::write()
{
    // TODO: Implement
}

std::string lcsv::file::to_string() const
{
    std::string result;
    // TODO: Implement
    return result;
}

lcsv::file::operator std::string() const
{
    return this->to_string();
}

lcsv::file::iterator lcsv::file::begin()
{
    return this->rows.begin();
}

lcsv::file::iterator lcsv::file::end()
{
    return this->rows.end();
}

lcsv::file::const_iterator lcsv::file::cbegin()
{
    return this->rows.cbegin();
}

lcsv::file::const_iterator lcsv::file::cend()
{
    return this->rows.cend();
}

lcsv::file::reverse_iterator lcsv::file::rbegin()
{
    return this->rows.rbegin();
}

lcsv::file::reverse_iterator lcsv::file::rend()
{
    return this->rows.rend();
}

lcsv::file::const_reverse_iterator lcsv::file::crbegin()
{
    return this->rows.crbegin();
}

lcsv::file::const_reverse_iterator lcsv::file::crend()
{
    return this->rows.crend();
}