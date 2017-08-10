// g++ 最小的K个数.cpp -o test -std=c++11; ./test
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string PrintMinNumber(vector<int> numbers)
    {
        string ansStr;
        if(numbers.empty())
            return ansStr;

        vector<int> ans;
        ans.push_back(numbers[0]);
        for (int i = 1; i < numbers.size(); i++)
        {
            ans.push_back(numbers[i]);
            for (int j = ans.size() - 1; j > 0; j--)
            {
                if (permuteValue(ans[j - 1], ans[j]) > permuteValue(ans[j], ans[j - 1]))
                    swap(ans[j - 1], ans[j]);
                else
                    break;
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            ansStr += to_string(ans[i]);
            cout << ans[i] << endl;
        }

        return ansStr;
    }

    long long int permuteValue(int a, int b)
    {
        int i = 1;
        while (i <= b)
            i *= 10;

        return a * i + b;
    }
};

int main()
{
    vector<int> numbers = {3, 32, 321};
    Solution s;
    cout << s.PrintMinNumber(numbers) << endl;
    return 0;
}