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
  int a, b;
  cin >> a >> b;

  int ans = 32;
  for (int B = max(2, b); B - b < ans; ++B)
  {
    int steps = floor(log(a) / log(B) + 1e-11) + 1 + (B - b);
    ans = min(ans, steps);
  }
  std::cout << ans << '\n';
}

// [A. Add and Divide] (https://codeforces.com/problemset/problem/1485/A)
// [2026-07-17] [06:20:24]
