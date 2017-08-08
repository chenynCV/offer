//  g++ 链表中环的入口结点.cpp -o test -std=c++11; ./test
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
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
        {
            return NULL;
        }

        ListNode *entry = MeetNodeOfLoop(pHead);
        if (entry == NULL)
            return NULL;
            
        cout << entry->val << endl;

        ListNode *now = pHead;
        while (entry->val != now->val)
        {
            entry = entry->next;
            now = now->next;
        }

        return entry;
    }

    ListNode *MeetNodeOfLoop(ListNode *pHead)
    {
        if (pHead == NULL || pHead->next == NULL || pHead->next->next == NULL)
            return NULL;

        ListNode *pre = pHead->next->next, *now = pHead->next;

        while (pre->val != now->val)
        {
            if (pre->next == NULL || pre->next->next == NULL)
                return NULL;
            pre = pre->next->next;
            now = now->next;
        }

        return pre;
    }
};

int main()
{
    int v[5] = {1, 2, 3, 4, 5};
    ListNode *pHead = new ListNode(v[0]);
    ListNode *now = pHead;
    for (int i = 1; i < 5; i++)
    {
        ListNode *next = new ListNode(v[i]);
        now->next = next;
        now = next;
    }
    now->next = pHead->next->next;

    Solution s;
    ListNode *entry = s.EntryNodeOfLoop(pHead);
    cout << entry->val << endl;

    return 0;
}