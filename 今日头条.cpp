#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, c, num, color, count = 0;
    cin >> n >> m >> c;
    map<int, vector<int>> indexMap;
    vector<bool> flag(50, true);
    for (size_t i = 0; i < n; i++)
    {
        cin >> num;
        for (size_t j = 0; j < num; j++)
        {
            cin >> color;
            if (flag[color])
            {
                if (!indexMap[color].empty() && (i - indexMap[color].back() < m || indexMap[color].front() + n - i < m))
                {
                    count++;
                    flag[color] = false;
                }
                else if (n < m)
                {
                    count++;
                    flag[color] = false;
                }
                indexMap[color].push_back(i);
            }
        }
    }
    cout << count << endl;
    return 0;
}
