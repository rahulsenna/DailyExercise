#include <vector>
std::vector<int> shortestArrang(const int &n)
{
    int start = n / 2;
    if ((n & 1) != 0)
        start = (n+1)/2;

    while (start > 0)
    {
        int sum = 0;
        for (int i = start; i > 0; --i)
        {
        	 sum +=i;
             if (sum == n)
             {
                std::vector<int> res;
                for (int j = start; j >= i; --j)
                    res.push_back((j));
                return res;  
             }
        }
        start--;
    }

    std::vector<int> res {-1};
    return res;
}