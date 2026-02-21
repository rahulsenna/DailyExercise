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
	int n;
	cin >> n;
	std::vector<int> P(n);
	for (auto &e : P)
		cin >> e;

	for (int i = 1; i < n - 1; ++i)
	{
		if (P[i] > P[i - 1] and P[i] > P[i + 1])
		{
			cout << "YES\n";
			cout << i << ' ' << i + 1 << ' ' << i + 2 << '\n';
			return;
		}
	}
	cout << "NO\n";
}