#pragma once

#include <string>

namespace lcsv
{
    class cell
    {
    public:
        typedef std::string value_type;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef value_type& reference;
        typedef const value_type& const_reference;
    private: // Members
        std::string value;
    public: // Methods
        cell();
        cell(const_reference value);
        cell(const cell& other) = default;
        ~cell();

        std::string get_value() const;
        void set_value(const_reference value);
        pointer data();

        bool is_empty() const;

        std::string to_string() const;
        operator std::string() const;

        cell& operator=(const cell& other);
        bool operator==(const cell& other) const;
    };
}; // namespace lcsv