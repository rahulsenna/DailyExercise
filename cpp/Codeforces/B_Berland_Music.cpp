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
  std::vector<int> p(n), q(n);
  for (auto &e : p)
    cin >> e;

  std::vector<int> idx(n);
  for (int i = 0; i < n; ++i)
    idx[p[i] - 1] = i;

  string likes;
  cin >> likes;

  int cur = 1;
  for (auto e : idx)
  {
    if (likes[e] == '0')
      q[e] = cur++;
  }
  for (auto e : idx)
  {
    if (likes[e] == '1')
      q[e] = cur++;
  }

  for (auto e : q)
    cout << e << ' ';
  cout << '\n';
}
