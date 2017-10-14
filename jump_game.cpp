#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int jump(vector<int> &nums)
    {
        int l = nums.size();
        if (l == 1)
            return 0;

        int i = 0, now = 0, next = 0, ans = 0;
        while (next < l - 1)
        {
            for (; i <= now; i++)
                next = max(next, i + nums[i]);
            now = next;
            ans++;
        }
        return ans;
    }
};

int main()
{
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    cout << "Processing..." << endl;

    Solution ss;
    int ans = ss.jump(nums);
    cout << ans << endl;

    return 0;
}
