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
	std::vector<s64> nums(n);

	bool has_even = false;
	bool has_odd = false;
	for (auto &e : nums)
	{
		cin >> e;
		if (e % 2 == 0)
			has_even = true;
		else
			has_odd = true;
	}
	if (has_odd && has_even)
		std::ranges::sort(nums);

	for (auto e : nums)
		cout << e << ' ';

	cout << '\n';
}