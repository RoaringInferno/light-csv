# light-csv
Easy csv parsing.

## Usage
Create a ```lcsv::file(std::string)``` object, passing the path to the file. Call ```lcsv::file::read()```.

Once the operation is completed, calling ```lcsv::file::header()``` grants access to the csv header, which can be used like an ```std::vector<std::string>```.

The ```lcsv::file``` object itself is a ```std::vector<lcsv::row>```. Each row is a ```std::vector<lcsv::cell>```.

```lcsv::cell```s are wrappers for ```std::string```.
Use implicit or explicit conversion (overloaded ```operator std::string() const```) to access the value, with wrapping quotation marks and [escaped] double quotations parsed out.

For all four objects (```lcsv::file```, ```lcsv::header```, ```lcsv::row```, ```lcsv::cell```), call ```::to_string()``` to get its file-writable string form.
Use this to get the string you would use to write a csv file (lines are delimited with ```\r\n```, except the last line with only ```\r```, and quotations are escaped and wrapped when appropriate).

Alternatively, use ```lcsv::file::write()``` to write the file to its original path, or ```lcsv::file::write(std::string)``` to write to a different path.
