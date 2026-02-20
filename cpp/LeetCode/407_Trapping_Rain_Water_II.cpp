#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <queue>

using namespace std;

/* 
int trapRainWater(vector<vector<int>> &heightMap)
{
	int height = heightMap.size();
	int width	 = heightMap[0].size();

	vector<vector<int>> leftMap = heightMap;
	for (int y = 0; y < height; ++y)
	{
		int left_max = 0;
		for (int x = 0; x < width; ++x)
		{
			leftMap[y][x] = left_max;
			left_max			= max(left_max, heightMap[y][x]);
		}
	}

	vector<vector<int>> rightMap = heightMap;
	for (int y = 0; y < height; ++y)
	{
		int right_max = 0;
		for (int x = width - 1; x >= 0; --x)
		{
			rightMap[y][x] = right_max;
			right_max			 = max(right_max, heightMap[y][x]);
		}
	}

	vector<vector<int>> upMap = heightMap;
	for (int x = 0; x < width; ++x)
	{
		int up_max = 0;
		for (int y = 0; y < height; ++y)
		{
			upMap[y][x] = up_max;
			up_max			= max(up_max, heightMap[y][x]);
		}
	}

	vector<vector<int>> downMap = heightMap;
	for (int x = 0; x < width; ++x)
	{
		int up_max = 0;
		for (int y = height - 1; y >= 0; --y)
		{
			downMap[y][x] = up_max;
			up_max				= max(up_max, heightMap[y][x]);
		}
	}

	int res = 0;

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int m = min(min(upMap[y][x], downMap[y][x]), min(leftMap[y][x], rightMap[y][x]));
			res += max(0, m - heightMap[y][x]);
		}
	}

	return res;
} */
/*
int trapRainWater(vector<vector<int>> &heightMap)
{
	int height = heightMap.size();
	int width	 = heightMap[0].size();

	std::vector<pair<int, int>> dirs = {
	{ 1,  0},
	{ 0,  1},
	{-1,  0},
	{ 0, -1}};

	set<pair<int,int>> seen {};

	int water_level = 0;
	int new_water_level = INT_MAX;
	int dir_idx = 0;
	int x = 0, y = 0;

	int res = 0;
	while(1)
	{
		x += dirs[dir_idx].first;
		y += dirs[dir_idx].second;
		if (seen.count({x,y}) or x >= width or x < 0 or y >= height or y < 0)
		{
			x -= dirs[dir_idx].first;
			y -= dirs[dir_idx].second;
			dir_idx = (dir_idx + 1) % 4;

			if (dir_idx == 0)
			{
				water_level = max(water_level, new_water_level);
				new_water_level = INT_MAX;
			}
			continue;
		}

		seen.insert({x,y});

		res += max(0, water_level - heightMap[y][x]);
		new_water_level = min (new_water_level, heightMap[y][x]);

		
		if (seen.size() >= height*width)
		{ 
			break;
		}
	}

	return res;
} */

int trapRainWater(vector<vector<int>> &heightMap)
{

	int height = heightMap.size();
	int width	 = heightMap[0].size();

	std::vector<std::pair<int, int>> D{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, greater<>> pq;

	std::set<pair<int, int>> seen;

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (not(x == 0 or x == width - 1 or y == 0 or y == height - 1))
				continue;
			seen.insert({x, y});
			pq.push({heightMap[y][x], x, y});
		}
	}
	int res = 0;
	while (not pq.empty())
	{
		auto top = pq.top();
		int	 h = top[0], x = top[1], y = top[2];
		int	 d = 5;
		pq.pop();

		for (int i = 0; i < 4; ++i)
		{
			int dx = x + D[i].first;
			int dy = y + D[i].second;
			if (dx <= 0 or dx >= width or dy <= 0 or dy >= height or seen.count({dx, dy}))
				continue;

			seen.insert({dx, dy});
			int cH = heightMap[dy][dx];
			int mH = max(h, cH);
			pq.push({mH, dx, dy});
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