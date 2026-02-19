#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int trap(vector<int> &height)
{
	int							 res = 0, max_right = 0, max_left = 0;
	std::vector<int> right_walls(height.size());
	for (int i = height.size() - 1; i >= 0; --i)
	{
		right_walls[i] = max_right;
		max_right			 = max(max_right, height[i]);
	}
	for (int i = 0; i < height.size(); ++i)
	{
		res += max(0, min(max_left, right_walls[i]) - height[i]);
		max_left = max(max_left, height[i]);
	}
	return res;
}

int main()
{
	// vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	vector<int> height = {4, 2, 0, 3, 2, 5};
	auto				res		 = trap(height);

	std::cout << "res: " << res << '\n';
	return (0);
}
