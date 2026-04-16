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

	{
		solve();
	}

	return 0;
}

void solve()
{
  int n;
  cin >> n;
  s64 a, A = 0, B = 0, C = 0;
  
  for (int i = 0; i < n; ++i)
  {
  	 cin >> a;
     A ^= a;
  }
  for (int i = 0; i < n-1; ++i)
  {
  	 cin >> a;
     B ^= a;
  }
  
  for (int i = 0; i < n-2; ++i)
  {
  	 cin >> a;
     C ^= a;
  }
  cout << (A ^ B) << '\n';
  cout << (B ^ C) << '\n';
}