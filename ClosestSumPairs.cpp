#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

void printValue(int i)
{
    std::cout << ' ' << i;
}

void printIntVec(std::vector<int> &input)
{
    std::for_each(input.begin(), input.end(), printValue);
    std::cout << std::endl;
}

void findClosestSumPair(int input1[], int input2[], int arraySize, int target)
{
    std::vector<int> vec1(input1, input1 + arraySize);
    std::vector<int> vec2(input2, input2 + arraySize);
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());
    printIntVec(vec1);
    printIntVec(vec2);
    std::map<int, std::vector<std::pair<int, int> > > result;

    int x = arraySize - 1;
    int y = 0;
    while (x >= 0 && y <= arraySize - 1) {
        int tmp = vec1[x] + vec2[y];
        int gap = std::abs(tmp - target);
        result[gap].push_back(std::make_pair<int, int>(vec1[x], vec2[y]));
        if (tmp == target) {
            --x;
            ++y;
        } else if (tmp < target) {
            ++y;
        } else {
            --x;
        }
    }

    auto closestPairs = result.begin()->second;
    std::cout << "Closest pairs are: " << std::endl;
    for (int i = 0; i < closestPairs.size(); ++i) {
        std::cout << closestPairs[i].first << ' ' << closestPairs[i].second << std::endl;
    }
}

int main()
{
    int input1[] = {5, 4, 8, 7};
    int input2[] = {10, 7, 1, 4};
    findClosestSumPair(input1, input2, 4, 13);
    
    return 0;
}
