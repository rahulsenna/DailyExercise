#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>> &heights)
{
  int D[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

  int height = heights.size();
  int width = heights[0].size();

  using HeightXY = pair<int, pair<int,int>>;

  std::priority_queue<HeightXY, std::vector<HeightXY>, std::greater<>> pq;
  pq.push({0, {0,0}});
  vector<vector<int>> effort(height, vector(width, INT_MAX));

  while(!pq.empty())
  {
    auto [h, xy] = pq.top();
    pq.pop();

    auto [x, y] = xy;

    if (x == width -1 and y == height -1)
    {
      return h;
    }
    if (h > effort[y][x])
      continue;

    for (int i = 0; i < 4; ++i)
    {
      int dx = D[i][0] + x;
      int dy = D[i][1] + y;

      if (dx < 0 or dx >= width or dy < 0 or dy >= height)
        continue;

      int climb      = abs(heights[dy][dx] - heights[y][x]);
      int new_effort = max(h, climb);
      if (new_effort < effort[dy][dx])
      {
        effort[dy][dx] = new_effort;
        pq.push({new_effort, {dx, dy}});
      }
    }
  }
  return 0;
}

int main()
{
	// vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
	vector<vector<int>> heights = {{1,10,6,7,9,10,4,9}};

  auto res = minimumEffortPath(heights);

	return(0);
}