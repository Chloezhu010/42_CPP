#include "philo.hpp"

Philo::Philo(int id, std::mutex* left, std::mutex* right): _id(id), leftfork(left), rightfork(right)
{}
