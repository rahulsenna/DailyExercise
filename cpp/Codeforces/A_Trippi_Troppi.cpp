#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string a, b, c;
	int test = 1;
	cin >> test;
	while(test--)
	{
		cin >> a >> b >> c;
		cout << a[0] << b[0] << c[0] << '\n';
	}
	return 0;
}
