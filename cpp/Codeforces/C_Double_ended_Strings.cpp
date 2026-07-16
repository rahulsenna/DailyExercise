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
  string a, b;
  cin >> a >> b;
  if (a.length() > b.length())
    swap(a, b);

  int l = 0, r = 1;
  int max_len = 0;
  int search_pos = 0;
  while (r <= a.length())
  {
    string_view sub = {a.begin() + l, a.begin() + r};
    int pos = b.find(sub, search_pos);
    if (pos != -1)
    {
      max_len = max(max_len, r - l);
      r++;
      search_pos = pos;
    }
    else
    {
      l++;
      r = l + 1;
      search_pos = 0;
    }
  }
  cout << a.length() + b.length() - 2 * max_len << '\n';
}

// [C. Double-ended Strings] (https://codeforces.com/problemset/problem/1506/C)
// [2026-07-16] [18:43:46]
