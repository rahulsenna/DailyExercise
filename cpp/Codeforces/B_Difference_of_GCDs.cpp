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
  int n, l, r;
  cin >> n >> l >> r;

  std::vector<int> a(n);
  for (int i = 1; i <= n; ++i)
  {
    int mod = l % i;
    int ai = l;
    if (mod > 0)
      ai += (i - mod);

    if (ai > r)
    {
      cout << "NO\n";
      return;
    }
    a[i - 1] = ai;
  }

  cout << "YES\n";
  for (auto e : a)
    cout << e << ' ';
  cout << '\n';
}

// [B. Difference of GCDs] (https://codeforces.com/problemset/problem/1708/B)
// [2026-08-27] [17:30:40]
