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
    bool isValidBST(TreeNode* root) {
       return func(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }

    bool func(TreeNode *root, int min, int max) {
        if (root == nullptr) {
            return true;
        }

        if (root->right != nullptr && root->val >= root->right->val) {
            return false;
        }
        if (root->left != nullptr && root->val <= root->left->val) {
            return false;
        }
        if (root->val >= max || root->val <= min) return false;

        return func(root->left, min, root->val) && func(root->right, root->val, max);

    }
};
