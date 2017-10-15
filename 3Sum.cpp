#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int a = nums[i];
            if (a > 0)
                break;
            if (ans.size() >= 1 && ans[ans.size() - 1][0] == a)
                continue;
            int sum = -a;
            int s = i + 1, t = nums.size() - 1;
            while (s < t)
            {
                if (nums[s] + nums[t] < sum)
                    s++;
                else if (nums[s] + nums[t] > sum)
                    t--;
                else
                {
                    int b = nums[s], c = nums[t];
                    if (a + b + c == 0)
                    {
                        if (!(ans.size() >= 1 && ans[ans.size() - 1][0] == a && ans[ans.size() - 1][1] == b))
                            ans.push_back({a, b, c});
                    }
                    s++;
                }
            }
        }
        // sort(ans.begin(), ans.end());
        // ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
