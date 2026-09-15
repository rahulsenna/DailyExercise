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
  std::vector<u64> a(n);

  set<u64> bucket;

  for (auto &e : a)
    cin >> e;

  u64 res = 2;

  while (true)
  {
    for (auto e : a)
      bucket.insert(e % res);

    if (bucket.size() == 2)
      break;
    bucket.clear();
    res *= 2;
  }

  cout << res << '\n';
}

// [B. Make Almost Equal With Mod] (https://codeforces.com/problemset/problem/1909/B)
// [2026-09-15] [21:08:35]
