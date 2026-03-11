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

void solve()
{
	int n;
	cin >> n;
  vector<s64> a(n), mx(n), px(n+1);
  s64 max_ai = 0;
  for (s64 ai, i = 0; i < n; i++) {
    cin >> ai;
    a[i] = ai;
    mx[i] = max_ai;
    max_ai = max(max_ai, ai);
  }
  for (s64 i = n-1; i >= 0; i--) {
    px[i] = px[i+1]+a[i];
  }
  for (s64 i = n-1; i >=0 ; i--) {
    if (mx[i]> a[i]){
      cout << px[i] - a[i]+mx[i] << ' ';
    }
    else {
      cout << px[i] << ' ';
    }
  }
  cout << '\n';
}
