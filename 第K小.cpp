// g++ 第K小.cpp -o test -std=c++11; ./test
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int find_kth(vector<int> in, int k)
    {
        return find_kth_minimal(in, 0, in.size(), k);
    }

    int find_kth_minimal(vector<int> &in, int s, int t, int k)
    {
        if (s + 1 >= t)
            return in[s];

        int i, j;
        for (i = j = s + 1; j < t; j++)
            if (in[j] < in[s])
                swap(in[i++], in[j]);
        swap(in[s], in[--i]);

        for (auto v : in)
            cout << v << " ";
        cout << endl;

        int len = i - s + 1;
        if (k == len)
            return in[i];
        else if (k < len)
            return find_kth_minimal(in, s, i + 1, k);
        else
            return find_kth_minimal(in, i + 1, t, k - len);
    }
};

int main()
{
    vector<int> in = {6, 5, 3, 1, 2, 4};
    Solution s;
    int ans = s.find_kth(in, 5);
    cout << ans << endl;
    return 0;
}