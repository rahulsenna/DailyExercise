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
  s64 n;
  cin >> n;
  std::vector<s64> a(n);

  for (auto &e : a)
    cin >> e;

  std::sort(a.begin(), a.end());

  if (a[0] != 1)
  {
    std::cout << "NO" << '\n';
    return;
  }

  s64 sum_till_now = 1;
  for (int i = 1; i < n; ++i)
  {
    if (a[i] > sum_till_now)
    {
      std::cout << "NO" << '\n';
      return;
    }
    sum_till_now += a[i];
  }

  std::cout << "YES" << '\n';
}

// [G2. Subsequence Addition (Hard Version)] (https://codeforces.com/problemset/problem/1807/G2)
// [2026-08-19] [09:12:11]
