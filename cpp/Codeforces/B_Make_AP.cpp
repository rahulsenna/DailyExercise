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

  if ((a + c) % 2 == 0)
  {
    int target = (a + c) / 2;

    if (target > 0 && target % b == 0)
    {
      cout << "YES\n";
      return;
    }
  }

  int b2 = 2 * b;
  if ((b2 - c) > 0 && (b2 - c) % a == 0)
  {
    cout << "YES\n";
    return;
  }

  if ((b2 - a) > 0 && (b2 - a) % c == 0)
  {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
}