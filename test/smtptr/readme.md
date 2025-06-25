# Notes
## Main purpose of smart pointers in CPP
- To automatically manage dynamic memory and prevent memory leaks
### Explaination
Smart pointers in C++ (like unique_ptr, shared_ptr, and weak_ptr) are wrappers around raw pointers that:
- Automatically free memory when it's no longer needed.
- Help prevent memory leaks and dangling pointers.
- Make ownership and lifetime explicit and safer.
- Allow RAII (Resource Acquisition Is Initialization) — tying resource cleanup to object lifetime.
### Example
Without smart pointers
```cpp
int* p = new int(10);
// Must remember to delete manually
delete p;
```
With smart pointers
```cpp
std::unique_ptr<int> p = std::make_unique<int>(10);
// Automatically deleted when `p` goes out of scope
```
### Types of smart pointers

| Smart Pointer | Ownership Type             | Auto Delete | Use Case                          |
| ------------- | -------------------------- | ----------- | --------------------------------- |
| `unique_ptr`  | Exclusive                  | ✅ Yes       | Single owner of a resource        |
| `shared_ptr`  | Shared (reference counted) | ✅ Yes       | Multiple owners sharing ownership |
| `weak_ptr`    | Non-owning reference       | ❌ No        | Observing without ownership       |


## ```std::unique_ptr```
- A smart pointer in C++ that provides exclusive ownership of a dynamically allocated object
- Part of the C++11 standard library, and is defined in the header <memory>
### What it does
- Auto delete the object it manages when the unique_ptr goes out of scope
- Only one unique_ptr can own a given object at a time
- Cannot be copied, only moved
### When to use it
- Want clear ownership semantics
- Don't want to manually call delete
- Want to prevent accidental sharing of the object
### Example
```cpp
#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> ptr = std::make_unique<int>(42); // only C++14 and later
    std::unique_ptr<int> ptr2 (new int(21));

    std::cout << "ptr: " << *ptr << std::endl;
    std::cout << "ptr2: " << *ptr2 << std::endl;
}
```

## ```std::move```
- a C++ standard library function used to enable move semantics
- It transfers ownership of a resource instead of copying it
- Included in header <utility>
### Important
- std::move doesn't actually move anything by itself
- It casts the var into an rvalue reference, signaling that it can be moved from
### Why move instead of copy
- Copy is expensive: it duplicates memory or state
- Move is cheap: it transfers pointers or ownership, leaving the src in a valid but empty state
### Example with std::unique_ptr
```cpp
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> a = std::make_unique<int>(42);
    std::unique_ptr<int> b = std::move(a); // Transfer ownership from a to b

    if (!a) {
        std::cout << "a is now null." << std::endl;
    }

    std::cout << *b << std::endl;  // prints 42
}
```
Without std::move, this wouldn't compile, as unique_ptr cannot be copied

## ```std::shared_ptr```
-  a smart pointer in C++ that allows multiple ```shared_ptr```s to share ownership of the same dynamically allocated object
- When the last ```shared_ptr``` pointing to that object is destroyed or reset, the object is deleted
- included in header <memory>
### When to use
- When multiple parts of your code need access to the same resource, and you don't want to manage its lifetime manually
- When ownership is not exclusive
### Key functions

| Function / Method          | Purpose                                                   |
| -------------------------- | --------------------------------------------------------- |
| `std::make_shared<T>(...)` | Allocates and returns a `shared_ptr<T>`                   |
| `ptr.use_count()`          | Returns how many `shared_ptr`s own the object             |
| `ptr.reset()`              | Releases ownership (and deletes if count = 0)             |
| `ptr.get()`                | Returns the raw pointer (not recommended to use directly) |

### Example
```cpp
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> a = std::make_shared<int>(100);  // allocate and manage int(100)
    std::shared_ptr<int> b = a;  // now a and b share ownership

    std::cout << "Value: " << *a << ", use_count: " << a.use_count() << std::endl;

    b.reset();  // b gives up ownership
    std::cout << "After reset, use_count: " << a.use_count() << std::endl;
}
```
### Important
Avoid shared_ptr cycles, which can cause memory leaks
```cpp
struct A;
struct B;

struct A {
    std::shared_ptr<B> b_ptr;
};

struct B {
    std::shared_ptr<A> a_ptr;
};
```
This will never free memory unless you break the cycle using ```std::weak_ptr```

## ```std::weak_ptr```
- A non-owning smart pointer that references a shared_ptr - managed object without increasing its reference count
- Use it to observe / access a shared resource without extending its lifetime
- ```std::weak_ptr``` is essential when using ```std::shared_ptr``` to avoid memory leaks due to circular references
### Why use it
- If two objects hold shared_ptrs to each other (a circular reference), the reference count never reaches 0 → memory leak
- weak_ptr breaks the cycle because it does not increase the reference count
### Example
```cpp
#include <iostream>
#include <memory>

class B;

class A {
public:
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::weak_ptr<A> a_ptr; // 👈 weak_ptr prevents circular ownership
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->b_ptr = b;
    b->a_ptr = a;  // weak_ptr here breaks the cycle

    // both A and B will be destroyed correctly
}
```
### Key methods

| Method        | Description                                             |
| ------------- | ------------------------------------------------------- |
| `lock()`      | Returns a `shared_ptr` if object is still alive         |
| `expired()`   | Returns true if the managed object is gone              |
| `reset()`     | Releases the reference                                  |
| `use_count()` | Shows how many `shared_ptr`s are pointing to the object |
