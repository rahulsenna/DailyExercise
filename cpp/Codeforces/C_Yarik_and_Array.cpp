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
  std::vector<int> a(n);
  for (auto &e : a)
    cin >> e;

  int res = max(INT_MIN, a[0]);
  int running_total = a[0];
  int l = 0, r = 1;
  while (r < n)
  {
    running_total = max(a[r], a[r] + running_total);
    if ((a[r] & 1) == (a[r - 1] & 1))
    {
      l = r;
      running_total = a[r];
    }
    res = max(res, running_total);
    r++;
  }

  std::cout << res << '\n';
}

// [C. Yarik and Array] (https://codeforces.com/problemset/problem/1899/C)
// [2026-08-03] [19:38:33]
