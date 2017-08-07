class Solution
{
  public:
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return true;

        int heightL = DFS(pRoot->left, 0);
        int heightR = DFS(pRoot->right, 0);

        return abs(heightL - heightR) < 2;
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