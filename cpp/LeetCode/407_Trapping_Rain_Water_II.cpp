#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <queue>

using namespace std;

int trapRainWater(vector<vector<int>> &heightMap)
{

	int height = heightMap.size();
	int width	 = heightMap[0].size();

	std::vector<std::pair<int, int>> D{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	using height_xy = pair<int,pair<int,int>>;
	std::priority_queue<height_xy, std::vector<height_xy>, greater<>> pq;

	vector<vector<bool>> seen(height, vector<bool>(width, false));

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (not(x == 0 or x == width - 1 or y == 0 or y == height - 1))
				continue;
			seen[y][x] = true;
			pq.push({heightMap[y][x], {x, y}});
		}
	}
	int res = 0;
	while (not pq.empty())
	{
		auto top = pq.top();
		int	 h = top.first, x = top.second.first, y = top.second.second;
		int	 d = 5;
		pq.pop();

		for (int i = 0; i < 4; ++i)
		{
			int dx = x + D[i].first;
			int dy = y + D[i].second;
			if (dx <= 0 or dx >= width or dy <= 0 or dy >= height or seen[dy][dx])
				continue;

			seen[dy][dx] = true;
			int cH = heightMap[dy][dx];
			int mH = max(h, cH);
			pq.push({mH, {dx, dy}});
			res += max(0, mH - cH);
		}
	}

	return res;
}

int main()
{
	/* 
	
	[1,4,3,1,3,2,]
	[3,2,1,3,2,4,]
	[2,3,3,2,3,1,]
	
	[3,3,3,3,3]
	[3,2,2,2,3]
	[3,2,1,2,3]
	[3,2,2,2,3]
	[3,3,3,3,3]
 */
	// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
	// Output: 4

	// Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
	// Output: 10

	std::vector<std::vector<int>> heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
	// Output: 4
	// std::vector<std::vector<int>> heightMap = {{3, 3, 3, 3, 3}, {3, 2, 2, 2, 3}, {3, 2, 1, 2, 3}, {3, 2, 2, 2, 3}, {3, 3, 3, 3, 3}};

	auto res = trapRainWater(heightMap);
	std::cout << res << '\n';

	return (0);
}