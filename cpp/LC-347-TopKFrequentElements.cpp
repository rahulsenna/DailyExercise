#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    std::unordered_map<int, int> freq;
    for (auto n: nums)
    	freq[n]++;

    std::vector<std::pair<int, int>> freq_list{freq.begin(), freq.end()};
    std::ranges::sort(freq_list, [](auto a, auto b) { return b.second < a.second; });

    std::vector<int> res;
    for (int i = 0; i < k; ++i)
        res.emplace_back(freq_list[i].first);
    
    return res;
}

int main()
{
    std::vector<int> input {1,1,1,2,2,3};
    auto res = topKFrequent(input, 2);
    for (auto n: res)
    	std::cout << n << ' ';
    std::cout << '\n';
    
	return(0);

}
