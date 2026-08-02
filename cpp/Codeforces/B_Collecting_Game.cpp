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

  std::vector<std::pair<u64, u64>> a(n);
  for (u64 i = 0; i < n; ++i)
  {
    cin >> a[i].first;
    a[i].second = i;
  }

  std::sort(a.begin(), a.end());
  std::vector<u64> prefix(n);
  prefix[0] = a[0].first;
  for (int i = 1; i < n; ++i)
    prefix[i] = prefix[i - 1] + a[i].first;

  std::vector<u64> res(n);
  res[a[n - 1].second] = n - 1;
  for (int i = n - 2; i >= 0; --i)
  {
    if (prefix[i] >= a[i + 1].first)
      res[a[i].second] = res[a[i + 1].second];
    else
      res[a[i].second] = i;
  }

  for (auto &e : res)
    cout << e << ' ';

  cout << '\n';
}

// [B. Collecting Game] (https://codeforces.com/problemset/problem/1904/B)
// [2026-08-01] [20:14:05]
