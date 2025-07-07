#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>
#include <list>

/* sorting algo */
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

template <typename T>
void insertionSort(T& container)
{

}

// merge sort
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