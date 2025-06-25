#include <iostream>
#include <thread>
#include <mutex>

int count = 0;
std::mutex mtx; // declare a mutex

void increment()
{
    for (int i = 0; i < 1000; ++i)
    {
        mtx.lock(); // lock before accessing shared data
        ++count;
        mtx.unlock(); // unlock after done
    }
}

int main()
{
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "final count: " << count << std::endl;
    return 0;
}