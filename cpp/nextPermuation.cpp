#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        auto it = adjacent_find(nums.rbegin(), nums.rend(), std::greater<int>());
        if (it != nums.rend())
        {
            auto pivot = std::next(it);
            auto successor = std::upper_bound(nums.rbegin(), it, *pivot);
            if (successor != nums.rend())
            {
                std::swap(*pivot, *successor);
                std::reverse(nums.rbegin(), pivot);
                return;
            }
        }
        std::reverse(nums.begin(), nums.end());
    }
};


int main()
{
    Solution sol;
    std::vector<int> inp {1,3,2};
    sol.nextPermutation(inp);
	return(0);

}