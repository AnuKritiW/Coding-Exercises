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
    void maxDepthHelper(TreeNode* root, int currDepth, int& maxDepthVal)
    {
        maxDepthVal = max(currDepth, maxDepthVal);

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (left != nullptr)
        {
            maxDepthHelper(left, currDepth + 1, maxDepthVal);
        }
        if (right != nullptr)
        {
            maxDepthHelper(right, currDepth + 1, maxDepthVal);
        }
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int maxDepthVal = 1;
        int currDepth = 1;
        maxDepthHelper(root, currDepth, maxDepthVal);
        return maxDepthVal;
    }
};
