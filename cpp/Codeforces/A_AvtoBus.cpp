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
  u64 n;
  cin >> n;
  if (n & 1 or n < 4)
  {
    cout << "-1\n";
    return;
  }

  u64 mx = n / 4;      //  n % 4 ~= 0 and 2, (when n is even), when its 2 remove the last 4w bus make 4 + 2 (remainder) 6w bus
  u64 mn = (n + 5) / 6;//  n % 6 ~= 0, 2, and 4 (when n is even), when its 2 remove the last 6w bus make two 4w bus
                       // when remainder is 4 just add one extra 4w bus

  cout << mn << ' ' << mx << '\n';
}