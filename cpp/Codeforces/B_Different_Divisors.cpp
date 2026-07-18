#include <bits/stdc++.h>
using namespace std;
typedef uint32_t u32; typedef int64_t s64; typedef uint64_t u64; typedef long double r64;
#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif
void solve();

vector<bool> primes(30000 + 1, true);
void sieve()
{
  primes[0] = false;
  primes[1] = false;
  for (int i = 2; i * i <= 30000; ++i)
  {
    if (primes[i])
    {
      for (int j = i * i; j <= 30000; j += i)
      {
        primes[j] = false;
      }
    }
  }
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif

  sieve();
	uint64_t t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}

bool is_prime(int N)
{
  if (N <= 1) return false;
  if (N <= 3) return true;
  if (N % 2 == 0 or N % 3 == 0) return false;

  for (int i = 5; i*i <= N; i+=6)
    if (N % i == 0 or N % (i + 2) == 0)
      return false;

  return true;
}

void solve()
{
  u64 d;
  cin >> d;

  u64 a = d + 1;
  while (!primes[a])
    a++;
  u64 b = a + d;
  while (!primes[b])
    b++;
  cout << a * b << '\n';
}

// [B. Different Divisors] (https://codeforces.com/problemset/problem/1474/B)
// [2026-07-18] [19:36:17]
