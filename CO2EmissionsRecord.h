// CO2EmissionsRecord.h
#ifndef CO2_EMISSIONS_RECORD_H
#define CO2_EMISSIONS_RECORD_H

#include <string>

struct CO2EmissionsRecord {
    std::string country; // Country name
    int year;            // Year of the emission data
    double CO2_emissions; // CO2 emissions for the country in that year
};

#endif
