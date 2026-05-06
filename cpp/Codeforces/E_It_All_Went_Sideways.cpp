#include <bits/stdc++.h>
using namespace std;

typedef int64_t s64;
typedef uint64_t u64;
typedef long double r64;

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

	s64 t;
	cin >> t;

	while (t--)
	{
		solve();
	}

	return 0;
}

void solve()
{
  int n;
  cin >> n;
  std::vector<int> a(n);

  u64 total = 0;
  for (auto &e : a)
  {
    cin >> e;
    total += e;
  }

  std::vector<int> suf_min(n);
  suf_min[n - 1] = a[n - 1];
  total -= suf_min[n - 1];
  for (int i = n - 2; i >= 0; --i)
  {
    suf_min[i] = min(suf_min[i + 1], a[i]);
    total -= suf_min[i];
  }

  int max_seq = 1;
  for (int curr_seq = 1, i = 1; i < n; ++i)
  {
    if (suf_min[i - 1] == suf_min[i])
    {
      curr_seq++;
      max_seq = max(max_seq, curr_seq);
    } else
      curr_seq = 1;
  }

  total += max_seq - 1;
  cout << total << '\n';
}  