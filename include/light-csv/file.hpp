#pragma once

#include "row.hpp"
#include "header.hpp"

#include <vector>
#include <string>

namespace lcsv
{
    typedef unsigned int row_index_t;

    class file
    {
    private:
        std::string path;
        header file_header;
        std::vector<row> rows;
        row_index_t row_count;
    public:
        file();
        file(const std::string& path);
        file(const file& other) = default;
        ~file();

        // Row Manipulation
        row get_row(const row_index_t index);
        std::vector<row> get_rows();
        void add_row(const row& r);
        void add_rows(const std::vector<row>& rows);
        void remove_row(const row_index_t index);
        void remove_rows(const std::vector<row_index_t>& indexes);
        void remove_all_rows();
        void set_row(const row_index_t index, const row& r);

        // Header Manipulation
        header get_header();
        void set_header(const header& h);

        // File Manipulation
        std::string get_path() const;
        void set_path(const std::string& path);

        // Row Count
        row_index_t get_row_count() const;

        // File I/O
        void read();
        void write();

        std::string to_string() const;
        operator std::string() const;
    };
}; // namespace lcsv