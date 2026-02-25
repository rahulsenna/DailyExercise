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
  int n, m;
  cin >> n >> m;

  std::vector<s64> a(n);
  s64              maxE = 0;
  for (auto &e : a)
  {
    cin >> e;
    maxE = max(maxE, e);
  }

  char sign;
  s64  l, r;
  for (int i = 0; i < m; ++i)
  {
    cin >> sign >> l >> r;
    s64 op = (sign == '+') ? 1LL : -1LL;
    if (maxE >= l and maxE <= r)
      maxE += op;

    cout << maxE << ' ';
  }
  cout << '\n';
}