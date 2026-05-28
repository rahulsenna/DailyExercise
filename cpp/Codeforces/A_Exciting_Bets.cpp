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
  s64 a, b;
  cin >> a >> b;
  if (b > a)
    swap(a, b);

  s64 excitement = a - b;
  s64 moves = 0;

  if (excitement > 0)
  {
    s64 remainder = b % excitement;
    moves = min(remainder, excitement - remainder);
  }

  cout << excitement << ' ' << moves << '\n';
}