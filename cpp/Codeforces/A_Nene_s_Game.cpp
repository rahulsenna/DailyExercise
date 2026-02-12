#include <bits/stdc++.h>
using namespace std;

typedef int64_t s64;
typedef uint64_t u64;
typedef long double r64;

inline void setup()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
}

#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif
void solve();
int main()
{
	setup();

	s64 t;
	cin >> t;

	while (t--)
	{
		solve();
	}

	return 0;
}

void solve()
{
	int k, q;
	cin >> k >> q;

	int minK = INT_MAX;

	for (int a, i = 0; i < k; ++i)
	{
		cin >> a;
		minK = min(minK, a);
	}
	minK--;

	for (int a, i = 0; i < q; ++i)
	{
		cin >> a;
		cout << min(minK, a) << ' ';
	}
	cout << '\n';
}