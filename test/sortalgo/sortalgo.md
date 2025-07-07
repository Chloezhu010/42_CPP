# Sort algo in cpp
## Bubble sort
- Intro
- Core idea
- Visual example
- Pseudo code

## Selection sort
- Intro
    - Selection sort is a simple comparison-based sorting algorithm.
    - It works by repeatedly selecting the smallest (or largest) element from the unsorted portion and moving it to the correct position in the sorted portion.
- Core idea
    - For sorting an array in ascending order:
    - Divide the array into two parts: sorted and unsorted.
    - Initially, the sorted part is empty, and the unsorted part is the entire array.
    - Find the minimum element in the unsorted part.
    - Swap it with the leftmost unsorted element (i.e., put it in the sorted position).
    - Move the boundary one element to the right.
    - Repeat until all elements are sorted.
- Visual example
    - Sort [5, 2, 9, 1, 3] in ascending order: Initial array: [5, 2, 9, 1, 3]
    - Pass 1: Find min from index 0-4 → 1, swap with 5 → [1, 2, 9, 5, 3]
    - Pass 2: Find min from 1-4 → 2, already in place → [1, 2, 9, 5, 3]
    - Pass 3: Find min from 2-4 → 3, swap with 9 → [1, 2, 3, 5, 9]
    - Pass 4: Find min from 3-4 → 5, already in place → [1, 2, 3, 5, 9]
    - Now sorted
- Pseudo code
    ```
    for i from 0 to n - 1:
        min_index = i
        for j from i + 1 to n:
            if arr[j] < arr[min_index]:
                min_index = j
        swap arr[i] and arr[min_index]
    ```
## Insertion sort
- Intro
    - Insertion Sort is a simple and intuitive comparison-based sorting algorithm that builds the final sorted array one item at a time.
    - It's similar to how you might sort playing cards in your hand: Take the next card, and insert it into the correct position among the already sorted cards on your left.
    - It’s efficient for small data sets or nearly sorted data, and is often used in hybrid sorting algorithms like Timsort (Python’s built-in sort).
- Core idea
    - Start from the second element (first is trivially sorted).
    - Take the current element (key) and compare it with the elements before it.
    - Shift larger elements one position to the right to make space.
    - Insert key into its correct position in the sorted portion.
    - Repeat this for each element until the array is sorted.

- Visual example
- Pseudo code

## Merge sort
- Intro
- Core idea
- Visual example
- Pseudo code

## Quick sort
- Intro
- Core idea
- Visual example
- Pseudo code
