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
  u64 n;
  cin >> n;
  std::vector<u64> a(n);
  u64 total = 0;
  for (auto &e : a)
  {
    cin >> e;
    total += e;
  }

  u64 res = 0, pre_sum = 0;
  for (int i = 0; i < n - 1; ++i)
  {
    pre_sum += a[i];
    res = max(res, gcd(pre_sum, total));
  }

  std::cout << res << '\n';
};

// [B. GCD Partition] (https://codeforces.com/problemset/problem/1780/B)
// [2026-08-24] [14:45:20]
