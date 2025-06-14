#include <math.h>
#include <unistd.h>

#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <unordered_map>
#include <memory>
#include <future>

long double operator"" _deg(long double deg)
{
        return deg * M_PI / 180.0;
};

int main(int argc, char ** argv)
{
    std::cout << "current cplusplus standard is:" << std::endl;
    std::cout << __cplusplus << std::endl;
    std::cout << std::endl;

    /*
     * I. auto key word
     */
    auto a = 10;
    auto y = 3.14;
    auto v = {1, 2, 3};
    (void) a;
    (void) y;
    (void) v;

    /*
     * II. Uniform Initialization
     */
    int b{10};
    double c{3.14};
    std::vector<int> v2 {1, 2, 3};
    (void) b;
    (void) c;

    /*
     * III. Range-based for Loop
     */
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    /*
     * IV. Lambda expression
     */
    auto add = [](int a, int b) { return a + b; };
    std::cout << add(5, 6) << std::endl;

    // usage of value capture
    int value = 10;
    auto lambdaI = [value]() {
        std::cout << "Captured value: " << value << std::endl;
    };

    value = 20;  // 改变原始值
    lambdaI();    // 输出：Captured value: 10

    // reference capture
    auto lambdaII = [&value]() {
        value = 30;  // 修改原始值
    };

    lambdaII();
    std::cout << "Modified value: " << value << std::endl;
    /*
     * V. nullptr
     */
    int * ptr = nullptr;
    if (ptr == nullptr) {
        std::cout << "Pointer is null" << std::endl;
    }

    /*
     * VI. Move Semantics
     */
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = std::move(vec1);
    std::cout << "vec1 length: " << vec1.size() << std::endl;
    std::cout << "vec2 length: " << vec2.size() << std::endl;

    /*
     * VII. Concurrency
     * std::thread, std::mutex, std::condition_variable
     */
    auto print = [](int a) {
        std::cout << "sleeping for " << a << " seconds..." << std::endl; 
        sleep(a);
    };
    std::thread t1 (print, 10);
    t1.join();

    /*
     * VIII. std::array、std::tuple、std::function、std::shared_ptr、std::unique_ptr
     */
    std::array<int, 3> arrI = {1, 2, 3};
    std::tuple<int, double, std::string> t = {1, 3.14, "Hello"};
    std::function<int(int, int)> addI = [](int a, int b) { return a + b; };
    (void) arrI;

    /*
     * IX. User defined Literals
     */
    std::cout << 90.0_deg << std::endl;

    /*
     * X. new algorithm like std::all_of, std::any_of, std::none_of, std::copy_if
     */
    std::vector<int> vec_ = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> filtered;

    // 使用 std::copy_if 过滤出偶数
    std::copy_if(vec_.begin(), vec_.end(), std::back_inserter(filtered), [](int x) {
        return x % 2 == 0;
    });

    // 输出过滤后的结果
    for (int num : filtered) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    /*
     * XI. std::bind、std::make_shared
     */
    auto sp = std::make_shared<int>(10);
    
    std::cout << *sp << " " << std::endl;

    /*
     * XII. std::unordered_map
     * std::unordered_map is based on hash table O(1) and std::map is based on red-black tree.O(logN)
     */
    std::unordered_map<int, std::string> umap = {{1, "one"}, {2, "two"}};
    std::cout << umap[1] << std::endl;  // 输出 one

    /*
     * XIII. decltype
     * decltype can get a type of a variable and keep refer and const which 'auto' will not keep
     * int& ref = a;
     * decltype(ref) c = a;  // type of c is int&
     */

    /*
     * XIV. std::future
     * std::future可以通过std::promise，std::async，std::packaged_task启动
     */

    auto async_task = [](int a, int b) -> int {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return a + b;
    };

    /** std::async启动任务 **/

    // 启动异步任务
    std::future<int> result = std::async(std::launch::async, async_task, 5, 6);

    // 执行其他操作
    std::cout << "Waiting for result..." << std::endl;

    // 阻塞当前线程，直到异步任务的结果返回
    int task_result = result.get();
    std::cout << "Result: " << task_result << std::endl;


    /** std::promise **/
    auto promise = [](std::promise<int> prom, int a, int b) -> void {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        prom.set_value(a + b);
    };

    // 创建一个 promise 对象
    std::promise<int> prom;
    // 获取与 promise 关联的 future
    std::future<int> prom_result = prom.get_future();

    // 启动一个线程来执行异步任务
    std::thread t2(promise, std::move(prom), 4, 5);
    // 执行其他操作
    std::cout << "Waiting for promise result..." << std::endl;

    // 获取异步任务的结果
    int promise_val = prom_result.get();
    std::cout << "Promise Result: " << promise_val << std::endl;

    // 调用join确保线程被回收
    t2.join();

    return 0;
}
