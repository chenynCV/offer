#include <bits/stdc++.h>
using namespace std;

bool compare(const string &a, const string &b)
{
    return a[0] > b[0];
}

int main()
{
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.size(); i++)
    {
        v.push_back(s.substr(i));
    }
    sort(v.begin(), v.end());
    cout << v[k] << endl;
    return 0;
}
