#include <bits/stdc++.h>
using namespace std;

char a[200];
int main() {
	scanf("%s", a);
	int n = strlen(a);
	int t = 100;
	while (t--) {
		puts(a);
		next_permutation(a, a + n);
	}
}
