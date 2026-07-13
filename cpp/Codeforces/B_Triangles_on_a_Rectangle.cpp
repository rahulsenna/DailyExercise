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
  u64 w,h;
  cin >> w >> h;
  u64 res = 0;
  
  for (int i = 0; i < 4; ++i)
  {
    u64 k, x, a, b;
    cin >> k;
    for (int j = 0; j < k; ++j)
    {
      cin >> x;
      if (j == 0) a = x;
      if (j == k - 1) b = x;
    }
    u64 area = (b - a) * (i < 2 ? h : w);
    res = max(res, area);
  }
  std::cout << res << '\n';
}

// [B. Triangles on a Rectangle] (https://codeforces.com/problemset/problem/1620/B)
// [2026-07-13] [23:05:55]
