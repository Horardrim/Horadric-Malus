#include <assert.h>
#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <cmath>
#include <vector>

int solution(const std::vector<int> & input) {
    int size = input.size();
    if (size == 0)
    {
        return 0;
    }
    else if (size == 1)
    {
        return input[0];
    }
    else if (size == 2)
    {
        return std::max(input[0], input[1]);
    }

    int first = input[0];
    int second = std::max(input[0], input[1]);
    
    for (int i = 2; i < size; ++i) {
        int temp = second;
        second = std::max(first + input[i], second);
        first = temp;
    }

    return second;
}

int main(int argc, char ** argv)
{
    int ans = 0;
    std::vector<int> sampleI {1, 3, 1, 4, 2, 1};
    
    ans = solution(sampleI);
    assert(ans == 8);

    std::vector<int> sampleII {3, 1, 5, 9, 2, 1};
    ans = solution(sampleII);
    assert(ans == 13);

    std::cout << "Solution for house robber I problem is OK." << std::endl;
    return 0;
}
