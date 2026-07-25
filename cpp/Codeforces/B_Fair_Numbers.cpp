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

bool is_fair(u64 n)
{
  string s = to_string(n);
  for (auto &e : s)
  {
    u64 d = e - '0';
    if (not(d == 0 or n % d == 0))
      return false;
  }
  return true;
}
void solve()
{
  u64 n;
  cin >> n;
  while (not is_fair(n))
    n++;
  cout << n << '\n';
}

// [B. Fair Numbers] (https://codeforces.com/problemset/problem/1411/B)
// [2026-07-25] [23:39:09]
