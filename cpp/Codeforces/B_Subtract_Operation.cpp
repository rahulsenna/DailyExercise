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
  int n, k;
  cin >> n >> k;
  std::vector<int> a(n);
  for (auto &e : a)
    cin >> e;
  
  std::sort(a.begin(), a.end());

  for (auto e : a)
  {
    if (binary_search(a.begin(), a.end(), e + k))
    {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
}

// [B. Subtract Operation] (https://codeforces.com/problemset/problem/1656/B)
// [2026-09-02] [21:48:34]
