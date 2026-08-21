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
  s64 n, c;
  cin >> n >> c;
  std::vector<s64> a(n);
  s64 i = 1;
  for (auto &e : a)
  {
    cin >> e;
    e += i++;
  }

  std::sort(a.begin(), a.end());
  s64 res = 0;

  for (auto &e : a)
  {
    if (c >= e)
    {
      res++;
      c -= e;
    }
    else
      break;
  }
  std::cout << res << '\n';
}

// [G1. Teleporters (Easy Version)] (https://codeforces.com/problemset/problem/1791/G1)
// [2026-08-21] [19:20:00]
