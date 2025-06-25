#include <iostream>
#include <memory>

int main()
{
    // // test unique_ptr, make_unique
    // std::unique_ptr<int> ptr = std::make_unique<int>(42);
    // std::unique_ptr<int> ptr2 (new int(21));
    // std::cout << "ptr: " << *ptr << std::endl;
    // std::cout << "ptr2: " << *ptr2 << std::endl;

    // // test copy unique_ptr, will return compilation error
    // std::unique_ptr<int> ptr4 = ptr;

    // // test move
    // std::unique_ptr<int> ptr3 = std::move(ptr); // transfer ownership
    // if (!ptr)
    //     std::cout << "Now ptr is null\n";
    // std::cout << "ptr3: " << *ptr3 << std::endl;

    // test shared_ptr
    std::shared_ptr<int> a = std::make_shared<int>(100);
    std::shared_ptr<int> b = a;
    std::shared_ptr<int> c = b;
    std::cout << "Value b: " << *b << std::endl;
    std::cout << "Count: " << b.use_count() << std::endl;
    a.reset();
    if (!b)
        std::cout << "Value b: " << *b << std::endl;
    else
        std::cout << "B is null\n";
    // b.reset();
    // if (!b)
    //     std::cout << "After rest: B is null\n";
    // c = std::make_unique<int>(42); // can change c' value, use_count also reduce
    // std::cout << "Value c: " << *c << std::endl;
    // std::cout << "Count: " << c.use_count() << std::endl;

    // // test weak_ptr
    // std::shared_ptr<int> sp = std::make_shared<int>(42);
    // std::weak_ptr<int> wp = sp; // doesn't increase ref count
    // std::cout << "use_count: " << sp.use_count() << std::endl; // 1
    // // sp.reset();
    // // std::cout << "use_count: " << sp.use_count() << std::endl;
    // std::shared_ptr<int> locked = wp.lock(); // use lock to check if shared_ptr is still alive
    // if (locked)
    //     std::cout << "Value: " << *locked << std::endl;
    // else
    //     std::cout << "Object has been deleted\n";
    // wp.reset();
    // bool expired = wp.expired();
    // std::cout << "Expired? " << expired << std::endl;
    

    
}