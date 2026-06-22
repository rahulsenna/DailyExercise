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
  char c;
  string s;
  cin >> n >> c >> s;

  int next_g = -1;
  int res = 0;
  for (int i = n - 1; i >= 0; --i)
  {
    if (s[i] == 'g')
    {
      next_g = i;
      continue;
    }
    if (s[i] == c)
      res = max(res, next_g - i);
  }

  next_g += n;
  for (int i = n - 1; i >= 0; --i)
  {
    if (s[i] == 'g')
      break;

    if (s[i] == c)
      res = max(res, next_g - i);
  }

  std::cout << res << '\n';
}

// [C. Traffic Light] (https://codeforces.com/problemset/problem/1744/C)
// [2026-06-22] [16:27:17]
