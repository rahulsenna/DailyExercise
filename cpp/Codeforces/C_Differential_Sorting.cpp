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

  if (a[n - 2] > a[n - 1])
  {
    cout << "-1\n";
    return;
  }
  if (a[n - 1] < 0)
  {
    cout << (is_sorted(a.begin(), a.end())) ? "0\n" : "-1\n";
    return;
  }

  cout << n - 2 << "\n";
  for (int i = 1; i <= n - 2; ++i)
    cout << i << ' ' << n - 1 << ' ' << n << '\n';
}

// [C. Differential Sorting] (https://codeforces.com/problemset/problem/1635/C)
// [2026-11-18] [22:48:21]
