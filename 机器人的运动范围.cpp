#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<int>> color(rows, vector<int>(cols, 0));

        return moveNext(threshold, rows, cols, color, 0, 0);
    }

    int moveNext(const int threshold, const int rows, const int cols,
                 vector<vector<int>> &color, int i, int j)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols || color[i][j] == 1)
            return 0;

        int sum = 0;
        int k;
        for (k = i; k > 0; k = k / 10)
            sum += k % 10;
        for (k = j; k > 0; k = k / 10)
            sum += k % 10;

        if (sum > threshold)
            return 0;

        color[i][j] = 1;

        return moveNext(threshold, rows, cols, color, i - 1, j)
        + moveNext(threshold, rows, cols, color, i + 1, j)
        + moveNext(threshold, rows, cols, color, i, j - 1)
        + moveNext(threshold, rows, cols, color, i, j + 1)
        + 1;
    }
};
