#include <bits/stdc++.h>
using namespace std;
typedef uint32_t u32;
typedef int64_t s64;
typedef uint64_t u64;
typedef long double r64;
#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif
void solve();
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout),
      freopen("error.txt", "w", stderr);
#endif
  uint64_t t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

void solve()
{
  s64 n, c;
  cin >> n >> c;

  auto a = vector<pair<s64, s64>>(n);
  for (s64 e, i = 1; i <= n; ++i)
  {
    cin >> e;
    a[i - 1] = {min(e + i, e + n + 1 - i), e + i};
  }
  std::sort(a.begin(), a.end());

  std::vector<s64> prefix(n);
  prefix[0] = a[0].first;
  for (s64 i = 1; i < n; ++i)
    prefix[i] = prefix[i - 1] + a[i].first;

  s64 res = 0;
  for (s64 i = 0; i < n; ++i)
  {
    s64 C = c - a[i].second;
    if (C < 0)
      continue;

    auto mid = upper_bound(prefix.begin(), prefix.end(), C);
    s64 dist = distance(prefix.begin(), mid);
    if (i < dist and (dist == n or C < *mid - a[i].first))
      dist--;

    res = max(res, dist + 1);
  }

  std::cout << res << '\n';
}

// [G2. Teleporters (Hard Version)]
// (https://codeforces.com/contest/1791/problem/G2) [2026-08-22] [01:43:23]
