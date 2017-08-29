// g++ 中兴.cpp -o test -std=c++11; ./test
#include <bits/stdc++.h>
using namespace std;

bool compare(const int &x, const int &y)
{
    int xn = 0, i = 0;
    while (x >= (1 << i))
    {
        if (x & (1 << i))
            xn++;
        i++;
    }

    int yn = 0, j = 0;
    while (y >= (1 << j))
    {
        if (y & (1 << j))
            yn++;
        j++;
    }

    if (xn == yn)
        return x > y;

    return xn > yn;
}

void handshakeStream(int num, int element, int *streamNum)
{
    sort(streamNum, streamNum + num, compare);

    for (int i = 0; i < element; i++)
        cout << streamNum[i] << endl;

    return;
}

int main()
{
    // int num = 5, element = 2;
    // int streamNum[] = {5, 3, 7, 1, 2};

    int num = 4, element = 3;
    int streamNum[] = {19, 32, 15, 24};

    handshakeStream(num, element, streamNum);

    return 0;
}