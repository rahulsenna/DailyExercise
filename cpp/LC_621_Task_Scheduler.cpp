#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int leastInterval(vector<char> &tasks, int n)
	{
		std::unordered_map<char, int> mp;
		for (auto c : tasks)
			mp[c]++;
		std::priority_queue<int> pq;
		for (auto &[k, freq] : mp)
			pq.push(freq);

		std::vector<int> leftover;
		leftover.reserve(pq.size());
		int res = 0;

		while (!pq.empty())
		{
			leftover.clear();
			int interval = n + 1;

			while (interval && !pq.empty())
			{
				int top = pq.top();
				pq.pop();
				interval--;

				if (top - 1 > 0)
					leftover.push_back(top - 1);

				res++;
			}

			// pq.push_range(leftover); // cpp23
			for (auto e : leftover)
				pq.push(e);

			if (!pq.empty())
				res += interval;
		}

		return res;
	}
};

int main()
{

	vector<char> input {'A','A','A','B','B','B'};
	int n = 2;
	Solution sol;
	auto res = sol.leastInterval(input, n);
	
	return(0);
}