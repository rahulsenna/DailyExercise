#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#if  0
ListNode *mergeKLists(std::vector<ListNode *> &lists)
{
    if (lists.empty())
    	return 0;
    
    std::unordered_map<ListNode*, int> nodes;
    for (auto root: lists)
    {
        if (root == nullptr)
            continue;
        
        ListNode *temp = root;
    	while(temp)
        {
            nodes[temp] = temp->val;
            temp = temp->next;
        }
    }
    if (nodes.empty())
    	return 0;
    std::vector<std::pair<ListNode*, int>> nodes_list{nodes.begin(), nodes.end()};
    std::sort(nodes_list.begin(), nodes_list.end(), [](auto a, auto b) { return a.second < b.second; });
    for (int i = 0; i < nodes_list.size()-1; ++i) 
    	nodes_list[i].first->next = nodes_list[i+1].first;
    
    nodes_list.back().first->next = 0;
    return nodes_list.front().first;
}

#endif  //0

ListNode *mergeKLists(std::vector<ListNode *> &lists)
{
    auto cmp = [](auto a, auto b) { return a->val > b->val; };
    std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmp)> pq;
    for (auto root: lists)
        if (root) pq.push(root);

    ListNode *res = pq.empty() ? 0 : pq.top();
    while(not pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        if (top->next)
            pq.push(top->next);

        top->next = pq.empty() ? 0 : pq.top();
    }
    return res;
}

int main()
{

    // lists = [[1,4,5],[1,3,4],[2,6]]
    ListNode *n1i1 = new ListNode(1);
    ListNode *n1i2 = new ListNode(2);
    ListNode *n1i3 = new ListNode(2);
    n1i1->next = n1i2;
    n1i2->next = n1i3;

    ListNode *m1i1 = new ListNode(1);
    ListNode *m1i2 = new ListNode(1);
    ListNode *m1i3 = new ListNode(2);
    m1i1->next = m1i2;
    m1i2->next = m1i3;

    ListNode *p1i1 = new ListNode(2);
    ListNode *p1i2 = new ListNode(6);
    p1i1->next = p1i2;

    // std::vector<ListNode *> lists{n1i1, m1i1, p1i1};
    std::vector<ListNode *> lists{n1i1, m1i1};

    auto res = mergeKLists(lists);
    int d = 3;

	
	return(0);

}