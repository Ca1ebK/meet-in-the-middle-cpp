#pragma once

class DynamicArray
{
private:
  int *data;
  int capacity;
  int size;

  void resize();

public:
  DynamicArray();
  ~DynamicArray();

  void add(int element);
  int get(int index) const;
  int getSize() const;
  bool isEmpty() const;
};
