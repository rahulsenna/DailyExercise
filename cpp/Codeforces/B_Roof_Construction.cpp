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
  u32 n;
  cin >> n;

  int msb = bit_floor(n - 1);
  for (int i = 1; i < msb; ++i)
    cout << i << ' ';
  cout << "0 ";

  for (int i = msb; i < n; ++i)
    cout << i << ' ';

  cout << '\n';
}

// [B. Roof Construction] (https://codeforces.com/problemset/problem/1632/B)
// [2026-07-12] [17:48:03]
