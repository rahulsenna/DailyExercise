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

  {
    solve();
  }

  return 0;
}

void solve()
{
  bool seen[100001] = {false};
  int  n, m;
  cin >> n >> m;
  std::vector<int> a(n);
  for (auto &e : a)
    cin >> e;

  std::vector<int> pre(n);

  int cnt_size = 0;

  for (int i = n - 1; i >= 0; i--)
  {
    if (seen[a[i]] == 0)
      cnt_size++;
    seen[a[i]] = 1;

    pre[i] = cnt_size;
  }
  int l;
  for (int i = 0; i < m; ++i)
  {
    cin >> l;
    cout << pre[l - 1] << '\n';
  }
}