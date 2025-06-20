#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 2, 3};
    nums.push_back(4);  // Add element at the end
    
    auto it = std::find(nums.begin(), nums.end(), 4);
    if (it != nums.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "Not found\n";


    // for (int num : nums)
    //     std::cout << num << " ";
    return (0);
}

// #include <map>
// #include <iostream>

// int main() {
//     std::map<std::string, int> age;
//     age["Alice"] = 30;
//     age["Bob"] = 25;

//     for (auto& pair : age)
//         std::cout << pair.first << ": " << pair.second << "\n";
// }

