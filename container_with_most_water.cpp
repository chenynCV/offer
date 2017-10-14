#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int s = 0, t = height.size() - 1;
        int v = 0, h = 0;
        while (t > s)
        {
            h = min(height[s], height[t]);
            v = max(v, h * (t - s));

            while (height[s] <= h && s < t)
                s++;

            while (height[t] <= h && s < t)
                t--;
        }

        return v;
    }
};
