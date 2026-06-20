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

  for (int i = 2; i * i <= n; ++i)
  {
    if (n % i == 0)
    {
      cout << n / i << " " << n - n / i << '\n';
      return;
    }
  }
  cout << 1 << " " << n - 1 << '\n';
}

// [M. Minimum LCM] (https://codeforces.com/problemset/problem/1765/M)
// [2026-06-20] [16:54:25]
