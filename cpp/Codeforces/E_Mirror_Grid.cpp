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
  vector<vector<char>> grid(n, vector<char>(n));

  for (auto &y : grid)
  {
    for (auto &x : y)
      cin >> x;
  }
  
  int res = 0;
  for (int y = 0; y < n / 2; ++y)
  {
    for (int x = 0; x < (n + 1) / 2; ++x)
    {
      int count[2] = {0, 0};

      count[grid[y][x] - '0']++;
      count[grid[x][n - 1 - y] - '0']++;
      count[grid[n - 1 - y][n - 1 - x] - '0']++;
      count[grid[n - 1 - x][y] - '0']++;

      res += min(count[0], count[1]);
    }
  }

  cout << res << '\n';
}

// [E. Mirror Grid] (https://codeforces.com/problemset/problem/1703/E)
// [2026-11-06] [22:46:39]
