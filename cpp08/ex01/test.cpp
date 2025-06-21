#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

int main()
{
    std::vector<int> nums = {7, 21, 2, 10, 4};
    std::vector<int> temp = nums;
    std::vector<int> output(temp.size());

    std::sort(temp.begin(), temp.end());
    // for (int i = 0; i < 5; i++)
    //     std::cout << nums[i] << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << temp[i] << ", ";

    int min = temp[1] - temp[0];
    for (int i = 1; i < 3; i++)
    {
        if (min >= temp[i + 1] - temp[i])
            min = temp[i + 1] - temp[i];
    }
    std::cout << "min: " << min << std::endl;
    
    // std::adjacent_difference(temp.begin(), temp.end(), output.begin());
    // std::cout << "\nafter\n";
    // for (int i = 0; i < 5; i++)
    //     std::cout << output[i] << ", ";

}
