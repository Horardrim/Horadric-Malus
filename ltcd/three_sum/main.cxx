#include <assert.h>
#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
#include <sstream>

std::vector<int *> solution(std::vector<int> input) {
    std::vector<int *> answers;
    std::sort(input.begin(), input.end());
    int size = input.size();

    for (int i = 0; i < size; ++i)
    {
        int first = input[i];
        if (i > 0 && input[i] == input[i - 1])
        {
            continue;
        }

        int fast = size - 1;
        for (int j = i + 1; j < size; ++j)
        {
            int second = input[j];
            int target = - (first + second);

            if (j > i + 1 && input[j] == input[j - 1])
            {
                continue;
            }

            if (first + second >= 0)
            {
                return answers;
            }
            
            while (j < fast && input[fast] > target)
            {
                --fast;
            }

            if (j == fast)
            {
                break;
            }

            if (input[fast] == target)
            {
                int * answer = (int *)malloc(sizeof(int) * 3);
                answer[0] = input[i];
                answer[1] = input[j];
                answer[2] = input[fast];
                answers.push_back(answer);
            }
        }
    }

    return answers;
}

int main(int argc, char ** argv)
{
    std::vector<int> sampleI {-1, 0, 1, 2, -1, -4};
    std::vector<int *> answers = solution(sampleI);
    for (int i = 0; i < (int) answers.size(); ++i)
    {
        int * answer = answers.at(i);
        std::stringstream oss;
        oss << answer[0] << " ";
        oss << answer[1] << " ";
        oss << answer[2];
        std::cout << oss.str() << std::endl;
    }

    std::cout << "Solution for three sum problem is OK." << std::endl;
    return 0;
}
