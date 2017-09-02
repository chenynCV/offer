#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    void replaceSpace(char *str, int length)
    {
        int spaceNum = 0;
        int len = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            len++;
            if (str[i] == ' ')
                spaceNum++;
        }
        cout << len << endl;
        cout << spaceNum << endl;

        int lenNow = len + 2 * spaceNum;
        if (lenNow > length)
            return;
        for (int i = len; i >= 0; i--)
        {
            cout << str[i] << endl;

            if (str[i] == ' ')
            {
                str[lenNow--] = '0';
                str[lenNow--] = '2';
                str[lenNow--] = '%';
            }
            else
            {
                str[lenNow--] = str[i];
            }
        }
    }
};

int main()
{
    Solution s;
    int length = 50;
    char *str = new char[length];
    strcpy(str, "we are happy");
    s.replaceSpace(str, length);
    cout << str << endl;
    delete[] str;
    return 0;
}