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
  u64 n;
  cin >> n;
  std::vector<u64> a(n);
  for (auto &e : a)
    cin >> e;

  u64 A = 0, B = 0;
  for (int i = 0; i < n; i += 2)
    A = gcd(A, a[i]);
  for (int i = 1; i < n; i += 2)
    B = gcd(B, a[i]);

  bool gcd_not_divisible = true;
  for (int i = 1; i < n; i += 2)
  {
    if (a[i] % A == 0)
    {
      gcd_not_divisible = false;
      break;
    }
  }
  if (gcd_not_divisible)
  {
    cout << A << '\n';
    return;
  }

  gcd_not_divisible = true;
  for (int i = 0; i < n; i += 2)
  {
    if (a[i] % B == 0)
    {
      gcd_not_divisible = false;
      break;
    }
  }

  if (gcd_not_divisible)
    cout << B << '\n';
  else
    cout << 0 << '\n';
}

// [C. Paint the Array] (https://codeforces.com/problemset/problem/1618/C)
// [2026-09-07] [18:30:44]
