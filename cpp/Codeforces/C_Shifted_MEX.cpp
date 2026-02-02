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
	vector<s64> nums(n);

	for (auto &e: nums)
		cin >> e;

	std::ranges::sort(nums);
	
	int res = 1;
	int series = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == nums[i - 1])
			continue;
		if (abs(nums[i] - nums[i - 1]) > 1)
			series = 0;
		else
			series++;
		res = max(res, series + 1);
	}
	cout << res << '\n';
}