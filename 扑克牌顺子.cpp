// g++ 最小的K个数.cpp -o test -std=c++11; ./test
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool IsContinuous(vector<int> numbers)
    {
        if (numbers.empty())
            return false;

        sort(numbers.begin(), numbers.end());
        int numGod = 0;
        while (numbers[numGod] == 0)
            numGod++;
        cout << numGod << endl;

        for (int i = numGod; i < numbers.size() - 1; i++)
        {
            if (numbers[i] == numbers[i + 1])
                return false;
        }
        cout << "no same number" << endl;

        cout << numbers[numbers.size() - 1] - numbers[numGod] - numGod << endl;
        cout << numbers.size() - numGod << endl;       
        if (int(numbers[numbers.size() - 1] - numbers[numGod] - numGod) < int(numbers.size() - numGod))
            return true;

        return false;
    }
};

int main()
{
    vector<int> numbers = {0, 0, 0, 0, 3};
    Solution s;
    cout << s.IsContinuous(numbers) << endl;
}