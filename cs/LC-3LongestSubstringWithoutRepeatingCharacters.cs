Console.WriteLine("Hello, Sailor"); 

Solution sol = new Solution();
// sol.LengthOfLongestSubstring("jbpnbwwd");
sol.LengthOfLongestSubstring("abcabcbb");

/* public class Solution {
    public int LengthOfLongestSubstring(string s) {
        HashSet<char> sub = [];
        Dictionary<char, int> pos = [];
        int last_cut = 0;
        int res = 0;
        for(int i=0; i< s.Count(); ++i)
        {
            if (sub.Contains(s[i]))
            {
                res = int.Max(res, sub.Count());
                // sub.Clear();
                // i = pos[s[i]]+1;

                for (int j = last_cut; j <= pos[s[i]]; ++j)
                {
                	sub.Remove(s[j]);
                }
                last_cut = pos[s[i]]+1;
            }
            sub.Add(s[i]);
            pos[s[i]] = i;
        }

        return int.Max(res, sub.Count());
    }
} */

public class Solution
{
    public int LengthOfLongestSubstring(string s)
    {
        var d = new Dictionary<int,int>();
        d.DefaultIfEmpty(i) 
        // Span<bool> chars = stackalloc bool[256];
        BitArray chars = new BitArray(256);
        int res = 0;
        int l = 0;
        for (int r = 0; r < s.Length; ++r)
        {
            while (chars[s[r]])
                chars[s[l++]] = false;
            res = int.Max(res, r + 1 - l);
            chars[s[r]] = true;
        }
        return res;
    }
}
