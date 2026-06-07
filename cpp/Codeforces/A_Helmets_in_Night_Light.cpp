#include <bits/stdc++.h>
using namespace std;

typedef uint32_t u32; typedef int64_t s64; typedef uint64_t u64; typedef long double r64;
inline void setup()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
}

#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif
void solve();
int main()
{
	setup();
	uint64_t t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}

void solve()
{
  int n, p;
  cin >> n >> p;
  std::vector<std::pair<int, int>> ab(n);
  for (auto &e : ab)
    cin >> e.second;
  for (auto &e : ab)
    cin >> e.first;

  std::sort(ab.begin(), ab.end());
  u64 res = p;
  int covered = 1;
  for (auto [cost, spread] : ab)
  {
    if (covered >= n)
      break;

    spread = min(n - covered, spread);
    if (cost >= p)
    {
      cost = p;
      spread = n - covered;
    }
    covered += spread;
    res += (u64)cost * spread;
  }
  std::cout << res << '\n';
}

// [A. Helmets in Night Light] (https://codeforces.com/problemset/problem/1876/A)
// [2026-06-07] [18:42:37]
