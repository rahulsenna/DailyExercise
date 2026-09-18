#include <bits/stdc++.h>
using namespace std;
typedef uint32_t u32; typedef int64_t s64; typedef uint64_t u64; typedef long double r64;
#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
	uint64_t t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}

void solve()
{
  u64 n, x, y;
  cin >> n >> x >> y;

  u64 common = n / lcm(x, y);
  u64 a = n / x - common;
  u64 b = n / y - common;

  u64 m = n - a + 1;

  s64 neg = (b * (b + 1LL)) / 2LL;
  s64 pos = ((n - m + 1)) * (n + m) / 2LL;

  cout << pos - neg << '\n';
}

// [D. Plus Minus Permutation] (https://codeforces.com/problemset/problem/1872/D)
// [2026-09-18] [22:48:30]
