#include "SortAlgo.hpp"

int main()
{
    std::vector<int> vec = {5,2,9,1,3,0};
    std::deque<int> deq = {5,2,9,1,3,0};

    // bubbleSort(vec);
    // bubbleSort(deq);

    // selectionSort(vec);
    // selectionSort(deq);

    insertionSort(vec);
    insertionSort(deq);
    
    printContainer(vec);
    printContainer(deq);

    return (0);
}