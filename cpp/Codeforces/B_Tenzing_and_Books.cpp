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
  int n, x;
  cin >> n >> x;

  int X = 0;
  for (int i = 0; i < 3; ++i)
  {
    bool seek = true;
    for (int e, j = 0; j < n; ++j)
    {
      cin >> e;
      seek = seek and not(~x & e);
      if (seek)
        X |= e;
    }
  }

  if (X == x)
    std::cout << "Yes\n";
  else
    std::cout << "No\n";
}

// [B. Tenzing and Books] (https://codeforces.com/problemset/problem/1842/B)
// [2026-08-12] [02:51:06]
