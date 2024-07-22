#pragma once

#include <string>

namespace lcsv
{
    class cell
    {
    private:
        std::string value;
    public:
        cell();
        cell(const std::string& value);
        cell(const cell& other) = default;
        ~cell();

        std::string get_value() const;
        void set_value(const std::string& value);

        bool is_empty() const;

        std::string to_string() const;
        operator std::string() const;
    };
}; // namespace lcsv