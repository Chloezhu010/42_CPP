#include <iostream>
#include <thread>
#include <memory>
#include <chrono> // for std::chrono

class Philo
{
    public:
        int         _id;
        std::mutex  *leftfork;
        std::mutex  *rightfork;
        std::thread th;
        int         eatCount = 0;
        std::chrono::time_point<std::chrono::steady_clock> lastMeal;
        Philo(int id, std::mutex* left, std::mutex* right);

        void        start();
        void        lifeCycle();
};