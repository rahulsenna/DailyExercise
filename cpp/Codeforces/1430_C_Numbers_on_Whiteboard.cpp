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
	vector<int> A(n);
	//for(int i=1;i<=n; i++)
	//	A[i-1]=i;

	int last = n+ n-1;
	if (last&1)
	    last++;
 	last /= 2;
	cout << "2\n";
	cout << n  << ' ' << n-1 << '\n';
	n-=2;
	while(n>0){
		cout << last << ' ' << n << '\n';
		last = (last+n);
		if (last&1)
			last++;
		last /= 2;
		n--;
	}
}
