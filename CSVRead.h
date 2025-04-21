#ifndef CSV_READ_H
#define CSV_READ_H

#include <vector>
#include <string>
#include "CO2EmissionsRecord.h"

std::vector<CO2EmissionsRecord> ReadCSVFile(const std::string& filename);

#endif
