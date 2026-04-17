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
	};

	return 0;
}

void solve()
{
  int n;
  cin >> n;
  std::vector<int> C(n);

  for (auto &e : C)
    cin >> e;

  int a = 0, b = n - 1;

  int res = 0;

  int aw = 0, bw = 0;

  while (a <= b)
  {
    if (aw <= bw)
      aw += C[a++];
    else
      bw += C[b--];

    if (aw == bw)
    {
      res = a + (n - b - 1);
    }
  }

  std::cout << res << '\n';
}