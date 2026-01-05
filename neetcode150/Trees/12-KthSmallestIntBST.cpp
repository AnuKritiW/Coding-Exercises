/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vals;
        dfs(root, vals);
        return vals[k-1];
        
    }

    void dfs(TreeNode* root, vector<int>& vals) {
        if (root == nullptr) return;
        dfs(root->left, vals);
        vals.push_back(root->val);
        dfs(root->right, vals);
    }
};
