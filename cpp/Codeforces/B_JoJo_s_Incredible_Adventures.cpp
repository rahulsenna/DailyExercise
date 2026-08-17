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
  string s;
  cin >> s;

  u64 n = s.length();

  if (s.find('0') == -1)
  {
    cout << n * n << '\n';
    return;
  }

  s = s + s;

  u64 max_cons = 0, cur_cons = 0;

  for (auto c : s)
  {
    if (c == '1')
    {
      cur_cons++;
      max_cons = max(max_cons, cur_cons);
    }
    else
      cur_cons = 0;
  }

  u64 S = max_cons + 1;
  u64 a = S / 2;
  u64 b = (S + 1) / 2;
  std::cout << a * b << '\n';
}

// [B. JoJo's Incredible Adventures] (https://codeforces.com/problemset/problem/1820/B)
// [2026-08-17] [05:01:06]
