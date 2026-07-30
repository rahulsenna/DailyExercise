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

	solve();
	return 0;
}

void solve()
{
  int n;
  string s;
  cin >> n >> s;

  for (int i = 1; i < n; ++i)
  {
    if (s[i - 1] > s[i])
    {
      cout << "YES\n" << i << ' ' << i + 1 << '\n';
      return;
    }
  }
  cout << "NO\n";
}

// [A. Reverse a Substring] (https://codeforces.com/problemset/problem/1155/A)
// [2026-07-30] [10:19:59]
