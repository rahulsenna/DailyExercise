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
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<bool> keys(26, false);

  for (int i = 0; i < k; ++i)
  {
    char c;
    cin >> c;
    keys[c - 'a'] = true;
  }

  u64 res = 0, curr_len = 0;
  for (auto c : s)
  {
    if (keys[c - 'a'])
      curr_len++;
    else
    {
      res += (curr_len * (curr_len + 1)) / 2;
      curr_len = 0;
    }
  }
  res += (curr_len * (curr_len + 1)) / 2;
  std::cout << res << '\n';
}

// [C. Yet Another Broken Keyboard] (https://codeforces.com/problemset/problem/1272/C)
// [2026-09-23] [20:28:19]
