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

  std::vector<int> x(n);
  for (auto &e : x)
    cin >> e;
  for (auto &e : x)
  {
    int a;
    cin >> a;
    e = a - e;
  }
  std::sort(x.begin(), x.end());
  int res = 0, l = 0, r = n - 1;
  while (l < r)
  {
    if (x[r] + x[l] >= 0)
    {
      res++;
      r--;
    }
    l++;
  }
  std::cout << res << '\n';
}

// [D. Friends and the Restaurant] (https://codeforces.com/problemset/problem/1729/D)
// [2026-10-19] [02:50:09]
