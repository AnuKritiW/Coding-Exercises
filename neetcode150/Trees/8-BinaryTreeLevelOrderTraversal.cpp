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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int currDepth = 0;
        vector<vector<int>> result;
        levelOrder(root, result, currDepth);
        return result;
    }

    void appendAt(vector<vector<int>>& result, size_t currDepth, int val) {
        if (currDepth >= result.size()) result.resize(currDepth + 1);  // create empty rows up to idx
        result[currDepth].push_back(val);                              // append to that row
    }

    void levelOrder(TreeNode* root, vector<vector<int>>& result, int currDepth)
    {
        if (root == nullptr) return;

        appendAt(result, currDepth, root->val);

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (left != nullptr)
        {
            levelOrder(left, result, currDepth + 1);
        }
        if (right != nullptr)
        {
            levelOrder(right, result, currDepth + 1);
        }
    }
};
