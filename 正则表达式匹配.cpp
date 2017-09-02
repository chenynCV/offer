#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool match(char *str, char *pattern)
    {
        cout << str << " " << pattern << endl;

        if (pattern[0] == '\0' && str[0] != '\0')
            return false;

        if (pattern[0] == '*' && pattern[1] == '\0')
            return true;

        if (pattern[1] == '\0' && str[1] == '\0' && pattern[0] == str[0])
            return true;

        if (pattern[0] == '.' || pattern[0] == str[0])
        {
            return match(str + 1, pattern + 1);
        }
        else if (pattern[0] == '*')
        {
            if (pattern[1] == '\0')
                return true;

            char *tmp = str;
            while (*tmp != '\0')
            {
                if (*tmp == pattern[1])
                    return match(tmp, pattern + 1);
                tmp++;
            }

            return false;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution s;
    char *str = "achenyanan";
    char *pattern = "chen*ya..n";
    cout << s.match(str, pattern) << endl;
    return 0;
}