#ifndef ASLISTR_H
#define ASLISTR_H

#include <string>
#include <iostream>
#include <algorithm>

struct CO2EmissionsRecord {
    std::string country;      // Country name
    int year;                 // Year of emissions data
    double CO2_emissions;     // CO2 emissions value for the country
};
class ASListR {
public:
    ASListR(int maxSize);      // Constructor with parameter for max array size
    ~ASListR();                // Destructor

    void PutItem(const CO2EmissionsRecord&); // Adds the item to the list
    void PrintList();          // Print all elements of the list in a readable format
    //sorting functions
    void SortByCO2EmissionsDescending();  // Sort the list by CO2 emissions in descending order
    void SortByCO2EmissionsAscending();  // Sort the list by CO2 emissions in ascending order
    void SortByYearDescending();  // Sort the list by year in descending order
    void SortByYearAscending();  // Sort the list by year in ascending order
    void SortByCountryDescending();  // Sort the list by country in descending order
    void SortByCountryAscending();  // Sort the list by country in ascending order
private:
    int length;                // Current number of items in the list
    CO2EmissionsRecord* ListItems; // Array of CO2EmissionsRecord
    int MAXSIZE;               // Maximum size of the list
    int currentPos;            // Current position in the list
};
// Constructor
ASListR::ASListR(int maxSize) {
    length = 0;
    MAXSIZE = maxSize;
    currentPos = 0;
    ListItems = new CO2EmissionsRecord[MAXSIZE];
}
// Destructor
ASListR::~ASListR() {
    delete[] ListItems;
}
// Adds an item to the list
void ASListR::PutItem(const CO2EmissionsRecord& record) {
    if (length < MAXSIZE) {
        ListItems[length] = record;
        length++;
    } else {
        std::cout << "Error: List is full!" << std::endl;
    }
}
// Print all elements of the list
void ASListR::PrintList() {
    for (int i = 0; i < length; i++) {
        std::cout << "Country: " << ListItems[i].country 
                  << "\t\t Year: " << ListItems[i].year 
                  << "\t\t CO2 Emissions: " << ListItems[i].CO2_emissions << std::endl;
    }
}
// Sort the list by CO2 emissions in descending order
void ASListR::SortByCO2EmissionsDescending() {
    std::sort(ListItems, ListItems + length, [](const CO2EmissionsRecord& a, const CO2EmissionsRecord& b) {
        return a.CO2_emissions > b.CO2_emissions;  // Sort in descending order
    });
}

// Sort the list by CO2 emissions in ascending order
void ASListR::SortByCO2EmissionsAscending() {
    std::sort(ListItems, ListItems + length, [](const CO2EmissionsRecord& a, const CO2EmissionsRecord& b) {
        return a.CO2_emissions < b.CO2_emissions;  // Sort in ascending order by CO2 emissions
    });
}

// Sort the list by year in descending order
void ASListR::SortByYearDescending() {
    std::sort(ListItems, ListItems + length, [](const CO2EmissionsRecord& a, const CO2EmissionsRecord& b) {
        return a.year > b.year;  // Sort in descending order by year
    });
}

// Sort the list by year in ascending order
void ASListR::SortByYearAscending() {
    std::sort(ListItems, ListItems + length, [](const CO2EmissionsRecord& a, const CO2EmissionsRecord& b) {
        return a.year < b.year;  // Sort in ascending order by year
    });
}

// Sort the list by country in descending order
void ASListR::SortByCountryDescending() {
    std::sort(ListItems, ListItems + length, [](const CO2EmissionsRecord& a, const CO2EmissionsRecord& b) {
        return a.country > b.country;  // Sort in descending order by country
    });
}

// Sort the list by country in ascending order
void ASListR::SortByCountryAscending() {
    std::sort(ListItems, ListItems + length, [](const CO2EmissionsRecord& a, const CO2EmissionsRecord& b) {
        return a.country < b.country;  // Compare alphabetically in ascending order
    });
}


#endif
