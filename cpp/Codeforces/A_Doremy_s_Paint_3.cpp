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
  std::unordered_map<int, int> mp;
  for (int a, i = 0; i < n; ++i)
  {
    cin >> a;
    mp[a]++;
  }

  if (mp.size() > 2)
  {
    std::cout << "No\n";
    return;
  } else if (mp.size() == 1)
  {
    std::cout << "Yes\n";
    return;
  }

  std::vector<std::pair<int, int>> freq{mp.begin(), mp.end()};

  if (abs(freq[0].second - freq[1].second) > 1)
    std::cout << "No\n";
  else
    std::cout << "Yes\n";
}