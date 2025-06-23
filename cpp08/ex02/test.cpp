#include <list>
#include <iostream>
#include <stack>

int main()
{
    std::list<int> nums;
    nums.push_back(5);
    nums.push_back(17);
    nums.push_back(91);

    std::cout << *nums.begin() << std::endl;
    std::cout << *nums.end() << std::endl;

    std::cout << *nums.rbegin() << std::endl;
    std::cout << *nums.rend() << std::endl;

    std::stack<int, std::list<int>> s;
    std::cout << typeid(decltype(s)::container_type).name() << std::endl;
}