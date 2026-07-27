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
  s64 a, b;
  cin >> a >> b;
  if (a > b)
    swap(a, b);

  if (b % a != 0)
  {
    cout << "-1\n";
    return;
  }

  int r = (log(b / a) / log(8.0) + 0.999);
  s64 w = a;
  for (int i = 0; i < r; ++i)
    w *= 8;

  if (w != b and w / 4 != b and w / 2 != b)
  {
    cout << "-1\n";
    return;
  }

  std::cout << r << '\n';
}

// [A. Johnny and Ancient Computer] (https://codeforces.com/problemset/problem/1362/A)
// [2026-07-28] [04:09:47]
