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
  s64 n, q;
  cin >> n >> q;

  std::vector<s64> a(n), prefix_sum(n);
  for (auto &e : a)
    cin >> e;

  partial_sum(a.begin(), a.end(), prefix_sum.begin());
  for (int i = 1; i < n; ++i)
    a[i] = max(a[i], a[i - 1]);

  for (s64 e, i = 0; i < q; ++i)
  {
    cin >> e;
    int dist = (std::upper_bound(a.begin(), a.end(), e) - a.begin()) - 1;
    cout << (dist < 0 ? 0 : prefix_sum[dist]) << ' ';
  }
  cout << '\n';
}

// [E. Scuza] (https://codeforces.com/problemset/problem/1742/E)
// [2026-10-15] [20:48:03]
