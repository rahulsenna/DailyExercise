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
  s64 n, k, b, s;
  cin >> n >> k >> b >> s;

  if (k * b > s or s > ((k - 1) * n + k * b))
  {
    cout << "-1\n";
    return;
  }

  s64 take = min(s, k * b + (k - 1));
  s64 remaining = s - take;
  for (int i = 0; i < n; ++i)
  {
    cout << take << " ";
    take = min(remaining, k - 1);
    remaining -= take;
  }
  cout << '\n';
}

// [B. Beautiful Array] (https://codeforces.com/problemset/problem/1715/B)
// [2026-07-04] [03:23:56]
