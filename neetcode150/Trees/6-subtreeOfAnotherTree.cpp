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

    bool same(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) return true;
        if (a == nullptr || b == nullptr) return false;

        if (a->val != b->val) return false;

        return same(a->left, b->left) && same(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true;
        if (root == nullptr && subRoot != nullptr) return false;

        TreeNode* rootLeft = root->left;
        TreeNode* rootRight = root->right;

        TreeNode* subRootLeft = subRoot->left;
        TreeNode* subRootRight = subRoot->right;

        // cout << "root->val = " << root->val << "; subRoot->val = " << subRoot->val << "\n";
        bool isSubTree = false;
        if (root->val == subRoot->val && same(root, subRoot))
        {
            return true;
        }

        // else if root values not equal
        return isSubtree(rootLeft, subRoot) || isSubtree(rootRight, subRoot);
        
    }
};
