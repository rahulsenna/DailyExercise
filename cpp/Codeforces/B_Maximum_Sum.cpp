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
  s64 total = 0;
  for (auto &e : a)
  {
    cin >> e;
    total += e;
  }
  std::sort(a.begin(), a.end());
  int K = n - k;
  s64 remove_sum = accumulate(a.begin() + n - k, a.end(), 0LL);
  s64 min_remove_sum = remove_sum;
  for (int i = 0; i < k * 2; i += 2)
  {
    remove_sum -= a[K++];
    remove_sum += a[i] + a[i + 1];
    min_remove_sum = min(min_remove_sum, remove_sum);
  }

  std::cout << total - min_remove_sum << '\n';
}

// [B. Maximum Sum] (https://codeforces.com/problemset/problem/1832/B)
// [2026-08-13] [01:51:02]
