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
  string s;
  cin >> n >> k >> s;

  int W = count(s.begin(), s.begin() + k, 'W');
  int res = W;
  for (int r = k; r < n; ++r)
  {
    if (s[r] == 'W')
      W++;
    if (s[r - k] == 'W')
      W--;
    res = min(res, W);
  }
  std::cout << res << '\n';
}

// [D. Black and White Stripe] (https://codeforces.com/problemset/problem/1690/D)
// [2026-07-08] [12:15:23]
