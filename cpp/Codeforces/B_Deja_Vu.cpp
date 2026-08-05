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
  int n, q;
  cin >> n >> q;

  std::vector<int> a(n);
  for (auto &e : a)
    cin >> e;

  std::vector<int> x;
  for (int e, i = 0; i < q; ++i) 
  {
    cin >> e;
    if (x.empty() or x.back() > e)
      x.push_back(e);
  }

  for (auto &j : a)
  {
    for (auto &i : x)
    {
      if (j % (1 << i) == 0)
        j += 1 << (i - 1);
    }
  }

  for (auto &e : a)
    cout << e << ' ';
  cout << '\n';
}

// [B. Deja Vu] (https://codeforces.com/problemset/problem/1891/B)
// [2026-08-05] [18:38:16]
