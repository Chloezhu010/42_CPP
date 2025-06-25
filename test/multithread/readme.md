# Multithread in cpp
## What's multithreading in cpp
Multithreading allows a program to execute multiple parts (threads) concurrently. Each thread can run a different task at the same time, potentially on different CPU cores.

Why use it?
- To improve performance on multi-core processors.
- To handle multiple tasks like I/O, computation, and user interface simultaneously.

## What's a mutex
A mutex (mutual exclusion) is used to prevent multiple threads from accessing shared resources at the same time, which would cause data races or corruption
### Example
```cpp
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx; // declare a mutex

void increment() {
    for (int i = 0; i < 10000; ++i) {
        mtx.lock();         // lock before accessing shared data
        ++counter;          // critical section
        mtx.unlock();       // unlock after done
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final counter: " << counter << std::endl;
    return 0;
}
```
## Better use ```std::lock_guard```
To avoid forgetting ```unlock()```, use RAII-style locking:
```cpp
std::lock_guard<std::mutex> lock(mtx);  // automatically locks and unlocks
++counter;
```
Updated the increment() becomes:
```cpp
void increment()
{
    for (int i = 0; i < 1000; i++)
    {
        std::lock_guard<std::mutex> lock(mutx);
        ++count;
    }
}
```
## What's RAII in cpp
RAII stands for Resource Acquisition Is Initialization.

It’s a C++ idiom where a resource (like memory, file handles, mutex locks, etc.) is acquired in a constructor and automatically released in the destructor.

This helps prevent leaks, bugs, and forgetting to release resources — especially useful in multithreading.
### Examples of RAII in cpp
| Resource | RAII Wrapper                          |
| -------- | ------------------------------------- |
| Memory   | `std::unique_ptr`, `std::shared_ptr`  |
| File     | `std::fstream`                        |
| Mutex    | `std::lock_guard`, `std::unique_lock` |
| Thread   | `std::jthread` (C++20)                |

### Benefits of RAII
- Auto resource mgmt
- Safer code (less chance of leaks or crashes)
- Make C++ exception-safe

## Deadlock
A deadlock occurs when two or more threads are waiting for each other to release resources, and none of them can proceed.
### Typical deadlock behavior
Each thread holds a resource and waits for another resource held by another thread, creating a cycle of dependency with no way to resolve it.
### How to avoid deadlock in cpp
1. Consistent lock ordering

2. Use ```std::scoped_lock```
    
    ```std::scoped_lock``` uses a mechanism like ```std::lock()``` under the hood, which locks multiple mutexes without risking deadlock.

    ```cpp
    #include <mutex>

    std::mutex mtx1, mtx2;

    void safe_function() {
        std::scoped_lock lock(mtx1, mtx2); // Locks both safely
        // Critical section
    }
    ```
3. Use ```std::lock()``` with ```std::unique_lock```
    
    Manually lock multiple mutexes atomically.
    ```std::lock()``` locks all mutexes at once in a way that avoids deadlock, and ```unique_lock``` allows manual unlocks later.
    ```cpp
    #include <mutex>

    std::mutex mtx1, mtx2;

    void safe() {
        std::unique_lock<std::mutex> l1(mtx1, std::defer_lock);
        std::unique_lock<std::mutex> l2(mtx2, std::defer_lock);
        std::lock(l1, l2); // Deadlock-safe locking
    }
    ```
4. Timeout locks (```try_lock```)
    
    Use ```try_lock()``` to avoid indefinite blocking — back off if lock can't be acquired.

    Prevent deadlock by not waiting forever.
    ```cpp
    if (mtx1.try_lock()) {
        if (mtx2.try_lock()) {
            // Safe: both locked
            mtx2.unlock();
        }
        mtx1.unlock();
    }
    else {
        // Couldn't get mtx1; try later
    }
    ```
    What it does
    - It tries to acquire the mutex lock immediately
    - If the mutex is available, it locks it and returns true.
    - If the mutex is already locked by another thread, it returns false immediately instead of waiting.

## ```std::mutex```

| Concept            | What it does                                                              |
| ------------------ | ------------------------------------------------------------------------- |
| `std::mutex`       | Prevents multiple threads from entering a critical section simultaneously |
| `lock()`           | Locks the mutex (waits if already locked)                                 |
| `unlock()`         | Unlocks the mutex                                                         |
| `std::lock_guard`  | Safer way to manage mutex via RAII                                        |
| `std::unique_lock` | More flexible than `lock_guard` (can unlock/relock)                       |

## ```std::thread```

| Concept       | Meaning                                        |
| ------------- | ---------------------------------------------- |
| `std::thread` | Launches a new thread in C++                   |
| `join()`      | Waits for the thread to finish                 |
| `detach()`    | Lets the thread run freely in the background   |
| `joinable()`  | Checks if the thread is joinable               |
| `std::ref`    | Used to pass arguments by reference to threads |


## ```std::unique_lock```
```std::unique_lock<std::mutex>``` is a flexible RAII-style mutex locker, similar to ```std::lock_guard```, but with more control.
### Basic usage
Just like ```std::lock_guard```, this ensures the mutex is locked and released safely
```cpp
std::unique_lock<std::mutex> lock(mtx);
// critical section
// unlocks automatically when `lock` goes out of scope
```
### When to use unique_lock over lock_guard
1. You need to manually unlock and relock
    ```cpp
    std::unique_lock<std::mutex> lock(mtx);
    doSomething();
    // temporarily unlock the mutex
    lock.unlock();
    // do non-critical work
    lock.lock();
    // critical section again
    ```
    ```std::lock_guard``` does not allow this — it's always locked for its entire lifetime

 2. You need to use ```std::condition_variable```
    ```cpp
    std::mutex mtx;
    std::condition_variable cv;

    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock); // unlocks the mutex while waiting, then locks again
    ```
    ```std::condition_variable::wait()``` requires a ```unique_lock``` — not compatible with ```lock_guard```
