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
  std::unordered_map<int, vector<int>> shoe_groups;
  for (int shoe_size, i = 0; i < n; ++i)
  {
    cin >> shoe_size;
    shoe_groups[shoe_size].push_back(i);
  }

  std::vector<int> assigned_shoe(n);

  for (auto &[size, students] : shoe_groups)
  {
    if (students.size() <= 1)
    {
      cout << "-1\n";
      return;
    }

    for (int j = 0; j < students.size() - 1; ++j)
    {
      assigned_shoe[students[j]] = students[j + 1] + 1;
    }

    assigned_shoe[students.back()] = students[0] + 1;
  }

  for (auto shoe : assigned_shoe)
    cout << shoe << ' ';
  cout << '\n';
}

// [B. Shoe Shuffling] (https://codeforces.com/problemset/problem/1691/B)
// [2026-07-07] [18:33:27]
