#include <math.h>
#include <unistd.h>

#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <unordered_map>
#include <memory>

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
    return 0;
}
