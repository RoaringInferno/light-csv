#pragma once

#include <vector>
#include <string>

namespace lcsv
{
    class header
    {
    public: // Typedefs
        typedef unsigned char index;
        typedef std::vector<std::string>::iterator iterator;
        typedef std::vector<std::string>::const_iterator const_iterator;
    private: // Members
        std::vector<std::string> column_names;
        index column_name_count;
    public: // Methods
        header();
        header(const std::string& header_line);
        header(const header& other) = default;
        ~header();

        // Column Name Manipulation
        std::string get_column_name(const unsigned int index) const;
        std::vector<std::string> get_column_names() const;
        void add_column_name(const std::string& column_name);
        void add_column_names(const std::vector<std::string>& column_names);
        void remove_column_name(const unsigned int index);
        void remove_column_names(const std::vector<unsigned int>& indexes);
        void remove_all_column_names();
        void set_column_name(const unsigned int index, const std::string& column_name);

        std::string to_string() const;
        operator std::string() const;

        // Iterator
        iterator begin();
        iterator end();
    };
}; // namespace lcsv