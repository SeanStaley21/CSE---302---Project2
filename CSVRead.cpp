#include "CSVRead.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<CO2EmissionsRecord> ReadCSVFile(const std::string& filename) {
    std::vector<CO2EmissionsRecord> records;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return records;
    }

    getline(file, line);  // Skip header

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string country, yearStr, co2Str;

        getline(ss, country, ',');
        getline(ss, yearStr, ',');
        getline(ss, co2Str, ',');

        if (country.empty() || yearStr.empty() || co2Str.empty())
            continue;

        CO2EmissionsRecord rec;
        rec.country = country;
        rec.year = std::stoi(yearStr);
        rec.CO2_emissions = std::stod(co2Str);

        records.push_back(rec);
    }

    return records;
}
