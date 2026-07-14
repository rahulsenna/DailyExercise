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
  s64 n;
  cin >> n;
  std::vector<std::pair<s64, s64>> a(n);
  for (s64 x, i = 0; i < n; ++i)
  {
    cin >> x;
    a[i] = {x, i};
  }

  std::sort(a.begin(), a.end(), std::greater<>());
  s64 res = 0;
  std::vector<s64> resv(n + 1);
  resv[0] = 0;
  s64 m = 1;
  for (s64 i = 0; i < n; i += 2)
  {
    res += 2 * a[i].first * m;
    resv[a[i].second + 1] = m;
    if ((i + 1) < n)
    {
      res += 2 * a[i + 1].first * m;
      resv[a[i + 1].second + 1] = -m;
    }
    m++;
  }
  cout << res << '\n';

  for (auto e : resv)
    cout << e << ' ';
  cout << '\n';
}

// [B. Divan and a New Project] (https://codeforces.com/problemset/problem/1614/B)
// [2026-07-14] [17:28:35]
