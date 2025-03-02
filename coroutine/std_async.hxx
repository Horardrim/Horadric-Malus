#include <coroutine>
#include <future>
#include <iostream>

struct AsyncFuture {
    std::future<int> result;

    struct promise_type {
        std::promise<int> promise;

        AsyncFuture get_return_object() {
            return {promise.get_future()};
        }

        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_value(int value) { promise.set_value(value); }
        void unhandled_exception() { promise.set_exception(std::current_exception()); }
    };
};
