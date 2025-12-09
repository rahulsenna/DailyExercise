#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:

    int findSwap(vector<int> &nums, int s)
    {
        int rep = nums[s - 1];
        int swap_idx = -1;
        int swap = INT_MAX;
        for (int j = s; j < nums.size(); ++j)
        {
            if (nums[j] > rep && nums[j] < swap)
            {
                swap = nums[j];
                swap_idx = j;
            }
        }
        return swap_idx;
    }
    void nextPermutation(vector<int> &nums)
    {

        int size = nums.size() - 1;

        for (int i = size; i > 0; --i)
        {
            if (nums[i] > nums[i - 1])
            {
                int swapIdx = findSwap(nums, i);
                swap(nums[i-1], nums[swapIdx]);
                sort(nums.begin()+i, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};


int main()
{
    Solution sol;
    std::vector<int> inp {1,3,2};
    sol.nextPermutation(inp);
	return(0);

}