#include "std_async.hxx"
#include "std_suspend.hxx"

SimpleCoroutine simple_coroutine() {
    std::cout << "Coroutine started\n";
    co_await std::suspend_always{};
    std::cout << "Coroutine resumed\n";
}

AsyncFuture async_task() {
    std::cout << "Async task started\n";
    co_await std::suspend_always{};
    std::cout << "Async task resumed\n";
    co_return 42;
}

int main(int argc, char ** argv)
{
    return 0;
}
