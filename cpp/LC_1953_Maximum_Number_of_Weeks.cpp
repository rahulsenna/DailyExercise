#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long numberOfWeeks(vector<int> &milestones)
  {
    long long m = *max_element(milestones.begin(), milestones.end());
    auto sum = accumulate(milestones.begin(), milestones.end(), 0LL) - m;
    return (m > sum) ? sum * 2LL + 1LL : sum + m;
  }
};

int main()
{
  Solution sol;
  std::vector<int> input5{1, 10, 7, 1, 7, 2, 10, 10, 355359359};
  auto res5 = sol.numberOfWeeks(input5);
  std::cout << "res5: " << res5 << '\n';

  std::vector<int> input4{4, 5, 5, 2};
  auto res4 = sol.numberOfWeeks(input4);
  std::cout << "res4: " << res4 << '\n';

  std::vector<int> input{1, 2, 3};
  auto res = sol.numberOfWeeks(input);
  std::cout << "res: " << res << '\n';
  std::vector<int> input2{5, 2, 1};
  auto res2 = sol.numberOfWeeks(input2);
  std::cout << "res2: " << res2 << '\n';
  std::vector<int> input3{5, 7, 5, 7, 9, 7};
  auto res3 = sol.numberOfWeeks(input3);
  std::cout << "res3: " << res3 << '\n';

  return (0);
}