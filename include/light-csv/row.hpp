#pragma once

#include "cell.hpp"

#include <vector>
#include <string>

namespace lcsv
{
    typedef unsigned int cell_index_t;

    class row
    {
    private:
        std::vector<cell> cells;
    public:
        row();
        row(const std::string& row_line);
        row(const row& other) = default;
        ~row();

        // Cell Manipulation
        cell get_cell(const cell_index_t index) const;
        std::vector<cell> get_cells() const;
        void add_cell(const cell& c);
        void add_cells(const std::vector<cell>& cells);
        void remove_cell(const cell_index_t index);
        void remove_cells(const std::vector<cell_index_t>& indexes);
        void remove_all_cells();
        void set_cell(const cell_index_t index, const cell& c);

        std::string to_string() const;
        operator std::string() const;
    };
}; // namespace lcsv