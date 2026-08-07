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
  s64 n, x;
  cin >> n >> x;
  std::vector<s64> a(n);
  for (auto &e : a)
    cin >> e;

  s64 res = 0;
  s64 l = 1, h = 2e9;
  while (l <= h)
  {
    s64 mid = (l + h + 1) / 2;
    s64 X = 0;
    for (auto e : a)
    {
      X += max(mid - e, 0LL);
      if (X > x)
        break;
    }
    if (X > x)
      h = mid - 1;
    else if (X <= x)
    {
      l = mid + 1;
      res = max(res, mid);
    }
  }
  std::cout << res << '\n';
}

// [E. Building an Aquarium] (https://codeforces.com/problemset/problem/1873/E)
// [2026-08-07] [11:29:30]
