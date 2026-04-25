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
  int n, k, x;
  cin >> n >> k >> x;

  if (x != 1)
  {
    cout << "YES\n" << n << '\n';
    for (int i = 0; i < n; ++i) cout << "1 ";
    cout << '\n';
  } else if (not(n & 1) and k >= 2)
  {
    cout << "YES\n" << n / 2 << '\n';
    for (int i = 0; i < n / 2; ++i) cout << "2 ";
    cout << "\n";
  } else if (k >= 3)
  {
    cout << "YES\n" << (n - 3) / 2 + 1 << '\n';
    for (int i = 0; i < (n - 3) / 2; ++i) cout << "2 ";
    cout << "3\n";
  } else
    cout << "NO\n";
}