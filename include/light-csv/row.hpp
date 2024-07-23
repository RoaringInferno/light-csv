#pragma once

#include "cell.hpp"

#include <vector>
#include <string>

namespace lcsv
{
    class row
    {
    public: // Typedefs
        typedef unsigned char index;
        typedef std::vector<cell>::iterator iterator;
        typedef std::vector<cell>::const_iterator const_iterator;
    private: // Members
        std::vector<cell> cells;
    public: // Methods
        row();
        row(const std::string& row_line);
        row(const row& other) = default;
        ~row();

        // Cell Manipulation
        cell get_cell(const index index) const;
        std::vector<cell> get_cells() const;
        void add_cell(const cell& c);
        void add_cells(const std::vector<cell>& cells);
        void remove_cell(const index index);
        void remove_cells(const std::vector<index>& indexes);
        void remove_all_cells();
        void set_cell(const index index, const cell& c);

        std::string to_string() const;
        operator std::string() const;

        // Iterator
        iterator begin();
        iterator end();
    };
}; // namespace lcsv