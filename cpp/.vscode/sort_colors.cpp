#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int b = 0, m = 0, e = nums.size() - 1;

        while(b<e)
        {
            if (nums[m] == 0)
                swap(nums[b++], nums[m++]);
            
            else if (nums[m] == 1)
                m++;
            else
                swap(nums[e--], nums[m++]);
        }
    }
};

int main()
{

    Solution sol;
    std::vector<int> input {0,0,1,0,1,1};
    sol.sortColors(input);
	
	return(0);

}