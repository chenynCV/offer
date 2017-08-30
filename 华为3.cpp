// g++ 华为.cpp -o test -std=c++11; ./test
#include <bits/stdc++.h>
using namespace std;

bool isKeyWords(string s)
{
    if (s == "int" || s == "return")
        return true;

    return false;
}

bool isOperator(string s)
{
    if (s == "+" || s == "," || s == ";" || s == "(" || s == ")" || s == "{" || s == "}")
        return true;

    return false;
}

bool isSamePattern(string input)
{
    int i = 0, j = 0;

    string fun = "int add(int x, int y)  {int sum=0; sum=x+y; return sum;}";

    while (i < fun.size() && j < input.size())
    {
        string tmp;
        while (fun[i] == ' ')
            i++;

        while (!isOperator(fun.substr(i, 1)) && fun[i] != ' ')
        {
            tmp.push_back(fun[i++]);
        }
        if (tmp.empty())
            tmp.push_back(fun[i++]);
        cout << tmp << endl;

        string tmp2;
        while (input[j] == ' ')
            j++;
        while (j < input.size() && !isOperator(input.substr(j, 1)) && input[j] != ' ')
        {
            tmp2.push_back(input[j++]);
        }
        if (j < input.size() && tmp2.empty())
            tmp2.push_back(input[j++]);
        cout << tmp2 << endl;

        if (isKeyWords(tmp) || isOperator(tmp))
        {
            if (tmp != tmp2)
                return false;
        }

        cout << endl;
    }

    if (i >= fun.size())
        return true;

    return false;
}

int main()
{
    string input;
    getline(cin, input);
    cout << input << endl;
    if (isSamePattern(input))
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}