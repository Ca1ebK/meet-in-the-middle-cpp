#include <iostream>
#include <string>
#include "src/DynamicArray.hpp"
#include "src/median.hpp"

int main()
{
  std::string filename;
  std::cout << "Enter the filename: ";
  std::getline(std::cin, filename);
  
  DynamicArray dataArray;
  bool success = readCSVFile(filename, dataArray);
  
  if (!success)
  {
    return 1;
  }
  
  double median = calculateMedian(dataArray);
  std::cout << "The median of the dataset is " << median << ".\n";
  
  return 0;
}
