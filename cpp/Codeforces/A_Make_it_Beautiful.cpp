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

  sort(a.begin(), a.end(), std::greater<int>());

  if (a[0] == a[n-1])
  {
    cout << "NO\n";
    return;
  }

  cout << "YES\n"
       << a[n - 1] << ' ';
  for (int i = 0; i < n - 1; ++i)
    cout << a[i] << ' ';

  cout << '\n';
}