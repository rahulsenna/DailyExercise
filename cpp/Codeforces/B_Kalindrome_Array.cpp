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

bool is_palindrome(vector<int> arr, int skip = 0)
{
  int l = 0, r = arr.size()-1;

  while(l < r)
  {
    while (l <= r and arr[l] == skip) l++;
    while (l <= r and arr[r] == skip) r--;
    if (arr[l] != arr[r])
      return false;
    l++, r--;
  }
  return true;
}

void solve()
{
  int n;
  cin >> n;
  std::vector<int> a(n);
  for (auto &e : a)
    cin >> e;

  int l = 0, r = n - 1;
  while (l < r and a[l] == a[r])
    l++, r--;

  if (l >= r or is_palindrome(a, a[l]) or is_palindrome(a, a[r]))
    cout << "YES\n";
  else
    cout << "NO\n";
}

// [B. Kalindrome Array] (https://codeforces.com/problemset/problem/1610/B)
// [2026-09-09] [17:32:25]
