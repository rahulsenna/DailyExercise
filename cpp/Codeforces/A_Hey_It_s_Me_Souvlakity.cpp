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
  string s;
  cin >> n >> s;

  int mn = n, mx = 1, a_c = 0;
  for (int i = 0; i < n; ++i)
  {
    if (s[i] == '1')
    {
      mn = min(mn, i + 1);
      mx = max(mx, i + 1);
      a_c++;
    }
  }

  cout << (a_c == 2 ? 1 : mx - mn) << '\n';
}

// [A. Hey, It's Me, Souvlakity] (https://codeforces.com/contest/2261/problem/A)
// [2026-10-26] [20:08:47]
