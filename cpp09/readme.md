# CPP09
## Requirement
- One container per exercise
- Except ex02 which uses 2 containers
## ex00 Bitcoin Exchange
- Goal: Read a file with date-value pairs and use another input to find corresponding prices
- Core ideas
    - Parse & validate dates and floats
    - Use a container to store date-value pairs for fast lookup by date or closest lower bound
    - Use ```std::ifstream``` and ```std::getline``` to handle file reading line by line
    - Use ```std::lower_bound``` logic or map iterators for closest matching keys
- Container choose
    - ```std::map```
    - Dates are naturally sorted keys -> map give O(log n) lookup with order
### Notes
#### ```std::ifstream```
- To read data from files, stands for input file stream
- Part of the <fstream> lib
- Key member functions

    | Function     | Description                                             |
    | ------------ | ------------------------------------------------------- |
    | `.is_open()` | Checks if the file is open                              |
    | `.getline()` | Reads a line from the file                              |
    | `.eof()`     | Checks if end of file has been reached                  |
    | `.close()`   | Closes the file                                         |
    | `.good()`    | Checks if the stream is in good state                   |
    | `operator>>` | Can be used like `file >> variable` for formatted input |

- Example of usage

    ```cpp
    #include <iostream>
    #include <fstream>
    #include <string>

    int main() {
        std::ifstream file("example.txt");  // Open the file for reading

        if (!file.is_open()) {
            std::cerr << "Failed to open file.\n";
            return 1;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;  // Print each line
        }

        file.close();  // Close the file
        return 0;
    }
    ```
#### ```std::getline```
- Read a line of text from an input stream until it encounters a delimiter (\n by default)
- Basic syntax: ```std::getline(input_stream, string_variable, delimiter);```
    - input_strea: the stream to read from eg. std::cin or ifstream
    - string_variable: a std::string where the content will be stored
    - delimiter (optional): the char that stops reading
- Example: Read from a file line by line
    ```cpp
    #include <fstream>
    #include <string>

    int main() {
        std::ifstream file("data.txt");
        std::string line;
        
        while (std::getline(file, line)) {  // Reads until EOF
            std::cout << line << '\n';
        }
    }
    ```

## ex01 Reverse polish notaion

## ex02 PmergeMe

## Notes
### Common CPP containers overview

| Container          | Order | Lookup Time | Insertion Time | Use Case |
|--------------------|-------|------------|--------------|----------|
| **`std::vector`**   | Sorted/Unsorted | O(n) | O(1) (amortized) | Dynamic arrays, random access |
| **`std::list`**     | Unsorted | O(n) | O(1) | Frequent insertions/deletions |
| **`std::deque`**    | Unsorted | O(n) | O(1) (front/back) | Double-ended queue |
| **`std::set`**      | Sorted (unique keys) | O(log n) | O(log n) | Sorted unique elements |
| **`std::multiset`** | Sorted (duplicates allowed) | O(log n) | O(log n) | Sorted elements (non-unique) |
| **`std::map`**      | Sorted (key-value) | O(log n) | O(log n) | Key-value pairs (sorted) |
| **`std::multimap`** | Sorted (duplicate keys) | O(log n) | O(log n) | Key-value (non-unique keys) |
| **`std::unordered_map`** | Unsorted (hash-based) | **O(1)** avg, O(n) worst | O(1) avg | Fast key-value lookup (no ordering) |
| **`std::unordered_set`** | Unsorted (hash-based) | **O(1)** avg | O(1) avg | Fast unique key lookup |

#### When to use sorted or unsorted containers?
- Use sorted (eg. std::map, std::set) if you need
    - Ordered traversal
    - Range-based operations, eg. find all dates in Q1 2023
- Use unsorted (eg. std::unordered_map, std::vector) if you need
    - Max lookup/ insertion speed
    - Order doesn't matter

#### Big O
- Big O describe the time complexity (or space complexity) of an algo/ operation, indicating how its performance scales as the input size (n) grows. It helps compare the efficiency of containers/ operations in the worst-case or average-case scenarios
- Common big O notions

    | Notation      | Meaning                  | Example (Lookup)               |
    |--------------|--------------------------|--------------------------------|
    | **O(1)**     | Constant time            | `std::unordered_map` (hash table) |
    | **O(log n)** | Logarithmic time         | Binary search in sorted `std::vector` |
    | **O(n)**     | Linear time              | Linear search in `std::list`   |
    | **O(n log n)** | Linearithmic time     | Sorting (`std::sort`)          |
    | **O(n²)**    | Quadratic time           | Nested loops over all elements |
- Big O in cpp containers
    - Lookup time

        | Container          | Lookup Time | Reason                          |
        |--------------------|------------|--------------------------------|
        | `std::unordered_map` | **O(1)** avg | Hash table (direct key→value)  |
        | `std::map`          | **O(log n)** | Red-Black Tree (sorted)        |
        | `std::vector` (unsorted) | **O(n)** | Sequential check              |
        | `std::vector` (sorted) | **O(log n)** | Binary search (`std::lower_bound`) |
    - Insertion time

        | Container          | Insertion Time | Reason                          |
        |--------------------|---------------|--------------------------------|
        | `std::unordered_map` | **O(1)** avg | Hash and store (no reordering) |
        | `std::map`          | **O(log n)** | Tree rebalancing               |
        | `std::vector` (end) | **O(1)** amortized | Push back (resizing rare)   |
        | `std::vector` (middle) | **O(n)** | Shift elements               |
#### What's red-black tree in high level
- A Red-Black Tree is a type of self-balancing binary search tree (BST) used to maintain sorted data efficiently. It ensures that operations eg. insertion, deletion, and lookup remain O(log n) time complexity, even in the worst case.
- Why red-black trees?
    - Standard BST can degenerate into a linked list (O(n) operations) if inserted in sorted order
    - Red-black tree auto balance themselves to prevent this, guaranteeing log time for key operations
    - Example
        - Standard BST problem
            - In a regular BST, each node usually has a left child and a right child
            - But if you insert already sorted data, the tree becomes like a linked list
            ```
            // insert 1,2,3,4,5 into a basic BST
            // tree becomes a chain
            // search for 5 requires 5 comparison, O(n) time

            1
              \
                2
                  \
                   3
                     \
                      4
                        \
                          5
            ```
        - Red-black tree fixes that
            - Auto rebalance after each insertion via color flips and rotation
            ```
            // after each inseration, the tree rebalances
            // search for any value only takes ~log(n) steps

                 2 (black)
                / \
                1   4 (black)
                    / \
                    3   5
            ```
- Key properties
    - Node color: every node is either red or black
    - Root is black: the root node must always be black
    - No 2 adjacent reds: a red node cannot have a red parent or child
    - Black depth equality: every path from a node to its descendant NULL leaves must have the same number of black nodes (to ensure balance)
- How it maintains balance
    - Great playlist explaining red-black tree and its mechanism: https://www.youtube.com/watch?v=qvZGUFHWChY&list=PL9xmBV_5YoZNqDI8qfOZgzbqahCUmUEin&index=1

#### What's binary search in high level
- Binary search is an efficient algorithm for finding a target value in a sorted collection (e.g., array, list). It works by repeatedly dividing the search range in half, eliminating half of the remaining elements at each step.
- Key Properties
    - Requirement: Data must be sorted (ascending/descending).
    - Time Complexity: O(log n) (much faster than linear search’s O(n)).
    - Space Complexity: O(1) (uses constant extra space).
- How it works
    - Initialize:
        - Define a start (beginning of the array) and end (last index).
    - Loop Until Found or Exhausted:
        - Calculate the middle index: mid = start + (end - start) / 2.
        - Compare the middle element (arr[mid]) to the target:
            - If equal: Return mid (target found!).
            - If target < middle: Search the left half (end = mid - 1).
            - If target > middle: Search the right half (start = mid + 1).
    - Terminate:
        - If start > end, the target doesn’t exist.
- Pseudo code
    ```python
    def binary_search(arr, target):
        start, end = 0, len(arr) - 1
        while start <= end:
            mid = start + (end - start) // 2
            if arr[mid] == target:
                return mid
            elif target < arr[mid]:
                end = mid - 1
            else:
                start = mid + 1
        return -1  # Not found
    ```