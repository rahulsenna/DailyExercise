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

auto group = [](uint32_t x) -> int {
  bool d2 = x % 2 == 0;
  bool d3 = x % 3 == 0;
  if (d2 && d3) return 0;
  if (d2) return 1;
  if (!d3) return 2;
  return 3;
};

void solve()
{
  int n;
  cin >> n;
  std::vector<uint32_t> a(n);
  for (auto &e: a)
  	cin >> e;

  std::sort(a.begin(), a.end(), [&](auto x, auto y) { return group(x) < group(y); });

  for (auto &e: a)
  	cout << e << ' ';
  cout << '\n';
}