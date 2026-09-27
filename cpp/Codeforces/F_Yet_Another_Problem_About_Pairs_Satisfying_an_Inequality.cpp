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

  std::vector<int> a;
  std::vector<int> b;
  for (int e, i = 1; i <= n; ++i)
  {
    cin >> e;
    if (e < i)
    {
      a.push_back(i);
      b.push_back(e);
    }
  }
  std::sort(b.begin(), b.end());
  s64 res = 0;
  for (auto i : a)
    res += b.end() - upper_bound(b.begin(), b.end(), i);

  std::cout << res << '\n';
}

// [F. Yet Another Problem About Pairs Satisfying an Inequality] (https://codeforces.com/problemset/problem/1703/F)
// [2026-09-26] [21:28:49]
