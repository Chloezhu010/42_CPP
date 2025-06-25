Logging System (Producer-Consumer)

✅ Concepts:
Thread communication

Condition variables

Queue protected by mutex

📝 Description:
Implement a logger where multiple threads (producers) push messages to a thread-safe queue, and one consumer thread logs them to stdout.

🔨 Features:
Shared std::queue<std::string>

Use std::mutex + std::condition_variable

std::unique_lock for flexible control of locking/unlocking