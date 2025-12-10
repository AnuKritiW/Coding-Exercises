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
    int goodNodes(TreeNode* root) {
        int maxOccurredInTraversal = root->val;
        int numGoodNodes = 0;

        goodNodesHelper(root, maxOccurredInTraversal, numGoodNodes);
        return numGoodNodes;
    }

    void goodNodesHelper(TreeNode* root, int maxOccurredInTraversal, int& numGoodNodes)
    {
        if (root == nullptr) return;

        if (root->val >= maxOccurredInTraversal) numGoodNodes++;

        TreeNode* left = root->left;
        if (left != nullptr)
        {
            int maxOccurredInTraversalLeft = max(maxOccurredInTraversal, left->val);
            goodNodesHelper(left, maxOccurredInTraversalLeft, numGoodNodes);
        }

        TreeNode* right = root->right;
        if (right != nullptr)
        {
            int maxOccurredInTraversalRight = max(maxOccurredInTraversal, right->val);
            goodNodesHelper(right, maxOccurredInTraversalRight, numGoodNodes);
        }
    }
};
