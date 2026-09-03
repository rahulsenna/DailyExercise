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
  std::vector<int> a(n);
  for (auto &e : a)
    cin >> e;

  int res = 0, target = a[n - 1];
  for (int i = 2; i <= n; ++i)
  {
    if (a[n - i] != target)
    {
      i = i * 2 - 2;
      res++;
    }
  }

  std::cout << res << '\n';
}

// [B. Fun with Even Subarrays] (https://codeforces.com/problemset/problem/1631/B)
// [2026-09-03] [16:56:14]
