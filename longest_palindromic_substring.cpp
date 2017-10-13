#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        string ans;

        int l = s.size();
        if (l == 0)
            return ans;

        int lmax = 0;
        ans = s[0];
        vector<vector<int> > state(l, vector<int>(l, 0));
        for (int i = l - 1; i >= 0; i--)
        {
            state[i][i] = 1;
            for (int j = i + 1; j < l; j++)
            {
                if (j - i == 1 && s[j] == s[i])
                    state[i][j] = 1;
                else if (state[i + 1][j - 1] == 1 && s[j] == s[i])
                {
                    state[i][j] = 1;
                }

                if (state[i][j] && j - i + 1 >= lmax)
                {
                    lmax = j - i + 1;
                    ans = s.substr(i, lmax);
                }
            }
        }

        return ans;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution ss;
    string ans = ss.longestPalindrome(s);
    cout << ans << endl;

    return 0;
}
