#pragma once

#include "row.hpp"
#include "header.hpp"

#include <vector>
#include <string>

namespace lcsv
{
    class file
    {
    public: // Typedefs
        typedef unsigned int index;
        typedef std::vector<row>::iterator iterator;
        typedef std::vector<row>::const_iterator const_iterator;
    private: // Members
        std::string path;
        header file_header;
        std::vector<row> rows;
        index row_count;
    public: // Methods
        file();
        file(const std::string& path);
        file(const file& other) = default;
        ~file();

        // Row Manipulation
        row get_row(const index index);
        std::vector<row> get_rows();
        void add_row(const row& r);
        void add_rows(const std::vector<row>& rows);
        void remove_row(const index index);
        void remove_rows(const std::vector<index>& indexes);
        void remove_all_rows();
        void set_row(const index index, const row& r);

        // Header Manipulation
        header get_header();
        void set_header(const header& h);

        // File Manipulation
        std::string get_path() const;
        void set_path(const std::string& path);

        // Row Count
        index get_row_count() const;

        // File I/O
        void read();
        void write();

        std::string to_string() const;
        operator std::string() const;

        // Iterator
        iterator begin();
        iterator end();
    };
}; // namespace lcsv