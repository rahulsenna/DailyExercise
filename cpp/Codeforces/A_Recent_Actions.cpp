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
	int n, m;
	cin >> n >> m;

	std::unordered_map<int, int> posts;
	for (int i = 1; i <= n; ++i)
		posts[i] = i;

	std::unordered_map<int, int> removed;

	int ii = 1, iv = 1, ri = n;

	for (int a, i = 1; i <= m; ++i)
	{
		cin >> a;
		if (posts.contains(a))
		{
			auto x		= posts[a];
			posts[a]	= ii;
			posts[iv] = x;

		} else
		{
			posts[a]			= --ii;
			iv						= a;
			removed[ri--] = i;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		int res = removed[i] ? removed[i] : -1;
		cout << res << ' ';
	}
	cout << '\n';
}