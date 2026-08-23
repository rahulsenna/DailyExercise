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
  int n;
  cin >> n;
  u64 res = 0;
  int mn = INT_MAX, neg = 0;
  for (int e, i = 0; i < n; ++i)
  {
    cin >> e;
    if (e < 0)
      neg++;
    res += abs(e);
    mn = min(mn, abs(e));
  }

  if (neg & 1)
    res -= mn * 2;
  std::cout << res << '\n';
}

// [E. Negatives and Positives] (https://codeforces.com/problemset/problem/1791/E)
// [2026-08-23] [08:20:31]
