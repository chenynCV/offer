#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (root == NULL)
            return res;
        DFS(root, to_string(root->val), res);
        return res;
    }

  private:
    void DFS(TreeNode *root, string s, vector<string> &res)
    {
        if (root->left == NULL && root->right == NULL)
        {
            res.push_back(s);
            return;
        }

        if (root->left != NULL)
            DFS(root->left, s + "->" + to_string(root->left->val), res);
        if (root->right != NULL)
            DFS(root->right, s + "->" + to_string(root->right->val), res);

        return;
    }
};