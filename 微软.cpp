#include <bits/stdc++.h>
using namespace std;
char a[100010];
vector<int> v;
int main()
{
    scanf("%s", a);
    int x = 0;
    for (char *c = a;; c++)
    {
        if (*c >= '0' && *c <= '9')
        {
            x = x * 10 + *c - '0';
        }
        else
        {
            v.push_back(x);
            x = 0;
        }
        if (!*c)
            break;
    }
    sort(v.begin(), v.end());
    for (int i = 0, m = v.size(); i < m; i++)
        printf("%d%c", v[i], (i + 1 == m) ? '\n' : '+');
    return 0;
}
