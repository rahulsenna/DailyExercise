#include <bits/stdc++.h>
using namespace std;

typedef int64_t s64;
typedef uint64_t u64;
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
int main()
{
	setup();

	s64 t;
	cin >> t;

	while (t--)
	{
		solve();
	}

	return 0;
}

void solve()
{
  int n;
  cin >> n;
  int N = n * 2;

  std::vector<int> a(n * 2);
  for (auto &e : a)
    cin >> e;

  int res = 1;

  auto spread = [&](int l, int r) {
    std::vector<bool> seen(N + 1);
    while (l >= 0 && r < N && a[l] == a[r])
    {
      seen[a[l]] = true;
      l--;
      r++;
    }

    int mex = 0;
    while (seen[mex]) mex++;
    res = max(res, mex);
  };

  for (int i = 0; i < N; ++i)
  {
    spread(i, i);
    spread(i, i + 1);
  }

  std::cout << res << '\n';
}