class Solution
{
  public:
    string LeftRotateString(string str, int n)
    {
        string ans(str);

        for (int i = n; i < str.size(); i++)
        {
            ans[i - n] = str[i];
        }

        for (int i = 0; i < n; i++)
        {
            ans[str.size() - n + i] = str[i];
        }

        return ans;
    }
};