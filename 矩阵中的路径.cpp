// g++ 滑动窗口的最大值.cpp -o test -std=c++11; ./test
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        vector<vector<int>> color(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (ishasPath(matrix, rows, cols, str, color, i, j))
                    return true;
            }
        }

        return false;
    }

    bool ishasPath(char *matrix, int rows, int cols, char *str, vector<vector<int>> &color, int i, int j)
    {
        if (strlen(str) == 0)
            return true;

        if (color[i][j] == 0 && matrix[i * cols + j] == *str)
        {
            if (strlen(str) == 1)
                return true;
            color[i][j] = 1;
            bool flag = false;
            if (i + 1 < rows)
                flag |= ishasPath(matrix, rows, cols, str + 1, color, i + 1, j);
            if (i - 1 >= 0)
                flag |= ishasPath(matrix, rows, cols, str + 1, color, i - 1, j);
            if (j + 1 < cols)
                flag |= ishasPath(matrix, rows, cols, str + 1, color, i, j + 1);
            if (j - 1 >= 0)
                flag |= ishasPath(matrix, rows, cols, str + 1, color, i, j - 1);
            color[i][j] = 0;
            return flag;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    char matrix[] = "abcesfcsadee";
    char str[] = "abcb";

    Solution s;
    bool ans = s.hasPath(matrix, 4, 3, str);

    cout << ans << endl;
    return 0;
}