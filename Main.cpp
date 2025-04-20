#include "ASListR.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

ASListR csvtoASListR(string csvfile) { // Convert a csv file to a list structure
    ASListR retCO2List(205); // Make sure the array has sufficient size for our data
    ifstream ReadFile(csvfile); // Open the csv file for reading
    string line, curvalue;
    getline(ReadFile, line); // Skip the first line (column names)
    
    while (getline(ReadFile, line)) {
        stringstream ss(line); // Turn the line into a string-stream
        int fielditer = 0;
        CO2EmissionsRecord newrec;
        
        // Parse each field in the CSV line
        while (getline(ss, curvalue, ',')) {
            switch (fielditer) {
                case 0: newrec.country = curvalue; break;    // Country name
                case 1: newrec.year = stoi(curvalue); break;  // Year
                case 2: newrec.CO2_emissions = stod(curvalue); break;  // CO2 emissions (numeric)
            }
            fielditer++;
        }
        
        retCO2List.PutItem(newrec); // Add the record to the list
    }
    
    return retCO2List; // Return the populated ASListR
}

int main(int argc, char** argv) {
    // Load CO2 emissions data from CSV file
    ASListR CO2EmissionsData = csvtoASListR("CO2_Emissions.csv");

    // added the the ability for the user to choose the sorting method
    int choice;
    cout << "Choose a sorting option:" << endl;
    cout << "1. Sort by CO2 emissions (Ascending)" << endl;
    cout << "2. Sort by CO2 emissions (Descending)" << endl;
    cout << "3. Sort by Year (Ascending)" << endl;
    cout << "4. Sort by Year (Descending)" << endl;
    cout << "5. Sort by Country (Ascending)" << endl;
    cout << "6. Sort by Country (Descending)" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    switch (choice) {
        case 1:
            CO2EmissionsData.SortByCO2EmissionsAscending();
            cout << "Sorted by CO2 emissions (Ascending)." << endl;
            break;
        case 2:
            CO2EmissionsData.SortByCO2EmissionsDescending();
            cout << "Sorted by CO2 emissions (Descending)." << endl;
            break;
        case 3:
            CO2EmissionsData.SortByYearAscending();
            cout << "Sorted by Year (Ascending)." << endl;
            break;
        case 4:
            CO2EmissionsData.SortByYearDescending();
            cout << "Sorted by Year (Descending)." << endl;
            break;
        case 5:
            CO2EmissionsData.SortByCountryAscending();
            cout << "Sorted by Country (Ascending)." << endl;
            break;
        case 6:
            CO2EmissionsData.SortByCountryDescending();
            cout << "Sorted by Country (Descending)." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
            return 1;
    }

    
    // Print the sorted data
    CO2EmissionsData.PrintList(); // Ensure the list is printed in the correct order
    return 0;
}
