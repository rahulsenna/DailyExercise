#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    std::string reorganizeString(std::string s)
    {
        std::unordered_map<char, int> map;
        for (auto c : s)
            map[c]++;
        int n = map.size();
        std::priority_queue<std::pair<int, char>> pq;
        for (auto &[k, v] : map)
            pq.push({v, k});

        std::stringstream ss;

        while (pq.size() >= 2)
        {
            auto [a_freq, a_chr] = pq.top();
            pq.pop();
            auto [b_freq, b_chr] = pq.top();
            pq.pop();

            ss << a_chr << b_chr;
            if (a_freq > 1)
                pq.push({a_freq - 1, a_chr});
            if (b_freq > 1)
                pq.push({b_freq - 1, b_chr});
        }
        if (!pq.empty())
        {
            auto &[a_freq, a_chr] = pq.top();
            if (a_freq != 1)
                return "";
            ss << a_chr;
        }
        return ss.str();
    }
};

int main()
{
	Solution sol;
    auto res = sol.reorganizeString("aab");
	return(0);
}