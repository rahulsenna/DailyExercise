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
  vector<int> a(n), b(n);

  for (int &e : a)
    cin >> e;
  for (int &e : b)
    cin >> e;

  unordered_map<int, int> max_a, max_b;

  int streak = 1;
  for (int i = 0; i < n; ++i)
  {
    if (i == n - 1 || a[i] != a[i + 1])
    {
      max_a[a[i]] = max(max_a[a[i]], streak);
      streak = 1;
    }
    else
      streak++;
  }

  streak = 1;
  for (int i = 0; i < n; ++i)
  {
    if (i == n - 1 || b[i] != b[i + 1])
    {
      max_b[b[i]] = max(max_b[b[i]], streak);
      streak = 1;
    }
    else
      streak++;
  }

  int ans = 0;

  for (auto [val, count] : max_a)
    ans = max(ans, count + max_b[val]);
  
  for (auto [val, count] : max_b)
    ans = max(ans, count + max_a[val]);

  cout << ans << '\n';
}

// [B. Array merging] (https://codeforces.com/problemset/problem/1831/B)
// [2026-06-16] [21:35:54]
