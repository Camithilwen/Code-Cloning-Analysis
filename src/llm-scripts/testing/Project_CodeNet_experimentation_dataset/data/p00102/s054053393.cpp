#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <iomanip>

std::vector<int> parse_line(std::string const& line) {
    using namespace std;
    vector<int> result;
    istringstream s(line);
    string element;
    while (getline(s, element, ' ')) {
        stringstream buf;
        int value = 0;
        buf << element;
        buf >> value;
        result.push_back(value);
    }
    return std::move(result);
}
int main(int argc, char* argv[])
{
    using namespace std;
    while (true) {
        string line;
        getline(std::cin, line);
        auto elements = parse_line(line);
        auto length = elements[0];
        if (length == 0) break;
        vector<int> total(length + 1);
        size_t width = length + 1;
        for (size_t i = 0; i < length; ++i) {
            getline(cin, line);
            elements = parse_line(line);
            int sum = 0;
            for (size_t n = 0; n < length; ++n) {
                int val = elements[n];
                sum += val;
                total[n] += val;
                cout << setw(5) << val;
            }
            cout << setw(5) << sum << endl;
            total[length] += sum;
        }
        for (size_t i = 0; i < width; ++i) {
            cout << setw(5) << total[i];
        }
        cout << endl;
    }

    return 0;
}