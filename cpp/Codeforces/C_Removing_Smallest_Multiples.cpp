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
  std::vector<char> a(n + 1);

  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  s64 res = 0;

  for (s64 i = 1; i <= n; ++i)
  {
    for (s64 j = i; j <= n; j += i)
    {
      if (a[j] == '0')
      {
        res += i;
        a[j] = '2';
      }
      else if (a[j] == '1')
        break;
    }
  }

  std::cout << res << '\n';
}

// [C. Removing Smallest Multiples] (https://codeforces.com/problemset/problem/1734/C)
// [2026-10-16] [20:45:33]
