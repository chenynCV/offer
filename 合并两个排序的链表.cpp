#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
  public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;

        if (pHead2 == NULL)
            return pHead1;

        if (pHead1->val < pHead2->val)
        {
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        }            
        else
        {
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }
    }
};

int main()
{
    vector<int> v1 = {1, 9}, v2 = {2, 4, 6, 8};
    ListNode *cur;

    ListNode *pHead1 = new ListNode(v1[0]);
    cur = pHead1;
    for (int i = 1; i < v1.size(); i++)
    {
        cur->next = new ListNode(v1[i]);
        cur = cur->next;
    }

    ListNode *pHead2 = new ListNode(v2[0]);
    cur = pHead2;
    for (int i = 1; i < v2.size(); i++)
    {
        cur->next = new ListNode(v2[i]);
        cur = cur->next;
    }

    Solution s;
    ListNode *p = s.Merge(pHead1, pHead2);

    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}