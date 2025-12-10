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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (left == nullptr && right == nullptr)
        {
            return root;
        }

        TreeNode* temp = left;
        root->left = invertTree(right);
        root->right = invertTree(temp);
        
        return root;
    }
};
