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
  int n, x;
  cin >> n >> x;
  std::vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  int fuel_tank = (x - a.back()) * 2;
  for (int i = 1; i <= n; ++i)
    fuel_tank = max(fuel_tank, a[i] - a[i - 1]);
  
  std::cout << fuel_tank << '\n';
}