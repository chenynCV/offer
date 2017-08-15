// g++ 滑动窗口的最大值.cpp -o test -std=c++11; ./test
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        vector<int> ans;
        deque<pair<int, int>> q;

        if (size == 0)
            return ans;
            
        for (int i = 0; i < num.size(); i++)
        {
            while (!q.empty() && q[0].first < int(i - size + 1))
                q.pop_front();

            for (auto k : q)
                cout << k.second << " ";
            cout << endl;

            while (!q.empty() && q.back().second < num[i])
                q.pop_back();
            q.push_back(make_pair(i, num[i]));

            for (auto k : q)
                cout << k.second << " ";
            cout << endl;

            if (i + 1 >= size)
                ans.push_back(q[0].second);
        }

        return ans;
    }
};

int main()
{
    vector<int> num = {2, 3, 4, 2, 6, 2, 5, 1};

    Solution s;
    vector<int> ans = s.maxInWindows(num, 3);

    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}