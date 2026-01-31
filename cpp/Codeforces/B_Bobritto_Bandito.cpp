#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m,l,r;
	cin >> n >> m >> l >> r;
	int remove = n-m;
	int rrem = min(remove, r);
	remove -= rrem;
	r -= rrem;

	if (remove>0)
		l += remove;

	cout << l << ' ' << r << '\n';
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int test = 1;
	cin >> test;
	while (test--)
	{
		solve();
	}
	return 0;
}