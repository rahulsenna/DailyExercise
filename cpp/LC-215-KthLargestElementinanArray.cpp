#include <bits/stdc++.h>
using namespace std;


int findKthLargest(std::vector<int> &nums, int k)
{
    // std::sort(nums.begin(), nums.end(), greater<int>());
    // return nums[k-1];
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (auto n : nums)
    {
        pq.push(n);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

int main()
{
	std::vector<int> input{3,2,1,5,6,4};

    auto res = findKthLargest(input, 2);
    std::cout << "res: " << res << '\n';
	return(0);

}