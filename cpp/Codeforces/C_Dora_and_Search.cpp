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

  int l = 0, r = n - 1;
  int mn = 1, mx = n;

  while (l < r)
  {
    if (a[l] == mn or a[l] == mx)
    {
      if (a[l] == mn)
        mn++;
      else
        mx--;
      l++;
    }
    else if (a[r] == mn or a[r] == mx)
    {
      if (a[r] == mn)
        mn++;
      else
        mx--;
      r--;
    }
    else
    {
      break;
    }
  }

  if (l == r)
    cout << "-1\n";
  else
    cout << l + 1 << ' ' << r + 1 << '\n';
}

// [C. Dora and Search] (https://codeforces.com/problemset/problem/1793/C)
// [2026-10-05] [16:40:12]
