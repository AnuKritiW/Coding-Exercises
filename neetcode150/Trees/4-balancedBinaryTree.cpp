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
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        getHeight(root, isBalanced);
        return isBalanced;
    }

    int getHeight(TreeNode* root, bool& isBalanced)
    {
        if (!isBalanced) return 0;
        if (root == nullptr) return 0;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (left == nullptr && right == nullptr) return 0;

        int leftHeight = 0;
        int rightHeight = 0;
        
        if (left != nullptr)
        {
            leftHeight = 1 + getHeight(left, isBalanced);
        }
        if (right != nullptr)
        {
            rightHeight = 1 + getHeight(right, isBalanced);
        }
        
        if (leftHeight < rightHeight - 1 ||
            leftHeight > rightHeight + 1)
        {
            isBalanced = false;
        }

        return max(leftHeight, rightHeight);
    }
};
