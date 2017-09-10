#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, vector<int>> user;
	int score;
	for (int i = 0; i < n; i++)
	{
		cin >> score;
		user[score].push_back(i);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int l, r, k, cnt = 0;
		cin >> l >> r >> k;

		for (auto j : user[k])
		{
			if (j >= l)
			{
				if (j <= r)
					cnt++;
				else
					break;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}