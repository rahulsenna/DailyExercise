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
	solve();
	return 0;
}

void solve()
{
  s64 n, q;
  cin >> n >> q;
  std::vector<int> a(n + 1), last_updated(n + 1, -1);
  s64 sum = 0;
  for (int i = 1; i <= n; ++i)
  {
    cin >> a[i];
    sum += a[i];
  }

  s64 x, idx, val, last_set = 0, last_set_idx = -1;
  for (int i = 1; i <= q; ++i)
  {
    cin >> x;
    if (x == 1)
    {
      cin >> idx >> val;
      int net = (last_updated[idx] < last_set_idx) ? val - last_set : net = val - a[idx];
      a[idx] = val;
      last_updated[idx] = i;
      sum += net;
    }
    else
    {
      cin >> val;
      sum = n * val;
      last_set = val;
      last_set_idx = i;
    }
    cout << sum << '\n';
  }
}

// [B. Stone Age Problem] (https://codeforces.com/problemset/problem/1679/B)
// [2026-11-13] [21:13:37]
