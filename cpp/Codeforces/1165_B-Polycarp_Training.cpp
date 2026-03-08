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
	solve();
	return 0;
}

void solve()
{
	int n;
	cin >> n;
  vector<int> a(n);
  for (auto& e : a)
    cin >> e;

  std::ranges::sort(a);

  int res = 0;
  for (auto e : a){
    if (e >= res+1)
      res++;
  }
  cout << res << '\n';
}
