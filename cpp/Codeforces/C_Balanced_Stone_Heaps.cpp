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
  int mx = 0;
  for (auto &e : a)
  {
    cin >> e;
    mx = max(e, mx);
  }

  int l = 0, r = mx, res = 0;
  vector<int> temp(n);

  while (l <= r)
  {
    bool pass = true;

    int mid = (r + l) / 2;
    temp = a;
    for (int i = n - 1; i >= 2; --i)
    {
      if (temp[i] < mid)
      {
        pass = false;
        break;
      }
      int left_over = temp[i] - mid;
      if (left_over >= 3)
      {
        left_over = min(left_over, a[i]);
        int d = left_over / 3;
        temp[i - 1] += d;
        temp[i - 2] += d * 2;
      }
    }

    if (temp[0] < mid or temp[1] < mid)
      pass = false;

    if (pass)
    {
      res = mid;
      l = mid + 1;
    }
    else
      r = mid - 1;
  }
  std::cout << res << '\n';
}

// [C. Balanced Stone Heaps] (https://codeforces.com/problemset/problem/1623/C)
// [2026-09-29] [20:44:24]
