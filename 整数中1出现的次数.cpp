// g++ 最小的K个数.cpp -o test -std=c++11; ./test
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; i *= 10)
        {
            int high = n / (i * 10), low = n % i;
            int curr = (n - high * i * 10) / i;
            if (curr == 0)
                ans += high * i;
            else if (curr == 1)
                ans += high * i + low + 1;
            else
                ans += (high + 1) * i;

            cout << "high: " << high << " curr: " << curr << " low: " << low << " ans: " << ans << endl;
        }
        return ans;
    }
};

int main()
{
    Solution s;

    int ans = s.NumberOf1Between1AndN_Solution(10);

    cout << ans << endl;

    return 0;
}