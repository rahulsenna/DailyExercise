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

  std::vector<int> a(n);
  for (auto &e : a)
    cin >> e;

  int min_n = INT_MAX;
  int max_n = INT_MIN;

  string res(n, '0');
  for (int i = 0, j = n - 1; i < n; ++i, --j)
  {
    min_n = min(min_n, a[i]);
    max_n = max(max_n, a[j]);
    if (min_n >= a[i])
      res[i] = '1';
    if (max_n <= a[j])
      res[j] = '1';
  }

  cout << res << '\n';
}