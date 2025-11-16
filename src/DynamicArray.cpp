#include "DynamicArray.hpp"
#include <iostream>

DynamicArray::DynamicArray()
{
  capacity = 10;
  size = 0;
  data = new int[capacity];
}

DynamicArray::~DynamicArray()
{
  delete[] data;
  data = nullptr;
}

void DynamicArray::resize()
{
  int newCapacity = capacity * 2;
  int *newData = new int[newCapacity];
  
  for (int i = 0; i < size; i++)
  {
    newData[i] = data[i];
  }
  
  delete[] data;
  data = newData;
  capacity = newCapacity;
}

void DynamicArray::add(int element)
{
  if (size == capacity)
  {
    resize();
  }
  
  data[size] = element;
  size++;
}

int DynamicArray::get(int index) const
{
  if (index < 0 || index >= size)
  {
    std::cerr << "Error: Index out of bounds.\n";
    return 0;
  }
  
  return data[index];
}

int DynamicArray::getSize() const
{
  return size;
}

bool DynamicArray::isEmpty() const
{
  return (size == 0);
}

