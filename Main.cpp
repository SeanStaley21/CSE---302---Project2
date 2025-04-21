#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include "CO2EmissionsRecord.h"
#include "CSVRead.h"

using namespace std;

// Max heap comparator
struct CompareCO2 {
    bool operator()(const CO2EmissionsRecord& a, const CO2EmissionsRecord& b) {
        return a.CO2_emissions < b.CO2_emissions;  // max-heap
    }
};

int main() {
    vector<CO2EmissionsRecord> records = ReadCSVFile("CO2_Emissions.csv");

    // Load into heap and keep insertion order
    priority_queue<CO2EmissionsRecord, vector<CO2EmissionsRecord>, CompareCO2> maxHeap;
    vector<CO2EmissionsRecord> insertionOrder;

    for (const auto& rec : records) {
        maxHeap.push(rec);
        insertionOrder.push_back(rec);
    }

    int choice;
    cout << "Choose an option:\n";
    cout << "1. Print k countries with highest CO2 emissions\n";
    cout << "2. Print every kth inserted record\n";
    cin >> choice;

    if (choice == 1) {
        int k;
        cout << "Enter value for k: ";
        cin >> k;
        cout << "\nTop " << k << " countries by CO2 emissions:\n";
        for (int i = 0; i < k && !maxHeap.empty(); ++i) {
            CO2EmissionsRecord top = maxHeap.top();
            maxHeap.pop();
            cout << top.country << " (" << top.year << ") - CO2: " << top.CO2_emissions << endl;
        }
    } else if (choice == 2) {
        int k;
        cout << "Enter value for k: ";
        cin >> k;
        cout << "\nEvery " << k << "th inserted record:\n";
        for (size_t i = k - 1; i < insertionOrder.size(); i += k) {
            const auto& rec = insertionOrder[i];
            cout << rec.country << " (" << rec.year << ") - CO2: " << rec.CO2_emissions << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
    }

    //pause to wait for user to end the program
    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
