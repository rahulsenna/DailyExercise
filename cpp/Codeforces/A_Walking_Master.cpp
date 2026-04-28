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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (b > d or (b == d and a < c))
  {
    cout << "-1\n";
    return;
  }

  int up_dist = abs(b - d);
  a += up_dist;
  b += up_dist;

  if (b == d and a < c)
  {
    cout << "-1\n";
    return;
  }

  int left_dist = abs(a - c);
  cout << up_dist + left_dist << '\n';
}
/* // official solution
void solve()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (d < b || c > (d - b + a))
  {
    cout << "-1\n";
  } else
  {
    cout << d - b + (a + d - b - c) << '\n';
  }
}
  */