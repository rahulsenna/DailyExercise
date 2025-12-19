#include <bits/stdc++.h>
using namespace std;

std::string highAndLow(const std::string &numbers)
{
  std::istringstream iss(numbers);
  std::vector<int> nums = {istream_iterator<int>(iss), {}};
  std::sort(nums.begin(), nums.end());
  return  to_string(nums.back()) + " " + to_string(nums.front());
}

int main()
{
  auto res = highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4");
  std::cout << "res: " << res << '\n';
  return (0);
}