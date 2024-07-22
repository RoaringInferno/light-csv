#pragma once

#include <vector>
#include <string>

namespace lcsv
{
    typedef unsigned char column_name_index_t;

    class header
    {
    private:
        std::vector<std::string> column_names;
        column_name_index_t column_name_count;
    public:
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
    };
}; // namespace lcsv