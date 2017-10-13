#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int v = 1e8, jj;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] > nums[i] && nums[j] < v)
                {
                    jj = j;
                    v = nums[j];
                }
            }

            if (v != 1e8)
            {
                swap(nums[i], nums[jj]);
                break;
            }
            else
            {
                sort(nums.begin()+i, nums.end());
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Processing..." << endl;

    Solution ss;
    ss.nextPermutation(nums);
    for (int i : nums)
        cout << i << " ";
    cout << endl;

    return 0;
}
