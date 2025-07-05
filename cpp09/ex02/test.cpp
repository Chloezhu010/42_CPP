#include "PmergeMe.hpp"

std::vector<size_t> getJacobIndice(size_t n)
{
    std::set<size_t> used;
   std::vector<size_t> result;
   
   // generate jacobsthal nbr
   size_t j0 = 0;
   size_t j1 = 1;
   while (j1 < n)
   {
        result.push_back(j1);
        used.insert(j1);
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;    
   }
   // add remaining indice
   for (size_t i = 0; i < n; i++)
   {
        if (used.find(i) == used.end())
            result.push_back(i);
   }
   result.erase(result.begin());
    
    // std::vector<size_t> result;
       
    // if (n == 0)
    //     return (result);
    // /* - generate jacobsthal nbr up to next <= n
    //    - store it in the jacob container 
    // */
    // std::vector<size_t> jacob;
    // jacob.push_back(0);
    // if (n >= 1)
    //     jacob.push_back(1);
    // for (size_t i = 2; ; i++)
    // {
    //     size_t next = jacob[i - 1] + jacob[i - 2] * 2;
    //     if (n <= next)
    //         break ;
    //     jacob.push_back(next);
    // }
    // /* generate the insertion indice */
    // for (size_t j = 2; j < jacob.size(); j++)
    //     result.push_back(jacob[j]);
    // result.push_back(0);
    // // fill in the rest of the indice
    // for (size_t k = 0; k < n; k++)
    // {
    //     std::vector<size_t>::iterator it = std::find(jacob.begin(), jacob.end(), k);
    //     if (it == jacob.end())
    //         result.push_back(k);
    // }
    return (result);
}

void splitPairVec(const std::vector<int> &input, std::vector<int> &main, 
                    std::vector<int> &pend, int &leftover)
{
    // if (input.size() == 2)
    // {
    //     if (input[0] > input[1])
    //     {
    //         main.push_back(input[0]);
    //         pend.push_back(input[1]);
    //     }
    //     else
    //     {
    //         main.push_back(input[1]);
    //         pend.push_back(input[0]);
    //     }
    // }
    // else
    // {
    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
        {
            main.push_back(input[i]);
            pend.push_back(input[i + 1]);
        }
        else
        {
            main.push_back(input[i + 1]);
            pend.push_back(input[i]);
        }
    }
        // std::vector<int>::const_iterator it = input.begin();
        // /* loop through the input numbers */
        // while ((it + 1) != input.end())
        // {
        //     if (*it > *(it + 1))
        //     {
        //         main.push_back(*it);
        //         pend.push_back(*(it + 1));
        //     }
        //     else
        //     {
        //         main.push_back(*(it + 1));
        //         pend.push_back(*it);
        //     }
        //     it += 2;
        // }
    // }
    /* check the last item */
    if (input.size() % 2 != 0)
        leftover = input.back();
    else
        leftover = -1;
}

void printVec(std::vector<int> &input)
{
    std::cout << "Print vector: \n";
    std::vector<int>::iterator it = input.begin();
    while (it != input.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";
}

void binaryInsertVec(std::vector<int> &sorted, int value)
{
    // find the insertion position
    size_t start = 0;
    size_t end = sorted.size();
    size_t mid;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (sorted[mid] < value)
            start = mid + 1;
        else
            end = mid;
    }
    // insert the value
    sorted.insert(sorted.begin() + start, value);
}

void sortVecRecursive(std::vector<int> &data)
{
    std::vector<int> main;
    std::vector<int> pend;
    int leftover;
    std::vector<size_t> insert_index;
    
    // split the input
    splitPairVec(data, main, pend, leftover);
    std::cout << "main: "; printVec(main); //debug
    std::cout << "pend: "; printVec(pend); //debug
    std::cout << "leftover: " << leftover << "\n"; //debug
    // get insertion order
    insert_index = getJacobIndice(pend.size());
    std::cout << "pend size: " << pend.size() << "\n"; //debug
    // loop through pend to insert using binaryInsert
    for (size_t i = 0; i < insert_index.size(); i++)
    {
        size_t index = insert_index[i];
        std::cout << "index: " << index << "\n"; //debug
        int value = pend[index];
        std::cout << "insert value: " << value << "\n"; //debug
        binaryInsertVec(main, value);
    }
    // insert leftover if there is
    if (leftover != -1)
        binaryInsertVec(main, leftover);
    data = main;
}

int main(int ac, char **av)
{
    // if (ac <= 2)
    // {
    //     std::cerr << "Error: Need at least two number to sort\n";
    //     return (1);
    // }
    
    // for (int i = 1; i < ac; i++)
    // {
    //     std::istringstream iss(av[i]);
    //     int nb;

    //     if (iss >> nb)
    //     {
    //         if (nb > 0 )
    //             std::cout << nb << "\n";
    //     }
    //     else
    //         std::cerr << "Error: invalid input\n";
    // }

    std::cout << "----Test getJacobIndice----\n";
    (void)ac;
    (void)av;
    size_t n = 4;
    std::vector<size_t> res = getJacobIndice(n);
    std::vector<size_t>::iterator it = res.begin();
    while (it != res.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";

    std::cout << "\n----Test splitPairVec----\n";
    std::vector<int> input = {5, 2,8,1,6,3,9,4,7};
    std::vector<int> main = {};
    std::vector<int> pend = {};
    int leftover;
    splitPairVec(input, main, pend, leftover);
    // debug print
    printVec(input);
    printVec(main);
    printVec(pend);
    std::cout << "leftover: " << leftover << "\n";

    // std::cout << "\n----Test binaryInsertVec----\n";
    // std::vector<int> sorted = {5, 6, 8, 9};
    // std::vector<int> pending = {2, 1, 3, 4};
    // int left = 7;
    // /* using std::lower_bound */
    // // std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), 4);
    // // sorted.insert(pos, 4);
    // /* using handmade binaryInsertVec function */
    // binaryInsertVec(sorted, 12);
    // printVec(sorted);

    // std::cout << "\n----Test sortVecRecursive----\n";
    // // std::vector<int> input = {5, 2, 8, 1, 6, 3, 9, 4, 7};
    // // printVec(input);

    // sortVecRecursive(input);
    // printVec(input);

    return (0);
}