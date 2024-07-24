#pragma once

#include "row.hpp"
#include "header.hpp"

#include <vector>
#include <string>

namespace lcsv
{
    class csv_file
    {
    public: // Typedefs
        typedef std::vector<csv_row> vector;

        typedef vector::size_type size_type;
        typedef vector::iterator iterator;
        typedef vector::const_iterator const_iterator;
        typedef vector::reverse_iterator reverse_iterator;
        typedef vector::const_reverse_iterator const_reverse_iterator;

        typedef csv_row value_type;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef value_type& reference;
        typedef const value_type& const_reference;
    private: // Members
        std::string path;
        csv_header file_header;
        vector rows;
    public: // Methods
        const std::string line_delimiter = "\r\n";

        csv_file();
        csv_file(const std::string& path);
        csv_file(const csv_header& file_header, const vector& rows);
        csv_file(const csv_file& other);
        ~csv_file();

        // Element access
        reference at(const size_type index);
        reference operator[](const size_type index);
        reference front();
        reference back();
        pointer data();

        const_reference at(const size_type index) const;
        const_reference operator[](const size_type index) const;
        const_reference front() const;
        const_reference back() const;
        const_pointer data() const;

        // Capacity
        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        void reserve(const size_type new_capacity);
        size_type capacity() const;
        void shrink_to_fit();

        // Modifiers
        void clear();
        iterator insert(const_iterator position, const_reference value);
        iterator insert(const_iterator position, const vector& values);
        iterator erase(const_iterator position);
        iterator erase(const_iterator first, const_iterator last);
        void push_back(const_reference value);
        void pop_back();
        void resize(const size_type new_size);
        void resize(const size_type new_size, const_reference value);
        void swap(csv_file& other);

        // Header Manipulation
        csv_header& header();
        const csv_header& header() const;
        

        // File Manipulation
        std::string get_path() const;
        void set_path(const std::string& path);

        // File I/O
        void read();
        void write();

        std::string to_string() const;
        operator std::string() const;

        // Iterator
        iterator begin();
        iterator end();
        const_iterator cbegin();
        const_iterator cend();

        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator crbegin();
        const_reverse_iterator crend();
    };
}; // namespace lcsv