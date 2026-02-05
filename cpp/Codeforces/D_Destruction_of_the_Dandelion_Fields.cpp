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
	s64 res = 0;
	std::vector<s64> odds;
	odds.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		s64 a;
		cin >> a;
		if (a&1)
			odds.push_back((a));
		else
			res += a;
	}

	if (odds.size() == 0)
	{
		cout << "0\n";
		return;
	}

	std::ranges::sort(odds, std::greater{});

	int take = (odds.size() + 1) / 2;
	for (int i = 0; i < take; ++i)
		res += odds[i];
	
	cout << res << '\n';
}