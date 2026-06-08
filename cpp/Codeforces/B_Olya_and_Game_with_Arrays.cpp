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
  std::vector<vector<int>> arr(n);
  for (int m, i = 0; i < n; ++i)
  {
    cin >> m;
    arr[i].resize(m);
    for (auto &e : arr[i])
      cin >> e;
    std::sort(arr[i].begin(), arr[i].end());
  }
  int mn0 = INT_MAX, mn1 = INT_MAX;
  u64 res = 0;
  for (int i = 0; i < n; ++i)
  {
    mn0 = min(mn0, arr[i][0]);
    mn1 = min(mn1, arr[i][1]);
    res += arr[i][1];
  }

  res -= mn1;
  res += mn0;
  std::cout << res << '\n';
}

// [B. Olya and Game with Arrays] (https://codeforces.com/problemset/problem/1859/B)
// [2026-06-08] [15:22:29]
