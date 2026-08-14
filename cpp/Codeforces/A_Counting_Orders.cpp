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
  std::vector<int> b(n);
  for (auto &e : a)
    cin >> e;

  for (auto &e : b)
    cin >> e;

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  u64 res = 1;
  int idx = 0;
  for (int i = 0; i < n; ++i)
  {
    while (idx < n and a[i] > b[idx])
      idx++;
    res = (res * (idx - i)) % 1000000007;
  }

  std::cout << res << '\n';
}

// [A. Counting Orders] (https://codeforces.com/problemset/problem/1827/A)
// [2026-08-14] [04:26:52]
