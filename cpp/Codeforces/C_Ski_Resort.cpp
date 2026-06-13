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
  int n, k, q;
  cin >> n >> k >> q;
  std::vector<int> con_days;
  int cqd = 0;
  for (int i = 0, a; i < n; ++i)
  {
    cin >> a;
    if (a <= q)
      cqd++;
    else
    {
      con_days.push_back(cqd);
      cqd = 0;
    }
  }
  con_days.push_back(cqd);

  u64 res = 0;
  for (auto c : con_days)
  {
    if (c >= k)
    {
      u64 d = c - k + 1;
      res += d * (d + 1) / 2;
    }
  }
  std::cout << res << '\n';
}

// [C. Ski Resort] (https://codeforces.com/problemset/problem/1840/C)
// [2026-06-13] [16:59:59]
