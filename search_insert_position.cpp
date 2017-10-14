#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
            return 0;
        else if (target > nums[nums.size() - 1])
            return nums.size();

        int s = 0, t = nums.size() - 1, mid;
        while (t - s > 1)
        {
            mid = (s + t) / 2;
            if ((target - nums[s]) * (target - nums[mid]) <= 0)
                t = mid;
            else
                s = mid;
        }

        if (nums[s] == target)
            return s;
        else
            return t;
    }
};

int main()
{
    int N, target;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    cin >> target;

    cout << "Processing..." << endl;
    Solution ss;
    int ans = ss.searchInsert(nums, target);
    cout << ans << endl;

    return 0;
}
