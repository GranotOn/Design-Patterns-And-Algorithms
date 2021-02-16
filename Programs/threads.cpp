#include "thread"
#include "string"
#include "iostream"
#include "mutex"
#include "atomic"

static const int NUM_THREADS = 5;
std::mutex mtx;
std::atomic<int> cnt{0};

void call_from_thread(int tid)
{
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Launched by thread " << tid << std::endl;
}


void call_from_thread2(int tid)
{
    while (cnt != tid)
        std::this_thread::yield();
    std::cout << "Launched by thread " << tid << std::endl;
    ++cnt;
}

int main()
{

    std::thread t[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        t[i] = std::thread(call_from_thread2, i);
    }

    std::cout << "Launched from main" << std::endl;

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        t[i].join();
    }

    return 0;
}