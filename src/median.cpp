#include "median.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

bool readCSVFile(const std::string &filename, DynamicArray &array)
{
  std::ifstream file(filename);
  
  if (!file.is_open())
  {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return false;
  }
  
  std::string content;
  std::getline(file, content);
  file.close();
  
  std::stringstream stream(content);
  std::string token;
  
  while (std::getline(stream, token, ','))
  {
    int value = std::stoi(token);
    array.add(value);
  }
  
  return true;
}

double calculateMedian(const DynamicArray &array)
{
  int count = array.getSize();
  
  if (count == 0)
  {
    return 0.0;
  }
  
  if (count % 2 == 1)
  {
    int middleIndex = count / 2;
    return array.get(middleIndex);
  }
  else
  {
    int middleIndex1 = (count / 2) - 1;
    int middleIndex2 = count / 2;
    
    return (array.get(middleIndex1) + array.get(middleIndex2)) / 2.0;
  }
}

