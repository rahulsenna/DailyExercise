#include <bits/stdc++.h>
using namespace std;
typedef uint32_t u32; typedef int64_t s64; typedef uint64_t u64; typedef long double r64;
inline void setup() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
	uint64_t t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}

void solve()
{
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  std::vector<pair<char, char>> ends{{'0', '0'}, {'0', '5'}, {'5', '2'}, {'5', '7'}};

  int res = INT_MAX;
  for (auto [a, b] : ends)
  {
    int a_i = s.find(a);
    if (a_i == -1) continue;
    int b_i = s.find(b, a_i + 1);
    if (b_i == -1) continue;
    res = min(res, b_i - 1); // -1 not -2 because zero indexed
  }

  std::cout << res << '\n';
}