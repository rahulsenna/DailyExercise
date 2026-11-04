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
  int n, m;
  cin >> n >> m;

  if (n == 1)
  {
    cout << "0\n";
    return;
  }

  if (n & 1)
    n++;

  cout << n / 2 << '\n';
  int mid = (n / 2);
  for (int i = 0; i < mid; ++i)
  {
    cout << i + 1 << ' ' << mid + i << '\n';
  }
}

// [D1. Come Be My Friend, Don't Be So Scared (Easy Version)] (https://codeforces.com/contest/2261/problem/D1)
// [2026-11-04] [21:18:26]
