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
  int n, q;
  cin >> n >> q;

  std::vector<int> a(51);
  for (int e, i = 1; i <= n; ++i)
  {
    cin >> e;
    if (not a[e])
      a[e] = i;
  }

  for (int e, i = 0; i < q; ++i)
  {
    cin >> e;
    int pos = a[e];
    for (int j = 1; j <= 50; ++j)
    {
      if (a[j] and a[j] < pos)
        a[j]++;
    }
    a[e] = 1;
    cout << pos << ' ';
  }
  cout << '\n';
}
/*

  int idx = 0;
  std::vector<int> steps;
  for (int e, i = 0; i < q; ++i)
  {
    cin >> e;
    int pos = a[e];
    int start = 0;

    if (pos <= 0)
    {
      start = -pos + 1;
      pos = 1;
    }

    for (int j = start; j < steps.size(); ++j)
    {
      if (pos < steps[j])
        pos++;
    }
    steps.push_back(pos);
    a[e] = idx--;

    cout << pos << ' ';
  }
  cout << '\n';

*/


// [C. Yet Another Card Deck] (https://codeforces.com/problemset/problem/1511/C)
// [2026-09-10] [19:17:33]
