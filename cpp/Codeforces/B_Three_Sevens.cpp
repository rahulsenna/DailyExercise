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
  int M, n;
  cin >> M;

  std::unordered_map<int, int> last;
  for (int m = 0; m < M; ++m)
  {
    cin >> n;
    for (int a, i = 0; i < n; ++i)
    {
      cin >> a;
      last[a] = m;
    }
  }
  std::unordered_map<int, int> part;
  for (auto [p, day] : last)
    part[day] = p;

  if (part.size() < M)
  {
    cout << "-1\n";
    return;
  }
  std::vector<std::pair<int, int>> part_pairs{part.begin(), part.end()};
  std::ranges::sort(part_pairs);

  for (auto [day, p] : part_pairs)
    cout << p << ' ';

  std::cout << '\n';
}