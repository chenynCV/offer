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
    bool isSymmetrical(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return true;

        return compare(pRoot->left, pRoot->right);
    }

    bool compare(TreeNode *pLeft, TreeNode *pRight)
    {
        if (pLeft == NULL && pRight == NULL)
            return true;

        if (pLeft == NULL && pRight != NULL)
            return false;

        if (pLeft != NULL && pRight == NULL)
            return false;

        if (pLeft->val != pRight->val)
            return false;

        return compare(pLeft->left, pRight->right) && compare(pLeft->right, pRight->left);
    }
};