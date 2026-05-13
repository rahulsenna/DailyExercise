#include <bits/stdc++.h>
using namespace std;

typedef uint32_t u32; typedef int64_t s64; typedef uint64_t u64; typedef long double r64;
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

  cin >> a[0];

  for (int i = 1; i < n; ++i)
  {
  	 cin >> a[i];

     if (a[i-i] == 1) a[i-i]++;
     if (a[i] == 1) a[i]++;

     if (a[i] % a[i-1] == 0) a[i]++;
  }

  for (auto &e: a)
  	cout << e << ' ';
  cout << '\n';
}