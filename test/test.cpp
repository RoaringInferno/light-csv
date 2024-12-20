#include "light-csv"

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <chrono>

const std::string test_file_dir = "../test/files/";

const std::string test_files[] = {
    "numbers.csv", // Checks read integrity.
};

void verify_numbers_csv(lcsv::csv_file& file)
{
    std::cout << "Verifying read file numbers.csv" << std::endl;

    assert(file.header().size() == 6); // 6 columns
    assert(file.header()[0] == "Number");
    assert(file.header()[1] == "x10");
    assert(file.header()[2] == "x7");
    assert(file.header()[3] == "Numberx4");
    assert(file.header()[4] == "+40");
    assert(file.header()[5] == "*0.1");
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
            if (i_divided.back() == '0'){
                i_divided.pop_back();
            } else {
                char last = i_divided.back();
                i_divided.pop_back();
                i_divided += ".";
                i_divided += last;
            }
        } else {
            i_divided = "0." + i_divided;
        }
        assert(row[5].to_string() == i_divided); // /10
        i++;
    }
};

int main(int argc, char **argv) {
    std::vector<lcsv::csv_file> files;
    for (const std::string &file : test_files) {
        auto start = std::chrono::high_resolution_clock::now();
        lcsv::csv_file f(test_file_dir + file);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "File: " << file << " read in " << std::to_string(elapsed.count() * 1000) << "ms" << std::endl;

        files.push_back(f);
    }

    verify_numbers_csv(files[0]);

    // Write test
    const std::vector<std::string> write_header = {"Header", "B", "C"};
    const std::vector<std::vector<std::string>> write_data = {
        {"1", "2", "3"},
        {"4", "5", "6"},
        {"7", "8", "9"},
        {"Hello", "World", "!"},
        {"10", "11", "12"},
    };

    { // Writing data
        std::cout << "Writing data\n";
        lcsv::csv_file write_test("write_test.csv");
        write_test.header() = write_header;
        for (int i = 0; i < write_data.size(); i++) {
            write_test.push_back(write_data[i]);
        }
        write_test.write();
    }

    // Reading data
    std::cout << "Reading data to verify\n";
    lcsv::csv_file write_test("write_test.csv");
    for (unsigned int i = 0; i < write_header.size(); i++) {
        assert(write_test.header()[i] == write_header[i]);
    }
    for (unsigned int i = 0; i < write_data.size(); i++) {
        for (unsigned int j = 0; j < write_header.size(); j++)
        {
            assert(write_test[i][j].get_value() == write_data[i][j]);
        }
    }

    return 0;
}