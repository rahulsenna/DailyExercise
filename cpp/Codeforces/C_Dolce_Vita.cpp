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
  s64 n, x;
  cin >> n >> x;
  std::vector<s64> a(n);
  for (auto &e: a)
    cin >> e;
  
  std::sort(a.begin(), a.end());
  std::vector<s64> pref(n+1);
  partial_sum(a.begin(), a.end(), pref.begin()+1);

  s64 res = 0;
  for (s64 i = 1; i <= n; ++i)
  {
    if (pref[i] <= x)
      res += (x - pref[i]) / i + 1;
  }
  std::cout << res << '\n';
}

// [C. Dolce Vita] (https://codeforces.com/problemset/problem/1671/C)
// [2026-11-15] [07:10:45]
