#include <bits/stdc++.h>
using namespace std;

int n, p, a[1010];
char s[1010], output[1010];

void work(int x)
{
    if (x == -1)
    {
        puts("NO");
        return;
    }
    a[x]++;
    while (a[x] < p && ((x - 1 >= 0 && a[x] == a[x - 1]) || (x - 2 >= 0 && a[x] == a[x - 2])))
        a[x]++;
    /* cout << x << " " << a[x] << " " << n << endl; */

    if (a[x] >= p)
    {
        work(x - 1);
        return;
    }

    for (int i = x + 1; i < n; i++)
    {
        a[i] = 0;
        while ((i - 1 >= 0 && a[i] == a[i - 1]) || (i - 2 >= 0 && a[i] == a[i - 2]))
            a[i]++;
    }

    /* cout << n << endl; */

    for (int i = 0; i < n; i++)
        putchar(a[i] + 'a');
    puts("");
}

int main()
{
    scanf("%d%d%s", &n, &p, s);

    if (p == 1)
    {
        puts("NO");
        return 0;
    }
    else if (p == 2)
    {
        if (n == 1 && s[0] == 'a')
        {
            puts("b");
        }
        else if (n == 2)
        {
            if (s[0] == 'a')
            {
                if (s[1] == 'b')
                {
                    puts("ba");
                }
                else
                {
                    puts("ab");
                }
            }
            else
            {
                puts("NO");
            }
        }
        else
        {
            puts("NO");
        }
        return 0;
    }

    for (int i = 0; i < n; i++)
        a[i] = s[i] - 'a';

    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1] || (i - 2 >= 0 && a[i] == a[i - 2]))
        {
            work(i);
            flag = true;
            break;
        }
    }
    if (!flag)
        work(n - 1);
    return 0;
}
