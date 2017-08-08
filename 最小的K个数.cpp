// g++ 最小的K个数.cpp -o test -std=c++11; ./test
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        if (input.empty())
        {
            return input;
        }

        if (input.size() < k)
        {
            vector<int> ans;
            return ans;
        }

        if (k == 0)
        {
            vector<int> ans;
            return ans;
        }

        // random_shuffle(input);
        std::random_shuffle(input.begin(), input.end());
        int kv = find_kth_minimal(input.data(), input.data() + input.size(), k);
        cout << kv << endl;
        vector<int> ans(k, kv);
        int id = 0;
        for (auto i : input)
        {
            if (i < kv)
                ans[id++] = i;
        }

        sort(ans.begin(), ans.end());
        // ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        return ans;
    }

    void random_shuffle(vector<int> &input)
    {
        int size = input.size();
        for (int i = 0; i < size - 1; i++)
        {
            int index = i + rand() % (size - i);
            swap(input[i], input[index]);
        }
    }

    int find_kth_minimal(int *const start, int *const end, int k)
    {
        if (start + 1 == end)
            return *start;

        //for (int *i = start; i < end; i++)
        //    printf("%d ", *i);
        //cout << endl;

        int *i, *j;
        for (i = j = start + 1; j < end; j++)
            if (*j < *start)
                swap(*i++, *j);
        swap(*start, *--i);

        //for (int *i = start; i < end; i++)
        //    printf("%d ", *i);
        //cout << endl;

        int l = i - start + 1;
        if (k == l)
            return *i;
        if (k < l)
            return find_kth_minimal(start, i, k);
        return find_kth_minimal(i + 1, end, k - l);
    }
};

int main()
{
    while (1)
    {
        vector<int> input;
        for (int i = 0; i < 1000; i++)
        {
            input.push_back(rand() % 100);
        }
        for (auto i : input)
            cout << i << ' ';
        cout << endl;

        Solution s;
        vector<int> ans = s.GetLeastNumbers_Solution(input, 1);

        for (auto i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}