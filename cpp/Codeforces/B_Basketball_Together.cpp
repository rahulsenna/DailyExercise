#include <bits/stdc++.h>
using namespace std;
typedef uint32_t u32; typedef int64_t s64; typedef uint64_t u64; typedef long double r64;
#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
	uint64_t t;
	solve();
	return 0;
}

void solve()
{
  int N, D;
  cin >> N >> D;

  std::vector<int> players(N);
  for (auto &e: players)
    cin >> e;

  std::sort(players.begin(), players.end());
  int remaining = N;
  int res = 0;
  while(remaining > 0)
  {
    int need = (D / players.back()) + 1;
    remaining -= need;
    if (remaining >= 0)
      res++;
    players.pop_back();
  }
  std::cout << res << '\n';  
}

// [B. Basketball Together] (https://codeforces.com/problemset/problem/1725/B)
// [2026-07-01] [18:19:10]
