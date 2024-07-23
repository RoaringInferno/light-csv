#include "light-csv.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <chrono>

const std::string test_file_dir = "../test/files/";

const std::string test_files[] = {
    "numbers.csv",
};

void verify_numbers_csv(lcsv::csv_file& file)
{
    std::cout << "Verifying read file numbers.csv" << std::endl;

    assert(file.header().size() == 6); // 6 columns
    assert(file.header().to_string() == "Number,x10,x7,Numberx4,\"+40\",\"/10\""); // header text
    assert(file.size() == 1000); // 1000 rows
    unsigned int i = 1;
    for (const lcsv::csv_row& row : file) {
        assert(row.size() == 6); // 6 columns
        assert(row[0].to_string() == std::to_string(i)); // Number
        assert(row[1].to_string() == std::to_string(i * 10)); // x10
        assert(row[2].to_string() == std::to_string(i * 7)); // x7
        assert(row[3].to_string() == std::to_string(i * 4)); // Numberx4
        assert(row[4].to_string() == std::to_string(i + 40)); // +40
        std::string i_divided = std::to_string(i);
        if (i_divided.size() > 1) {
            i_divided = i_divided.substr(0, i_divided.size() - 1) + "." + i_divided.substr(i_divided.size() - 1);
        } else {
            i_divided = "0." + i_divided;
        }
        assert(row[5].to_string() == i_divided); // /10
    }
};

int main(int argc, char **argv) {
    std::vector<lcsv::csv_file> files;
    for (const std::string &file : test_files) {
        auto start = std::chrono::high_resolution_clock::now();
        lcsv::csv_file f(test_file_dir + file);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "File: " << file << " read in " << std::to_string(elapsed.count()) << "ms" << std::endl;

        files.push_back(f);
    }

    verify_numbers_csv(files[0]);
    return 0;
}