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
  int n;
  cin >> n;
  std::vector<int> a(n);
  std::vector<int> A(n);

  for (auto &e : a)
    cin >> e;

  for (auto &e : A)
    cin >> e;
  int l = 0, r = 0;
  while (a[r] == A[r]) r++;
  l = r;
  
  while (l > 0 and A[l - 1] <= A[l]) l--;
  while (r < n - 1 and A[r + 1] >= A[r]) r++;

  std::cout << l + 1 << ' ' << r + 1 << '\n';
}

// [B. Sort the Subarray] (https://codeforces.com/problemset/problem/1821/B)
// [2026-08-16] [02:44:10]
