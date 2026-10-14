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

  map<int, int> cnt;
  for (int e, i = 0; i < n; ++i)
  {
    cin >> e;
    cnt[e]++;
  }

  int res = 0;
  for (auto [i, c] : cnt)
  {
    int next_c = cnt.count(i + 1) ? cnt[i + 1] : 0;
    res += max(0, c - next_c);
  }
  cout << res << '\n';
}

// [D. Matryoshkas] (https://codeforces.com/problemset/problem/1790/D)
// [2026-10-14] [13:40:28]
