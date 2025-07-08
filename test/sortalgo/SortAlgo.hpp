#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>
#include <list>

/* sorting algo */
// bubble sort
template <typename T>
void bubbleSort(T& container)
{
    size_t len = container.size();
    for (size_t i = 0; i < len - 1; i++)
    {
        for (size_t j = 0; j < len - i - 1; j++)
        {
            if (container[j] > container[j + 1])
                std::swap(container[j], container[j + 1]);
        }
    }
}

// selection sort
template <typename T>
void selectionSort(T& container)
{
    size_t len = container.size();
    for (size_t i = 0; i < len - 1; i++)
    {
        size_t min_index = i;
        for (size_t j = i + 1; j < len; j++)
        {
            if (container[j] < container[min_index])
                min_index = j;
        }
        std::swap(container[i], container[min_index]);
    }
}

// insertion sort
template <typename T>
void insertionSort(T& container)
{
    size_t len = container.size();
    for (size_t i = 1; i < len; i++)
    {
        typename T::value_type key = container[i]; // store the value before shifting
        int j = i - 1;
        while (j >= 0 && container[j] > key)
        {
            container[j + 1] = container[j]; // array right shift
            --j; // comparison left shift
        }
        container[j + 1] = key;
    }
}

// merge sort
template <typename T>
void mergeSort(T begin, T end)
{
    // if only 1 or 0 elements, no need for sorting
    if (container.size() <= 0)
        return ;
    // find the mid point
    typename T::iterator mid = container.begin() + std::distance(container.begin(), container.end()) / 2;
    // recursively sort the left and right halves
    mergeSort(container.begin(), mid);
    mergeSort(mid, container.end());
    // merge the sorted halves using temporary buffer
    T temp(container.size()); // allocate temp buffer with same size
    typename T::value_type::iterator left = container.begin();
    typename T::value_type::iterator right = mid;
    typename T::value_type::iterator end = container.end();
    while (left != mid && right != end)
    {
        if (*left < *right)
            temp.push_back(*left);
        else
            temp.push_back(*right);
        left++;
        right++;
    }
    // copy remaining elements
    temp.insert(temp.end(), left, mid);
    temp.insert(temp.end(), right, mid);
    // copy merged result back to original range
    std::move(temp.begin(), temp.end(), container.begin());
}

// quick sort
// heap sort

/* utility functions */
template <typename T>
void printContainer(T& container)
{
    auto it = container.begin();
    while (it < container.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";
}