#include <queue>
#include <vector>

using namespace std;

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
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> p;

        if (root != NULL)
        {
            q.push(root);
        }

        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            p.push_back(front->val);

            if (front->left != NULL)
            {
                q.push(front->left);
            }

            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }

        return p;
    }
};