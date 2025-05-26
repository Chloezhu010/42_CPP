# 42_CPP
## CPP00
### ex00
- Write a simple c++ program, without any class
- Get familliar to std::cout, std::endl

### ex01
- Create a phonebook, that can store up to 8 contacts, and display the stored info during runtime
- Contact class: store individual contact info
- PhoneBook class: manage the collection of contacts
- main.cpp: handle user input & program flow

### ex02
- Re-engineer the Account.cpp, based on the existing Account.hpp, tests.cpp and result log

## CPP01
### ex00
- Class creation: Create a Zombie class that represents a zombie entity
- Object instantiation: 2 ways to create zombie objects
    - On the stack: memory allocated auto, release when out of scope
    - On the heap: manual memory allocate with new, must be freed with delete
- Member functions: The class will have member functions to give the zombie a name and make it announce itself
    - newZombie: create a zombie on the heap
    - randomChump: create a zombie on the stack

### ex01
- Dynamic memory allocation for creating multiple zommbie objects
- Function: Zombie* zombieHorde( int N, std::string name )
    - Create N zombies objects in a single allocation
    - Give each zombie a specific name
    - Return a ptr to the 1st zombie
- Show horde works by having each zombie announce itself
- Cleanup all allocated memory

### ex02
- Intro to ptr vs reference, memory address, string manipulation

### ex03
- Intro to ptr to member functions
- reference to member functions needs to be initialized immediately
- ptr to member functions doesn't require immediate initialization

### ex04
- Intro to file i/o, string manipulation, error handling

### ex05
- Intro to ptr to member functions

### ex06
- Cmd line arg handling
- Switch statements with fall-through behavior
- Message filter based on the level

## CPP02
### ex00
- Implement a simple fixed-point number class
    - _value stores the number internally as an int, which is a scaled version of the real number
        - eg. to store 3.25, multiple by 2^8, so _value = 832
        - to retrieve the original nbr, float real = _value / 256.0f = 3.25
    - _bits defines how many bits are used for the fractional part
        - static: shared by all instances of Fixed
        - const: cannot be changed
### ex01
- Convert between int and float

### ex02
- Overload +-*/
- Overload prefix/ postfix ++/--

### ex03
- Use Binary Space Partitioning (BSP) for point-in-triangle test

## CPP03
- Inheritance
    - create a new child class from an existing parent class
    - inherit all public and protected attributes and methods of the parent
    - able to override or extend behaviour
- ex00
- ex01
- ex02