#pragma once

#include <string>

namespace lcsv
{
    class csv_line_reader
    {
    public: // Typedefs
        typedef char value_type;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef value_type& reference;
        typedef const value_type& const_reference;

        typedef std::string::size_type size_type;
        typedef std::string::iterator iterator;
        typedef std::string::const_iterator const_iterator;
        typedef std::string::reverse_iterator reverse_iterator;
        typedef std::string::const_reverse_iterator const_reverse_iterator;
    private: // Methods
        const_iterator find_next_separator(const_iterator start) const;
        const_reverse_iterator find_previous_separator(const_reverse_iterator start) const;
    private: // Members
        std::string csv_string;
        /**
         * @brief The position immediately following the left-hand separator. (The first character of the current cell, after the comma)
         * @note 0-based index.
         */
        const_iterator left_separator;
        /**
         * @brief The position of the right-hand separator. (Immediately following the last character of the current cell, on the comma)
         * @note 0-based index.
         */
        const_iterator right_separator;

        /**
         * @note 0-based index
         */
        size_type column_number;
    public: // Methods
        const value_type separator = ',';

        csv_line_reader();
        csv_line_reader(const std::string& csv_string);
        csv_line_reader(const csv_line_reader& other);
        ~csv_line_reader();

        // Element access'
        reference at(const size_type index);
        reference operator[](const size_type index);

        // Capacity
        bool empty() const;
        size_type size() const;

        // Iteration
        const_iterator left_separator_position() const;
        const_iterator right_separator_position() const;
        size_type block_size() const;

        // Iterators
        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;

        // CSV
        std::string read_cell() const;
        void advance();
        void retreat();

        // column_number
        size_type get_column_number() const;
        void set_column_number(const size_type column_number);
    };
}; // namespace lcsv