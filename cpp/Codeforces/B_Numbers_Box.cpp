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
  int r, c;
  cin >> r >> c;
  int res = 0, mn = INT_MAX, neg_count = 0;
  for (int e, i = 0; i < r * c; ++i)
  {
    cin >> e;
    if (e < 0)
      neg_count++;
    res += abs(e);
    mn = min(mn, abs(e));
  }

  if (neg_count & 1)
    res -= mn * 2;

  std::cout << res << '\n';
}

// [B. Numbers Box] (https://codeforces.com/problemset/problem/1447/B)
// [2026-07-22] [10:07:40]
