#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int findGCD(int input0, int input1)
{
    if (input0 == input1) {
        return input0;
    }
    int tmp0 = input0;
    int tmp1 = input1;
    int reminder0 = 0;
    int reminder1 = 0;
    int multipler = 1;
    while (reminder0 == 0 && reminder1 == 0) {
        if (tmp0 % 2 != 0 || tmp1 % 2 != 0) {
            break;
        }
        tmp0 = tmp0 / 2;
        tmp1 = tmp1 / 2;
        multipler = multipler * 2;
        reminder0 = tmp0 % 2;
        reminder1 = tmp1 % 2;
    }
    int maxValue = (tmp0 >= tmp1) ? tmp0 : tmp1;
    int minValue = (tmp0 < tmp1) ? tmp0 : tmp1;
    int minusValue = maxValue - minValue;
    while (minusValue != minValue) {
        maxValue = (minValue >= minusValue) ? minValue : minusValue;
        minValue = (minValue < minusValue) ? minValue : minusValue;
        minusValue = maxValue - minValue;
    }
    return minusValue * multipler;
}

int generalizedGCD(int num, int* arr)
{
    if (num == 1) {
        return arr[0];
    }
    vector<int> input(arr, arr + num);
    sort(input.begin(), input.end());
    int gcd = 1;
    for (int i = 1; i < num; ++i) {
        int tmpGcd = findGCD(input[0], input[i]);
        if (i == 1) {
            gcd = tmpGcd;
        } else {
            gcd = (tmpGcd < gcd) ? tmpGcd : gcd;
        }
    }
    return gcd;

}

int main()
{
    int array1[5] = {2, 4, 6, 8, 10};
    int res = generalizedGCD(5, array1);
    cout << res << endl;

    int array2[5] = {6, 3, 5, 4, 2};
    res = generalizedGCD(5, array2);
    cout << res << endl;

    int array3[5] = {8, 16, 24, 28, 34};
    res = generalizedGCD(5, array3);
    cout << res << endl;
    return 0;
}

