/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Medium (53.17%)
 * Likes:    23523
 * Dislikes: 517
 * Total Accepted:    3.5M
 * Total Submissions: 6.7M
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security systems
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 * 
 * 
 */

// @lc code=start
class Solution {
public:
int rob(vector<int> &nums)
{
  int N = nums.size();
  if (N == 0) return 0;
  if (N == 1) return nums[0];

  std::vector<int> pref(nums.size(), 0);
  pref[0] = nums[0];
  pref[1] = std::max(nums[0], nums[1]);
  for (int i = 2; i < N; ++i)
    pref[i] = std::max(pref[i - 2] + nums[i], pref[i - 1]);
  return pref.back();
}
};
// @lc code=end

