#include <bits/stdc++.h>
using namespace std;

typedef int64_t     s64;
typedef uint64_t    u64;
typedef long double r64;

inline void setup()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
}

#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif
void solve();
int  main()
{
  setup();

  solve();

  return 0;
}

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<s64> a(n);
  for (auto &e : a) cin >> e;

  std::vector<s64> damage_forward(n + 1);
  std::vector<s64> damage_backward(n + 1);

  for (int i = 1; i < n; ++i)
    damage_forward[i + 1] = damage_forward[i] + max(0LL, a[i - 1] - a[i]);

  for (int i = n; i > 1; --i)
    damage_backward[i - 1] = damage_backward[i] + max(0LL, a[i - 1] - a[i - 2]);

  s64 res = 0;
  for (int j = 0; j < m; ++j)
  {
    int s, t;
    cin >> s >> t;

    if (s < t)
      res = damage_forward[t] - damage_forward[s];
    else
      res = damage_backward[t] - damage_backward[s];

    cout << res << '\n';
  }
}