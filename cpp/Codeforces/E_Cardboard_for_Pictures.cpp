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
  s64 n, c;
  cin >> n >> c;

  std::vector<s64> a(n);
  for (auto &e : a)
    cin >> e;

  std::sort(a.begin(), a.end(), greater<>());

  s64 l = 1, h = sqrt(c - n);
  s64 res = 0;

  while (l <= h)
  {
    s64 mid = (l + h + 1ll) / 2ll;

    s64 sum = 0;
    for (auto e : a)
    {
      sum += (e + mid * 2) * (e + mid * 2);
      if (sum > c)
        break;
    }
    if (c == sum)
    {
      std::cout << mid << '\n';
      return;
    }

    if (sum > c)
      h = mid - 1ll;
    else
      l = mid + 1ll;
  }
}

/*
void solve()
{
  s64 n, c;
  cin >> n >> c;

  s64 sum_s = 0;
  s64 sum_s2 = 0;

  for (int i = 0; i < n; ++i)
  {
    s64 e;
    cin >> e;
    sum_s += e;
    sum_s2 += e * e;
  }

  // Coefficients for A*w^2 + B*w + C = 0
  __int128 A = n;
  __int128 B = sum_s;
  __int128 C = (sum_s2 - c) / 4; 

  // Discriminant D = B^2 - 4AC
  __int128 D = B * B - 4 * A * C;

  // Approximate the square root using double
  s64 sq = sqrt((double)D);
  
  // Bulletproof adjustment for any floating-point inaccuracies
  while ((__int128)sq * sq < D) sq++;
  while ((__int128)sq * sq > D) sq--;

  // w = (-B + sqrt(D)) / (2A)
  s64 w = (sq - (s64)B) / (2 * (s64)A);

  cout << w << '\n';
}
*/

// [E. Cardboard for Pictures] (https://codeforces.com/problemset/problem/1850/E)
// [2026-08-10] [16:48:30]
