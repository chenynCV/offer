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
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == NULL || pHead2 == NULL)
            return NULL;

        int l1 = 0, l2 = 0;

        ListNode *node;

        node = pHead1;
        while (node->next != NULL)
        {
            node = node->next;
            l1++;
        }

        node = pHead2;
        while (node->next != NULL)
        {
            node = node->next;
            l2++;
        }

        ListNode *p1 = pHead1, *p2 = pHead2;
        if (l1 > l2)
        {
            int diff = l1 - l2;
            for (int i = 0; i < diff; i++)
                p1 = p1->next;
        }
        else
        {
            int diff = l2 - l1;
            for (int i = 0; i < diff; i++)
                p2 = p2->next;
        }

        while (p1 != NULL && p2 != NULL && p1->val != p2->val)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};