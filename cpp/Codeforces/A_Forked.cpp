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
  int a, b, k1, k2, q1, q2;
  cin >> a >> b >> k1 >> k2 >> q1 >> q2;

  std::set<pair<int, int>> K, Q;
  for (int i = 0; i < 2; ++i)
  {
    K.insert({k1+a, k2+b});
    K.insert({k1-a, k2-b});
    K.insert({k1+a, k2-b});
    K.insert({k1-a, k2+b});

    Q.insert({q1+a, q2+b});
    Q.insert({q1-a, q2-b});
    Q.insert({q1+a, q2-b});
    Q.insert({q1-a, q2+b});
  	swap(a,b);
  }
  
  std::set<pair<int,int>> result;
  std::set_intersection(K.begin(), K.end(), Q.begin(), Q.end(), std::inserter(result,result.begin()));
  std::cout << result.size() << '\n';
}