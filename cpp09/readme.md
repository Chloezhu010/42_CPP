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
- Container
    - ```std::map```
    - Dates are naturally sorted keys -> map give O(log n) lookup with order
    - For input file, one date may have multiple values
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
#### ```substr()```
- A member function of std::string class that extracts a substring from a string
- Part of ```<string>``` lib
- Basic syntax: ```string substr(size_t pos = 0, size_t len = npos) const;```
    - pos: starting pos of the substring (default is 0)
    - len: nb of char to include (default is npos)
    - return: a new string containing the extracted substr
#### ```std::map```
- A associative container in C++ that stores key-value pairs, with the keys kept in sorted order
- Incl. in the ```<map>``` lib and based on a self-balancing red-black tree
- Basic syntax: 
    - ```std::map<std::string, int> myMap;```
- Common operations
    - Insert or assign
        ```cpp
        myMap["apple"] = 5;                  // Inserts or updates
        myMap.insert({"banana", 10});       // Insert only if key doesn't exist
        ```
    - Lookup
        ```cpp
        #include <iostream>
        #include <map>
        #include <string>

        int main() {
            std::map<std::string, int> ages {
                {"Alice", 30},
                {"Bob", 25},
                {"Charlie", 35}
            };

            // Using operator[]
            std::cout << "Alice's age: " << ages["Alice"] << "\n";  // 30
            
            // Using at()
            try {
                std::cout << "Bob's age: " << ages.at("Bob") << "\n";  // 25
                std::cout << "Dave's age: " << ages.at("Dave") << "\n";  // throws
            } catch(const std::out_of_range& e) {
                std::cout << "Key not found\n";
            }

            // Using find()
            auto it = ages.find("Charlie");
            if (it != ages.end()) {
                std::cout << "Charlie's age: " << it->second << "\n";  // 35
            } else {
                std::cout << "Charlie not found\n";
            }

            return 0;
        }
        ```
    - Erase
        ```cpp
        myMap.erase("banana");
        ```
    - Iterate
        ```cpp
        for (std::map<std::string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
            std::cout << it->first << ": " << it->second << "\n";

        // Or use C++11 style:
        for (const auto& [key, value] : myMap)
            std::cout << key << ": " << value << "\n";
        ```
#### ```std::lower_bound```
- A binary search algo that returns the 1st position in a sorted range
- Incl in the ```<algorithm>``` lib
- Basic synthax: ```iterator = std::lower_bound(begin, end, value);```
    - Search in the [begin, end] range
    - Return an iterator pointing to the 1st element >= value
    - The range must be sorted
- Example
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>

    int main() {
        std::vector<int> v = {10, 20, 30, 40, 50};

        auto it = std::lower_bound(v.begin(), v.end(), 30);
        std::cout << *it << std::endl;  // Output: 30

        it = std::lower_bound(v.begin(), v.end(), 35);
        std::cout << *it << std::endl;  // Output: 40
    }
    ```

## ex01 Reverse polish notaion
- Goal: Build a program that can parse & evaluate a IPN expression using a stack
- Core ideas
    - Inverse polish notation
    - Stack-based evaluation
    - Input parsing
        - split the input into tokens
        - push nb onto the stack
        - when encountering an operator, pop 2 numbers, apply the operation, and push the result
    - Error handling
        - Invalid char
        - Division by 0
        - Too many/ few operators
        - Badly formed expression
- Container
    - ```std::stack```
    - Match LIFO data structure

### Notes
#### Inverted polish math expression
- Characteristics of IPN
    - No parentheses needed
    - Evaluated from left to right using a stack
    - Widely used in stack-based calculators, compilers, and interpreter design
- Example
    ```
    // normal
    3 + 4
    (3 + 4) * (5 - 2)

    // IPN
    3 4 +
    3 4 + 5 2 - *
    ```
- How to evaluate IPN
    - Use a stack
        - Read tokens left to right
        - Push operands to the stack
        - When see an operator, pop the top 2 elements, apply the operator, push the result back
    - For ```3 4 + 5 2 - *```
        - Push 3 to stack: [3]
        - Push 4 to stack: [3, 4]
        - +, pop 3 and 4: 3+4=7, push to stack: [7]
        - Push 5 and 2: [7, 5, 2]
        - -, pop 5 and 2: 5-3=3, push to stack: [7, 3]
        - *, pop 7 and 3: 7*3=21, push to stack: [21]
#### ```std::stack```
- A container adapter that gives you LIFO behavior
- Incl in the ```<stack>``` header
- Common member functions

    | Function  | Description                                 |
    | --------- | ------------------------------------------- |
    | `push(x)` | Adds `x` to the top of the stack            |
    | `pop()`   | Removes the top element                     |
    | `top()`   | Returns (reference to) the top element      |
    | `empty()` | Returns `true` if the stack is empty        |
    | `size()`  | Returns the number of elements in the stack |
#### ```std::istringstream```
- A stream that reads from a ```std::string```
- Incl in ```<sstream>``` header
- Key use cases
    - Split a string into space-separated tokens
    - Parse strings into int, float, etc.
    - Process cmd line inputs or file content
- Example
    ```cpp
    #include <sstream>
    #include <string>
    #include <iostream>

    int main() {
        std::string input = "42 hello 3.14";
        std::istringstream iss(input);

        int a;
        std::string word;
        double pi;

        iss >> a >> word >> pi;

        std::cout << "a = " << a << "\n";
        std::cout << "word = " << word << "\n";
        std::cout << "pi = " << pi << "\n";

        return 0;
    }

    // output
    // a = 42
    // word = hello
    // pi = 3.14
    ```

## ex02 PmergeMe
- Goal
    - Simulate a hybrid sorting algo (based on merge-insertion sort) to sort a sequence of positive int
    - Take unsorted nb as input, store them in containers, apply a hybrid sorting algo while measuring execution time for each container
        - Understand the sorting optimizations
        - Use containers (vector and deque) and compare their performance
        - Measure runtime for each container
- Key concept
    - Merge insertion / Ford Johnson algo simplified version
        - Insertion sort for small subgroups
        - Merge sort for combining sorted subgroups
        - Balance the simplicity of insertion sort (good for small n) and the power of merge sort (good for large n)
    - Divide and conquer
        - Input list split into pairs of elements
        - Each pair is partially sorted, then the larger elements are recursively sorted into a main chain
        - The smaller elements are inserted in the correct position within the sorted sequence using binary search
    - Performance benchmark
        - Compare ```std::vector``` and ```std::deque``` for the smae sorting operation
        - Time complexity should be the same
        - But memory layout and access patterns differ -> diff in real-world timing
- Container
    - ```std::vector```
        - Contiguous memory, good cache locality
        - Fast random access
        - Ideal for binary search and insertion
        - Slight overhead when inserting not at the end
    - ```std::deque```
        - Double-ended queue with segmented memory layout
        - Constant-time insertion/ removal at both ends
        - Slighly slower random access than vector
        - Useful if many insertions/ removals are not at the end
- Implementation logic
    - Parse input
        - Only accept valid positive int
        - Check for duplicates or invalid input
    - Store input
        - Store the input into both container
    - Sort each container with merge-insert algo
        - Group nb in pairs
        - Sort each pair
        - Recursively merge the larger elements
        - Insert the smaller ones into the right position in the sorted list
    - Measure performance
        - Time the operation on each container
        - Output sorted list & duration in micro/ milliseconds

### Notes
#### Different sorting mechanism and evolution
- Sorting algo are mechanism that arranges elements of a list / array in a specific order
- Major sorting algo and evolution

    | Algorithm            | Era Introduced | Time Complexity        | Key Features & Evolutionary Role                                  |
    |----------------------|---------------|------------------------|-------------------------------------------------------------------|
    | Bubble Sort          | 1950s         | O(n^2)                 | Simple, educational, inefficient for large data                   |
    | Selection Sort       | 1950s         | O(n^2)                 | Simple, but not efficient for large datasets                      |
    | Insertion Sort       | 1950s         | O(n^2)                 | Efficient for small or nearly sorted data; used in modern hybrids |
    | Merge Sort           | 1945–1950s    | O(n log n)             | First efficient divide-and-conquer sort; stable, consistent       |
    | Quick Sort           | 1960          | Avg: O(n log n), Worst: O(n^2) | Fast in practice, in-place, widely used, not stable by default    |
    | Heap Sort            | 1964          | O(n log n)             | Good worst-case, in-place, not stable, less cache-friendly        |
    | Hybrid Sorts         | 1990s+        | O(n log n)             | Combine strengths of multiple algorithms (e.g., Timsort, Introsort)|

- Early algo: simple but inefficient for large data
    - Bubble sort
        - repeatedly steps through the list, compare adjacent elements, swap them if in wrong order
        - bubble the largest unsorted element to its correct position at the end
        - continue until no swaps are needed
    - Selection sort
        - divide the list into a sorted and unsorted part
        - repeatedly select the smallest element from the unsorted part and swap it with the 1st unsorted element
        - grow the sorted portion one element at a time
    - Insertion sort
        - build the sorted list one element at a time
        - take each element and insert it into its correct position among the already sorted elements
        - efficient for small or nearly sorted datasets
- Divide and conquer algo: major efficiency improvements in the 60s
    - Merge sort
        - recursively split the list into halves until each sublist contains one element
        - merge sublist back together in sorted order, producing a fully sorted list
        - require extra space for merging
    - Quick sort
        - select a pivot element, partitions the list into elements less than/ greater than the pivot
        - recursively sort the partitions
        - fast in practice, but performance can be poor if pivots are chosen badly
- Heap sort: added stable performance regardless of input order
    - Heap sort
        - build a binary heap from the list
        - repeatedly remove the largest element from the heap and place it at the end of the list
        - efficiently maintain the heap after each removal, resulting in a sorted list
- Hybrid algo: adapt to data features and combine the best features of multiple sorts
    - Merge-insert sort: one of the hybrid algo
#### Merge-insert sort in high level
- Merge-insertion sort (Ford–Johnson algorithm, 1959) is a hybrid that combines merge sort's initial pairing with insertion sort's binary insertions. Its main distinction:
    - **Optimal for small lists**: For up to 22 elements, it uses the minimum number of comparisons possible for any comparison sort
    - **Hybrid mechanism**: Pairs elements and recursively sorts the larger ones (like merge sort), then inserts the remaining elements in a carefully chosen order using binary search (like insertion sort)
    - **Theoretical significance**: For decades, it held the record for the fewest comparisons needed for sorting small arrays. For larger arrays, newer algorithms have surpassed it, but they build on similar principles
- Practical use
    - Merge-insert sort: not used in practice for large data due to complexity and diminishing returns
    - Merge sort & Quick sort: dominate practical use for large dataset due to efficency and adapatability
    - Hybrid algo (eg. Timsort, Introsort) use insertion sort for small subarrays
#### Merge-insert sort high-level flow
- Sample: [5, 2, 8, 1, 6, 3, 9, 4, 7]
- Pairing:
    - (5,2) -> (2,5)
    - (8,1) -> (1,8)
    - (6,3) -> (3,6)
    - (9,4) -> (4,9)
    - (7) -> left unpaired
    - Pairs: [(2,5), (1,8), (3,6), (4,9), (7)]
    - Large elements: [5, 8, 6, 9]
    - Small elements: [2, 1, 3, 4]
    - Left over: [7]
- Recursive sort of large elements
    - Recursively sort [5, 8, 6, 9] using merge-insert sort algo
    - Assume it returns [5, 6, 8, 9], then it's our **sorted main chain**
- Strategic insertion of small elements
    - Use binary search on the main chain, to find a place for insertion
    - The insertion works similarly to binary insertion sort, but with a twist
        - The insertion order is dictated by math sequence called Jacobsthal numbers
    - The optimized insertion order is [1,4,2,3,7]
    - Based on binary search, insert one by one
        - insert 1: [1,5,6,8,9]
        - insert 4: [1,4,5,6,8,9]
        - insert 2: [1,2,4,5,6,8,9]
        - insert 3: [1,2,3,4,5,6,8,9]
        - insert 7: [1,2,3,4,5,6,7,8,9]

#### ```std::vector```
- A dynamic array in the CPP STL lib. It's one of the most used containers becauses it combines
    - Contiguous memory layout
    - Auto resizing
    - Convenient API
- Core features

    | Feature             | Description                                                    |
    | ------------------- | -------------------------------------------------------------- |
    | Dynamic sizing      | Grows/shrinks as needed (using `push_back`, `resize`, etc.)    |
    | Random access       | Fast `O(1)` access to elements via `[]` or `.at()`             |
    | Contiguous memory   | Elements are stored in a single, continuous block of memory    |
    | Efficient iteration | Excellent performance due to **cache locality**                |
    | STL compatible      | Works well with algorithms like `std::sort`, `std::find`, etc. |
- Key operations

    | Operation              | Complexity     | Notes                                     |
    | ---------------------- | -------------- | ----------------------------------------- |
    | `push_back()`          | Amortized O(1) | Adds element to the end                   |
    | `pop_back()`           | O(1)           | Removes last element                      |
    | `insert()` / `erase()` | O(n)           | Costly if not at the end (needs shifting) |
    | `[]` or `.at()`        | O(1)           | Random access                             |
    | `clear()`, `resize()`  | O(n)           | May involve copying or zeroing elements   |
- Memory management
    - When vector exceeds its capacity
    - It allocates a bigger block (usualy 1.5-2x the old size)
    - Copy all the existing elements to the new block
    - Delete the old block

#### ```std::deque```
- Short for double-ended queue
- A sequential container in CPP STL that allows
    - Fast insertion & deletion at both ends
    - Random access (slighly slower than vector)
- Internal structure
    - Unlike std::vector, which stores elements in contiguous memory, std::deque is usually implemented as a series of memory blocks (a segmented array) managed by a central directory.
    - This enables:
        - Constant time push/pop at both ends (O(1))
        - No reallocation of the entire container like vector when growing from the front
    - But:
        - Random access is slightly slower than vector because of the segmented memory layout. 
- Key operations

    | Operation           | Complexity | Notes                             |
    | ------------------- | ---------- | --------------------------------- |
    | `push_back()`       | O(1)       | Add element to the end            |
    | `push_front()`      | O(1)       | Add element to the beginning      |
    | `pop_back()`        | O(1)       | Remove element from the end       |
    | `pop_front()`       | O(1)       | Remove element from the beginning |
    | `operator[] / at()` | O(1)       | Random access                     |
    | `insert()/erase()`  | O(n)       | Anywhere in the middle            |

- deque vs vector

    | Feature        | `deque`                           | `vector`                          |
    | -------------- | --------------------------------- | --------------------------------- |
    | Memory layout  | Segmented blocks                  | Contiguous                        |
    | Front insert   | Fast (`O(1)`)                     | Slow (`O(n)`)                     |
    | Random access  | Fast (`O(1)`) but slightly slower | Very fast (`O(1)`)                |
    | Cache locality | Worse                             | Better                            |
    | Push back      | Fast                              | Fast (but may require reallocate) |

    - cache locality: how efficiently a program accesses data in memory with respect to the CPU cache
#### ```std::lower_bound```
- A binary search algo from the ```<algorithm>``` header
- Find the 1st position in a sorted range where a value could be inserted without breaking the order
- Function signature
    ```cpp
    template <class ForwardIt, class T>
    ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value);
    ```
- Return value
    - An iterator pointing to the 1st element that is not less than value

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