#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long taskSchedulerII(vector<int> &tasks, int space)
  {
    long long res = 0;
    std::unordered_map<int, long long> mp;

    for (long long i = 0, curr_day = 0; i < tasks.size(); ++i, ++curr_day)
    {
      if (mp.contains(tasks[i]))
      {
        int prev_day = mp[tasks[i]];
        int dist = curr_day - (prev_day + 1);
        auto d = std::max(0, space - dist);
        res += d;
        curr_day += d;
      }
      res++;
      mp[tasks[i]] = curr_day;
    }
    return res;
  }
};

int main()
{
  Solution sol;



  std::vector<int> in1 {1,2,1,2,3,1};
  std::cout << "res1: " << sol.taskSchedulerII(in1, 3) << '\n';


std::vector<int> in2 {5,8,8,5};
  std::cout << "res1: " <<  sol.taskSchedulerII(in2, 2) << '\n';
	
	return(0);
}