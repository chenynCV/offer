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

        for (RandomListNode *now = pHead; now != NULL;)
        {
            RandomListNode *node = new RandomListNode(now->label);
            node->next = now->next;
            now->next = node;

            now = node->next;
        }

        for (RandomListNode *now = pHead; now != NULL;)
        {
            RandomListNode *node = now->next;

            if (now->random == NULL)
                node->random = NULL;
            else
                node->random = now->random->next;

            now = now->next->next;
        }

        RandomListNode *pHeadClone = pHead->next;
        for (RandomListNode *now = pHead; now != NULL;)
        {
            RandomListNode *node = now->next;
            now->next = node->next;
            if (node->next == NULL)
                node->next = NULL;
            else
                node->next = node->next->next;

            now = now->next;
        }

        return pHeadClone;
    }
};