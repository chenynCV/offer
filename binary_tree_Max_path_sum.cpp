#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    int maxPathSum(TreeNode *root)
    {
        int sum = -1e8;
        maxSubPathSum(root, sum);
        return sum;
    }

  private:
    int maxSubPathSum(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return 0;

        int l = maxSubPathSum(root->left, sum);
        int r = maxSubPathSum(root->right, sum);

        int v = root->val;
        if (l > 0)
            v += l;
        if (r > 0)
            v += r;

        sum = max(sum, v);

        return root->val + max(0, max(l, r));
    }
};
