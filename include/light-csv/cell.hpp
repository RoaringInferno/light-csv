#pragma once

#include <string>

namespace lcsv
{
    class csv_cell
    {
    public: // Typedefs
        typedef std::string value_type;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef value_type& reference;
        typedef const value_type& const_reference;
    private: // Members
        std::string value;
    public: // Methods
        csv_cell();
        csv_cell(const_reference value);
        csv_cell(const csv_cell& other);
        ~csv_cell();

        std::string get_value() const;
        void set_value(const_reference value);
        pointer data();

        bool is_empty() const;

        std::string to_string() const;
        operator std::string() const;

        csv_cell& operator=(const csv_cell& other);
        bool operator==(const csv_cell& other) const;
    };
}; // namespace lcsv