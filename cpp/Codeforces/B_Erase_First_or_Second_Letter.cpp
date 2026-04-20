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
  string s;
  cin >> n >> s;
  bool seen[26] = {0};
  int distinct = 0;
  int res = 0;

  for (int i = 0; i < n; ++i)
  {
    int c = s[i] - 'a';
    if (!seen[c])
    {
      seen[c] = 1;
      distinct++;
    }
    res += distinct;
    // all distinct string of len n will have fixed last n-1 chars
    // how many distinct chars so far tell how many distinct strings can be created of len n
  }

  std::cout << res << '\n';
}



/* 
official DP
void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<long long> ans(n, 0);
  vector<int>       nxt(26, n);
  ans[n - 1]          = 1;
  nxt[s[n - 1] - 'a'] = n - 1;

  for (int i = n - 2; i >= 0; i--)
  {
    ans[i]          = ans[i+1] + (nxt[s[i]-'a'] - i);
    nxt[s[i]-'a'] = i;
  }

  cout << ans[0] << endl;
}
*/