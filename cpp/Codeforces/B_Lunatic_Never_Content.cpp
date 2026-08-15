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

  int res = 0;
  for (int i = 0; i < n / 2; ++i)
    res = gcd(res, abs(a[i] - a[(n - 1) - i]));
  std::cout << res << '\n';
}

// [B. Lunatic Never Content] (https://codeforces.com/problemset/problem/1826/B)
// [2026-08-15] [03:44:37]
