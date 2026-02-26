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
  std::vector<int> p(n);
  for (auto &e : p)
    cin >> e;
  
  if (n == 1)
  {
    cout << "-1\n";
    return;
  }

  auto q = p;
  std::ranges::sort(q);

  for (int i = 0; i < n - 1; ++i)
  {
    if (p[i] == q[i])
      swap(q[i], q[i + 1]);
  }
  if (p[n - 1] == q[n - 1])
    swap(q[n - 1], q[n - 2]);

  for (auto e : q)
    cout << e << ' ';
  cout << '\n';
}