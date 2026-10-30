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
  s64 n, m = 0;
  cin >> n;

  std::vector<s64> a(n);
  for (auto &e : a)
  {
    cin >> e;
    m = max(m, e);
  }

  s64 highest_bit = 0;
  for (auto e : a)
  {
    s64 diff = m ^ e;
    highest_bit = max(highest_bit, (s64)bit_width((u64)diff) - 1);
  }

  s64 mask = (1LL << highest_bit) - 1;

  int res = m | mask;
  std::cout << res << '\n';
}

// [B. What's the Capital of France?] (https://codeforces.com/contest/2261/problem/B)
// [2026-10-30] [20:20:30]
