#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    void reOrderArray(vector<int> &array)
    {
        for (int i = 0; i < int(array.size() - 1); i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (array[j + 1] % 2 == 1 && array[j] % 2 == 0)
                    swap(array[j + 1], array[j]);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> array = {};
    s.reOrderArray(array);
    for (auto i : array)
        cout << i << ' ';
    cout << endl;
    return 0;
}