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
  int n, m;
  cin >> n >> m;

  std::vector<vector<int>> a(m, vector<int>(n));

  for (int c = 0; c < n; ++c)
  {
    for (int r = 0; r < m; ++r)
      cin >> a[r][c];
  }
  s64 res = 0;
  for (int i = 0; i < m; ++i)
  {
    std::sort(a[i].begin(), a[i].end());
    for (s64 j = 0; j < n; ++j)
      res += (s64)a[i][j] * (2 * j - n + 1);
  }

  std::cout << res << '\n';
}

// [B. Playing in a Casino] (https://codeforces.com/problemset/problem/1808/B)
// [2026-10-02] [22:57:22]
