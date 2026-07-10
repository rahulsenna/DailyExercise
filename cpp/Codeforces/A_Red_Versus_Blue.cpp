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
  int n, r, b;
  cin >> n >> r >> b;

  int d = r / (b + 1);
  int e = r % (b + 1);

  for (int i = 0; i <= b; ++i)
  {
    cout << string(d + (i < e), 'R');
    if (i < b)
      cout << 'B';
  }
  cout << '\n';
}

// [A. Red Versus Blue] (https://codeforces.com/problemset/problem/1659/A)
// [2026-07-09] [19:31:06]
