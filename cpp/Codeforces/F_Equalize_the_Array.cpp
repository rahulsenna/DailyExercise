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

  std::unordered_map<int, int> a;
  for (int e, i = 0; i < n; ++i)
  {
    cin >> e;
    a[e]++;
  }
  std::vector<int> freq;
  for (auto [k, v] : a)
    freq.push_back(v);

  std::sort(freq.begin(), freq.end());

  int res = INT_MAX;
  int fs = freq.size();
  for (int i = 0; i < fs; ++i)
    res = min(res, n - freq[i] * (fs - i));

  std::cout << res << '\n';
}

// [F. Equalize the Array] (https://codeforces.com/problemset/problem/1490/F)
// [2026-09-25] [23:08:38]
