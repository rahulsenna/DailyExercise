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
  int    n;
  string s;
  cin >> n >> s;

  int res = 1;

  for (int curr = 1, i = 1; i < n; ++i)
  {
    if (s[i - 1] == s[i])
      curr++;
    else
      curr = 1;
    res = max(res, curr);
  }

  cout << res + 1 << '\n';
}