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

  set<char> unique_chars(s.begin(), s.end());
  std::vector<int> loc(26, -1);

  for (int i = 0; i < s.length(); ++i)
  {
    int c = s[i] - 'a';
    if (loc[c] != -1)
    {
      if ((i - loc[c]) < unique_chars.size())
      {
        cout << "NO\n";
        return;
      }
    }
    loc[c] = i;
  }
  cout << "YES\n";
  int d = 5;
}

// [B. A Perfectly Balanced String?] (https://codeforces.com/problemset/problem/1673/B)
// [2026-08-31] [22:39:29]

