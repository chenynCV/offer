#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<string> Permutation(string str)
    {
        vector<string> ans;
        if (str.empty())
            return ans;

        int cnt[128] = {0};
        for (auto i : str)
        {
            cnt[i]++;
        }

        string now;
        Permutation_kth(ans, now, cnt, 0, str.size());

        return ans;
    }

    void Permutation_kth(vector<string> &ans, string &now, int cnt[], int k, int size)
    {
        if (now.size() >= size)
        {
            ans.push_back(now);
            return;
        }

        for (int i = 0; i < 128; i++)
        {
            if (cnt[i] > 0)
            {
                cnt[i]--;
                now.push_back(i);
                Permutation_kth(ans, now, cnt, k + 1, size);
                now.pop_back();
                cnt[i]++;
            }
        }

        return;
    }
};

int main()
{
    string str = "ab";

    Solution s;
    vector<string> ans = s.Permutation(str);

    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}
