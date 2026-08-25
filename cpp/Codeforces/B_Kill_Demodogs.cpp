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
  u64 n;
  cin >> n;
  u64 mod = 1e9 + 7;

  u64 mul = 2022 / 6;
  u64 res = n % mod;
  res = res * ((n + 1) % mod) % mod;
  res = res * ((4 * n - 1) % mod) % mod;
  res = res * mul % mod;
  std::cout << res << '\n';
}

// [B. Kill Demodogs] (https://codeforces.com/problemset/problem/1731/B)
// [2026-08-25] [19:17:01]
