#pragma once

#include "DynamicArray.hpp"
#include <string>

bool readCSVFile(const std::string &filename, DynamicArray &array);
double calculateMedian(const DynamicArray &array);

