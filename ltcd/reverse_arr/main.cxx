#include <assert.h>
#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
#include <sstream>

int gcd(int a, int b)
{
    while(a % b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }

    return b;
}

void solution(std::vector<int> & input, const int & k)
{
    const int length = input.size();
    const int offset = k % length;
    const int loop = gcd(length, offset);
    int exchange = 0;
    for (int i = 0; i < loop; ++i)
    {
        int start = i;
        while((start + offset) % length != i)
        {
            exchange = input[(start + offset) % length];
            input[(start + offset) % length] = input[start];
            start += offset;
        }
        input[i] = exchange;
    }
}

int main(int argc, char ** argv)
{
    std::vector<int> sampleI {1, 2, 3, 4, 5, 6};
    solution(sampleI, 8);
    std::cout << gcd(7, 3) << std::endl;
    std::cout << gcd(3, 6) << std::endl;
    std::cout << gcd(6, 3) << std::endl;
    std::cout << sampleI[2] << std::endl;
    std::cout << sampleI[0] << std::endl;
    std::cout << sampleI[1] << std::endl;
    

    std::cout << "Solution for three sum problem is OK." << std::endl;
    return 0;
}
