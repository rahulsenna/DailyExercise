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

  std::vector<int> a(n);
  for (auto &e : a)
    cin >> e;

  int res = 0, sum_a = 0, max_b = 0;
  for (int b, i = 0; i < n; ++i)
  {
    cin >> b;
    if (i >= k)
      continue;

    max_b = max(b, max_b);
    sum_a += a[i];

    res = max(res, sum_a + max_b * (k - (i + 1)));
  }
  std::cout << res << '\n';
}

#if 0
void solve()
{
  int n, k;
  cin >> n >> k;
  std::vector<int> a(n);
  std::vector<int> b(n);
  for (auto &e : a)
    cin >> e;
  for (auto &e : b)
    cin >> e;

  int K = min(n, k);
  std::vector<int> A(K);
  std::vector<int> B(K);

  A[0] = a[0];
  B[0] = b[0];
  for (int i = 1; i < K; ++i)
  {
    A[i] = A[i - 1] + a[i];
    B[i] = max(B[i - 1], b[i]);
  }
  int res = 0;

  for (int i = K - 1; i >= 0; --i)
  {
    int a = A[i], b = B[i] * max(0, k - (i + 1));
    int r = a + b;
    res = max(res, r);
  }

  std::cout << res << '\n';
}
#endif
// [C. Quests] (https://codeforces.com/problemset/problem/1914/C)
// [2026-07-31] [22:20:54]
