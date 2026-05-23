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
  int a, b, c;
  cin >> a >> b >> c;

  // 2b = (a + c)
  // a = 2b - c
  if ((2 * b - c) > 0 && (2 * b - c) % a == 0)
  {
    cout << "YES\n";
    return;
  }

  // b = (a + c) / 2
  if ((a + c) % 2 == 0 && ((a + c) / 2) % b == 0)
  {
    cout << "YES\n";
    return;
  }
  // c = 2b - a
  if ((2 * b - a) > 0 && (2 * b - a) % c == 0)
  {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
}