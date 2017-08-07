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
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int>> pathAll;
        vector<int> path;
        int sum = 0;
        if (root == NULL)
            return pathAll;
        else
            DFS(root, pathAll, path, sum, expectNumber);
        return pathAll;
    }

    void DFS(TreeNode *root, vector<vector<int>> &pathAll, vector<int> path, int sum, int expectNumber)
    {
        path.push_back(root->val);
        sum += root->val;

        if (root->left != NULL)
        {
            DFS(root->left, pathAll, path, sum, expectNumber);
        }

        if (root->right != NULL)
        {
            DFS(root->right, pathAll, path, sum, expectNumber);
        }

        if (root->left == NULL && root->right == NULL)
        {
            if (sum == expectNumber)
                pathAll.push_back(path);
        }

        return;
    }
};