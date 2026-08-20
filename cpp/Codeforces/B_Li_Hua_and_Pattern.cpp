#include <bits/stdc++.h>
using namespace std;
typedef uint32_t u32; typedef int64_t s64; typedef uint64_t u64; typedef long double r64;
#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
	uint64_t t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}

void solve()
{
  int n, k;
  cin >> n >> k;

  vector<uint8_t> a(n * n);

  for (auto &e : a)
    cin >> e;

  int changes = 0;

  for (int i = 0; i < (n * n)/2; ++i)
  {
    int j = n * n - 1 - i;
    if (a[i] != a[j])
    {
      if (++changes > k)
        break;
    }
  }
  k -= changes;
  if (k >= 0 and (!(k & 1) or n & 1))
    cout << "YES\n";
  else
    cout << "NO\n";
}

// [B. Li Hua and Pattern] (https://codeforces.com/problemset/problem/1797/B)
// [2026-08-20] [07:23:58]
