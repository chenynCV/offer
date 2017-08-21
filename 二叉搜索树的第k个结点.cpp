#include <bits/stdc++.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
  public:
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        if (pRoot == NULL || k <= 0)
            return NULL;

        vector<TreeNode *> v;
        DFSVisit(pRoot, v);

        if (v.size() < k)
            return NULL;

        return v[k - 1];
    }

    void DFSVisit(TreeNode *p, vector<TreeNode *> &v)
    {
        if (p == NULL)
            return;

        if (p->left != NULL)
        {
            DFSVisit(p->left, v);
        }
        v.push_back(p);
        if (p->right != NULL)
        {
            DFSVisit(p->right, v);
        }

        return;
    }
};