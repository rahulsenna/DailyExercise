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
  std::map<int, u64> map;
  for (int e, i = 1; i <= n; ++i)
  {
    cin >> e;
    map[e - i]++;
  }

  u64 res = 0;
  for (auto [k, v] : map)
    res += (v * (v - 1LLU)) / 2LLU;

  std::cout << res << '\n';
}

// [D. Same Differences] (https://codeforces.com/problemset/problem/1520/D)
// [2026-09-24] [20:18:14]
