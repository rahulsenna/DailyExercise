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
  int N = n * (n - 1) / 2;

  std::vector<int> b(N);
  for (auto &e : b)
    cin >> e;

  std::sort(b.begin(), b.end());

  int b_idx = 0;
  for (int i = 0; i < n; ++i)
  {
    if (b_idx >= N)
      b_idx = N - 1;
    cout << b[b_idx] << ' ';

    b_idx += n - (i + 1);
  }

  cout << '\n';
}

// [C. Assembly via Minimums] (https://codeforces.com/problemset/problem/1857/C)
// [2026-09-20] [16:00:54]
