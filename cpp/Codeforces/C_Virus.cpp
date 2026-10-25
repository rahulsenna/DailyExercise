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
  int n, m;
  cin >> n >> m;

  std::vector<int> a(m);
  for (auto &e : a)
    cin >> e;

  std::sort(a.begin(), a.end());

  std::vector<int> gap_s;

  for (int i = 1; i < m; ++i)
    gap_s.push_back(a[i] - a[i - 1] - 1);

  gap_s.push_back((n + a.front()) - a.back() - 1);

  std::sort(gap_s.begin(), gap_s.end(), greater<>());

  int res = n, days_p = 0;

  for (auto gap : gap_s)
  {
    int save_pot = gap - days_p * 2;
    if (save_pot <= 0)
      break;

    if (save_pot == 1)
    {
      res -= 1;
      days_p += 1;
    }
    else
    {
      res -= (save_pot - 1);
      days_p += 2;
    }
  }

  std::cout << res << '\n';
}

// [C. Virus] (https://codeforces.com/problemset/problem/1704/C)
// [2026-10-26] [01:01:49]
