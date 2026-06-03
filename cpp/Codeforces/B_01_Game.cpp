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

  int n = s.length();
  int zeros = count(s.begin(), s.end(), '0');
  int ones = count(s.begin(), s.end(), '1');

  if (min(zeros, ones) & 1)
    cout << "DA\n";
  else
    cout << "NET\n";
}

// [B. 01 Game] (https://codeforces.com/problemset/problem/1373/B)
// [2026-06-03] [21:23:00]
