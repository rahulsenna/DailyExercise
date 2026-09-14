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
  vector<vector<pair<int, int>>> a(3, vector<pair<int, int>>(n));

  for (int j = 0; j < 3; ++j)
  {
    for (int i = 0; i < n; ++i)
    {
      cin >> a[j][i].first;
      a[j][i].second = i;
    }
    std::partial_sort(a[j].begin(), a[j].begin() + 3, a[j].end(), greater<>());
  }

  int res = 0;
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      for (int k = 0; k < 3; ++k)
      {
        auto [av, ai] = a[0][i];
        auto [bv, bi] = a[1][j];
        auto [cv, ci] = a[2][k];

        if (ai != bi and bi != ci and ai != ci)
          res = max(res, av + bv + cv);
      }
    }
  }

  cout << res << '\n';
}

// [D. Three Activities] (https://codeforces.com/problemset/problem/1914/D)
// [2026-09-14] [19:13:16]
