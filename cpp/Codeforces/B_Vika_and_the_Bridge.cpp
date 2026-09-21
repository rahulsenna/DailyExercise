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
  int n, k;
  cin >> n >> k;

  vector<int> largest_gap(k + 1);
  vector<int> second_largest_gap(k + 1);
  vector<int> last_loc(k + 1);

  for (int e, i = 1; i <= n; ++i)
  {
    cin >> e;
    int gap = i - last_loc[e] - 1;
    if (gap > largest_gap[e])
    {
      second_largest_gap[e] = largest_gap[e];
      largest_gap[e] = gap;
    }
    else if (gap > second_largest_gap[e])
    {
      second_largest_gap[e] = gap;
    }
    last_loc[e] = i;
  }

  int res = INT_MAX;

  for (int i = 1; i <= k; ++i)
  {
    int gap = n - last_loc[i];
    if (gap > largest_gap[i])
    {
      second_largest_gap[i] = largest_gap[i];
      largest_gap[i] = gap;
    }
    else if (gap > second_largest_gap[i])
    {
      second_largest_gap[i] = gap;
    }

    res = min(res, max(largest_gap[i] / 2, second_largest_gap[i]));
  }
  std::cout << res << '\n';
}

// [B. Vika and the Bridge] (https://codeforces.com/problemset/problem/1848/B)
// [2026-09-21] [17:41:54]
