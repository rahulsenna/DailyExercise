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

  int open = 0;

  for (auto c : s)
  {
    if (c == '(')
      open++;
    else if (open > 0)
      open--;
  }

  std::cout << open << '\n';
}

// [C. Move Brackets] (https://codeforces.com/problemset/problem/1374/C)
// [2026-07-27] [10:48:20]
