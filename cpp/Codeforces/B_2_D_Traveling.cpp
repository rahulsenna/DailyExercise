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
  s64 n, k, a, b;
  cin >> n >> k >> a >> b;
  a--, b--;
  std::vector<std::pair<s64, s64>> major_cities(n);
  for (auto &e : major_cities)
    cin >> e.first >> e.second;

  auto dist = [&](auto i, auto j)
  {
    return abs(major_cities[i].first - major_cities[j].first) +
           abs(major_cities[i].second - major_cities[j].second);
  };
  s64 res = dist(a, b);
  s64 s_a = 1e18, s_b = 1e18;
  for (int i = 0; i < k; ++i)
  {
    s_a = min(s_a, dist(a, i));
    s_b = min(s_b, dist(b, i));
  }
  std::cout << min(s_a + s_b, res) << '\n';
}

// [B. 2D Traveling] (https://codeforces.com/problemset/problem/1869/B)
// [2026-08-08] [17:12:10]
