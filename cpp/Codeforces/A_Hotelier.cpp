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

	// s64 t;
	// cin >> t;

	// while (t--)
	{
		solve();
	}

	return 0;
}

void solve()
{
	int		 n;
	string events;
	cin >> n >> events;
	std::string rooms(10, '0');

	for (auto e : events)
	{
		if (e == 'L')
		{
			int idx = 0;
			while (rooms[idx] == '1') idx++;
			rooms[idx] = '1';
		} else if (e == 'R')
		{
			int idx = 9;
			while (rooms[idx] == '1') idx--;
			rooms[idx] = '1';
		} else
			rooms[e - '0'] = '0';
	}
	cout << rooms;
}