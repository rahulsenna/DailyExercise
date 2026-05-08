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
  int T = 0;
	while (++T <=t)
  {
 /*    if (T==102)
    {
      int n;
      cin >> n;
      std::vector<int> a(n);
      for (auto &e : a) cin >> e;

      cout  << n;
      for (auto e : a) cout << e;
      cout << "\n";
    } */

    solve();
  }
		
	return 0;
}


void solve()
{
  int n;
  cin >> n;
  vector<int> a(n + 1), cnt(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    cnt[a[i]]++;
  }

  vector<int> cubes_at_i_height(n + 1);
  cubes_at_i_height[n] = cnt[n];
  for (int i = n - 1; i >= 1; i--) cubes_at_i_height[i] = cubes_at_i_height[i + 1] + cnt[i];

  s64 init = 0, final = 0;
  for (s64 i = 1; i <= n; i++)
  {
    init += i * a[i];

    s64 k     = cubes_at_i_height[i];
    s64 start = n - k + 1;// example n=10 k=3 == 8 9 10, n-k = 7+1 = 8
    s64 end   = n;
    final += k * (start + end) / 2;// same as init += i * a[i]; but for all sorted_i...n at once
  }

  s64 res      = final - init;
  s64 max_gain = 0;
  for (int i = 1; i <= n; i++)
  {
    s64 sorted_i = n - cubes_at_i_height[a[i]] + 1;
    s64 gain     = i - sorted_i;
    max_gain     = max(max_gain, gain);
  }

  cout << res + max_gain << endl;
}

#if 0
/* Sorting */
void solve()
{
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  std::vector<int> right = a;
  std::sort(right.begin(), right.end());

  u64 init = 0, final = 0;
  for (u64 i = 1; i <= n; i++)
  {
    init += i * a[i];
    final += i * right[i];
  }

  s64 res      = final - init;
  s64 max_gain = 0;

  for (int i = 1; i <= n; i++)
  {
    auto lb       = std::lower_bound(right.begin() + 1, right.end(), a[i]);
    auto sorted_i = std::distance(right.begin(), lb);
    s64  gain     = i - sorted_i;
    max_gain      = std::max(max_gain, gain);
  }

  std::cout << res + max_gain << '\n';
}
#endif