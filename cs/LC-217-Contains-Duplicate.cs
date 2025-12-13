public class Solution
{
    public bool ContainsDuplicate(int[] nums)
    {
        //return nums.ToHashSet().Count() != nums.Count();
        HashSet<int> seen = [];
        foreach (int n in nums)
        {
            if (seen.Contains(n))
                return true;
            seen.Add(n);
        }
        return false;
    }
}