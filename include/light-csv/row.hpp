#pragma once

#include "cell.hpp"

#include <vector>
#include <string>

namespace lcsv
{
    class csv_row
    {
    public: // Typedefs
        typedef std::vector<csv_cell> vector;

        typedef vector::size_type size_type;
        typedef vector::iterator iterator;
        typedef vector::const_iterator const_iterator;
        typedef vector::reverse_iterator reverse_iterator;
        typedef vector::const_reverse_iterator const_reverse_iterator;

        typedef csv_cell value_type;   
        typedef value_type* pointer;
        typedef const value_type& reference;
        typedef const value_type* const_pointer;
        typedef const value_type& const_reference;
    private: // Members
        vector cells;
    public: // Methods
        csv_row();
        csv_row(const std::string& row_line);
        csv_row(const vector& cells);
        csv_row(const csv_row& other);
        ~csv_row();

        std::string to_string() const;
        operator std::string() const;

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
        void swap(csv_row& other);

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