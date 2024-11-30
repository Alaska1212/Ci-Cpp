#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <map>

struct Date {
    int day, month, year;

    bool operator<(const Date& other) const {
        return std::tie(year, month, day) < std::tie(other.year, other.month, other.day);
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << year << "/" << std::setw(2) << std::setfill('0') << month << "/" << std::setw(2) << day;
        return oss.str();
    }
};

int main() {
    std::ifstream inputFile("dates.txt");
    if (!inputFile) {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    const std::map<std::string, int> monthMap = {
        {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
        {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8},
        {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
    };

    std::set<Date> uniqueDates;
    int day, year;
    std::string month;

    while (inputFile >> day >> month >> year) {
        uniqueDates.insert({day, monthMap.at(month), year});
    }

    for (const auto& date : uniqueDates) {
        std::cout << date.toString() << std::endl;
    }

    return 0;
}
