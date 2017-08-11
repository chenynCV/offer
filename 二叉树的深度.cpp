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
    int TreeDepth(TreeNode *pRoot)
    {
        return DFS(pRoot, 0);
    }

    int DFS(TreeNode *pRoot, int height)
    {
        if (pRoot == NULL)
            return height;

        height++;

        int heightL = DFS(pRoot->left, height);
        int heightR = DFS(pRoot->right, height);

        return max(heightL, heightR);
    }
};