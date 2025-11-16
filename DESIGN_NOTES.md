# Design Notes - Meet in the Middle

## Thought-Provoking Questions

### 1. How do you keep track of the number of items in the file?

The `DynamicArray` class maintains a `size` variable that tracks the number of elements currently stored in the array. Every time we call the `add()` method while reading from the CSV file, the size is incremented. This way, we don't need to know the total count beforehand - we simply count as we read.

### 2. When might your program fail to allocate memory on the heap?

The program allocates memory on the heap in two places:

- Initial allocation in the `DynamicArray` constructor
- When resizing the array (doubling capacity when full)

Memory allocation could fail if:
- The system runs out of available memory
- The array grows too large (very large dataset)
- Other programs are using most of the available memory

If `new` fails to allocate memory, it would typically throw a `std::bad_alloc` exception. In production code, we might want to catch this exception and handle it gracefully.

### 3. What is nullptr and how might it be used in your program?

`nullptr` is a keyword in C++ that represents a null pointer - a pointer that points to nothing. 

In our program, we use `nullptr` in the destructor:
```cpp
delete[] data;
data = nullptr;  // Set pointer to nullptr after freeing memory
```

This is a good practice because:
- It prevents accidentally using the pointer after the memory has been freed
- It makes debugging easier (accessing nullptr typically causes immediate crash)
- It helps avoid "dangling pointer" bugs

We could also check if a pointer is `nullptr` before using it to prevent crashes.

### 4. Does it matter if the data points are sorted in ascending or descending order when calculating the median? Why or why not?

No, it doesn't matter whether the data is sorted in ascending or descending order. The median calculation only cares about finding the middle value(s), not whether they increase or decrease.

For example:
- Ascending: [1, 2, 3, 4, 5] → median is 3 (middle element)
- Descending: [5, 4, 3, 2, 1] → median is 3 (still the middle element)

For even-length arrays:
- Ascending: [1, 2, 3, 4] → median is (2+3)/2 = 2.5
- Descending: [4, 3, 2, 1] → median is (3+2)/2 = 2.5

The position-based approach works regardless of sort direction. We simply access the middle index (or indices) of the array.

## Design Decisions

### Dynamic Array Implementation

The `DynamicArray` class uses:
- **Pointer arithmetic**: The `data` pointer references a dynamically allocated array
- **Manual memory management**: We use `new` and `delete[]` to manage heap memory
- **Automatic resizing**: When the array reaches capacity, we double its size
- **Starting capacity of 10**: Balances memory usage with resize frequency

### Median Calculation

The median calculation handles two cases:
1. **Odd number of elements**: Returns the middle element directly
2. **Even number of elements**: Returns the average of the two middle elements

We use `static_cast<double>` to ensure proper floating-point division even though our input values are integers.

### File Reading

The CSV reading function:
- Uses `std::ifstream` to read the file
- Reads the entire line at once (assumes single-line CSV)
- Uses `std::stringstream` to parse comma-separated values
- Converts strings to integers using `std::stoi`
- Returns a boolean to indicate success/failure

