// g++ 华为.cpp -o test -std=c++11; ./test
#include <bits/stdc++.h>
using namespace std;

bool isValid(const char *input)
{
    int len = strlen(input);
    if (!(len > 0 && len <= 6))
        return false;

    for (int i = 0; i < len; i++)
    {
        if (!(input[i] >= 97 && input[i] <= 122))
            return false;
    }

    return true;
}

void convertTo26(const char *input, char *output)
{
    if (!isValid(input))
    {
        sprintf(output, "%s", "ERROR");
        return;
    }

    int len = strlen(input);
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        ans = int(input[i]) - 96 + 26 * ans;
    }
    sprintf(output, "%d", ans);

    return;
}

int main()
{
    char input[1000];
    cin >> input;
    char *output = new char[32];
    convertTo26(input, output);
    printf("%s\n", output);
    return 0;
}