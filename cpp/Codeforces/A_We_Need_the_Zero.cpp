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


int count(bool mp[256])
{
  int res = 0;
  for (int i = 0; i < 256; ++i)
  	 if (mp[i]) res++;

  return res;
}
void solve()
{
  int n;
  cin >> n;
  bool mp[256] = {0};
  int  final   = 0;
  for (int a, i = 0; i < n; ++i)
  {
    cin >> a;
    mp[a] = true;
    final ^= a;
  }

  if (n & 1 or final == 0)
  {
    cout << final << '\n';
    return;
  } else
    cout << "-1\n";
}