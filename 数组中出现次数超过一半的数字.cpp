// g++ 数组中出现次数超过一半的数字.cpp -o test -std=c++11; ./test
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int ans = 0;
        sort(numbers.begin(), numbers.end());
        // for (auto i : numbers)
        //     cout << i <<' ';
        // cout << endl;

        int minCnt = numbers.size() % 2 == 0 ? numbers.size() / 2 : numbers.size() / 2 + 1;
        for (int i = 0; i < minCnt; i++)
        {
            if (numbers[i] == numbers[i + minCnt - 1])
                return numbers[i];
        }

        return ans;
    }
};

int main()
{
    vector<int> numbers = {1, 2, 3, 2, 2, 2, 5, 4, 2};

    Solution s;
    int ans = s.MoreThanHalfNum_Solution(numbers);
    cout << ans << endl;

    return 0;
}