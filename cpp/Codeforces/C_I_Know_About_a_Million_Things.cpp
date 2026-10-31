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
	cin >> t;
	while (t--)
		solve();
	return 0;
}

void solve()
{
  int n;
  cin >> n;

  std::vector<int> a(n);
  int sum = 0, odds = 0;
  for (auto &e : a)
  {
    cin >> e;
    sum += e;
    if (e & 1)
      odds++;
  }

  if (n == 1 or not(sum & 1))
  {
    cout << "Moggity\n";
    return;
  }

  if (n == 2 or (n == 3 and odds == 3))
    cout << "Larpity\n";
  else
    cout << "Moggity\n";
}

// [C. I Know About a Million Things] (https://codeforces.com/contest/2261/problem/C)
// [2026-10-31] [20:27:18]
