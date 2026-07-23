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
  u64 x, y, k;
  cin >> x >> y >> k;

  u64 need = (k * y + k) - 1;
  x--;
  u64 r = (need + x - 1) / x;

  u64 res = k + r;
  std::cout << res << '\n';
}

// [A. Buying Torches] (https://codeforces.com/problemset/problem/1418/A)
// [2026-07-22] [23:03:14]
