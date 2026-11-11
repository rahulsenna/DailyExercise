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
  int n, s;
  cin >> n >> s;

  std::vector<int> a(n);
  int sum = 0;
  for (auto &e : a)
  {
    cin >> e;
    if (e == 1)
      sum++;
  }
  if (s > sum)
  {
    cout << "-1\n";
    return;
  }

  int max_len = -1, l = 0, curr_sum = 0;
  for (int r = 0; r < n; ++r)
  {
    curr_sum += a[r];

    while (curr_sum > s and l <= r)
      curr_sum -= a[l++];

    if (curr_sum == s)
      max_len = max(max_len, r - l + 1);
  }

  std::cout << n - max_len << '\n';
}

// [E. Binary Deque] (https://codeforces.com/problemset/problem/1692/E)
// [2026-11-11] [22:51:14]

