#include <assert.h>
#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
#include <sstream>

int solution(const std::vector<int> & stocks)
{
    if (stocks.size() == 0)
    {
        return 0;
    }

    int max_profit = 0;
    int current_hold = 0;
    for (int i = 1; i < (int) stocks.size(); ++i)
    {
        if (stocks[i] < stocks[current_hold])
        {
            current_hold = i;
            continue;
        }

        if (stocks[i] - stocks[current_hold] > max_profit)
        {
            max_profit = stocks[i] - stocks[current_hold];
        }
    }

    return max_profit;
}

int main(int argc, char ** argv)
{
    std::vector<int> stocks {1, 2, 9, 5, 3, 6};
    int profit = solution(stocks);
    assert(profit == 8);

    std::vector<int> stocksI {3, 4, 9, 2, 3, 6};
    profit = solution(stocksI);
    assert(profit == 6);
    return 0;
}
