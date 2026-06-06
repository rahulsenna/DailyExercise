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
  string s;
  cin >> s;
  int cnt[2] = {count(s.begin(), s.end(), '0'), count(s.begin(), s.end(), '1')};

  for (auto e : s)
  {
    int x = e - '0';
    if (!(cnt[x ^ 1]-- > 0))
    {
      std::cout << cnt[x ^ 0] << '\n';
      return;
    }
  }
  std::cout << "0\n";
}

// [B. Swap and Delete] (https://codeforces.com/problemset/problem/1913/B)
// [2026-06-06] [16:01:30]

/*
111100
0011

*/