struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL)
    {
    }
};

class Solution
{
  public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (pHead == NULL)
            return NULL;

        for (RandomListNode *now = phead; now != NULL; now = now->next)
        {
            RandomListNode *head = new RandomListNode(pHead->label);
            head->next = phead->next;
            phead->next = head;
        }
    }
};