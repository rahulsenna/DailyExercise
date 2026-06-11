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
  int n, k;
  cin >> n >> k;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i)
  {
    a[i].second = i;
    cin >> a[i].first;
    a[i].first %= k;
    if (a[i].first == 0)
      a[i].first = k;
  }
  std::sort(
      a.begin(), a.end(), [](auto x, auto y)
      { return x.first == y.first ? x.second < y.second : x.first > y.first; });

  for (auto [pos, res] : a)
  {
    cout << res + 1 << ' ';
  }
  cout << '\n';
}

// [B. Monsters] (https://codeforces.com/problemset/problem/1849/B)
// [2026-06-11] [10:43:43]
