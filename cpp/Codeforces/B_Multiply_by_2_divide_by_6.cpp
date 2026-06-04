#include <bits/stdc++.h>
using namespace std;

typedef uint32_t u32; typedef int64_t s64; typedef uint64_t u64; typedef long double r64;
inline void setup()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
}

#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif
void solve();
int main()
{
	setup();
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

  int step = 0;
  while (n != 1)
  {
    if (n % 6 != 0 && n * 2 % 6 != 0)
    {
      std::cout << "-1\n";
      return;
    }
    if (n % 6 == 0)
    {
      step += 1;
      n /= 6;
    }
    else
    {
      step += 2;
      n = (n * 2) / 6;
    }
  }
  std::cout << step << '\n';
}

// [B. Multiply by 2, divide by 6] (https://codeforces.com/problemset/problem/1374/B)
// [2026-06-04] [14:43:35]
