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
        int count = 0;
        int answer;
        return foo(root, k, count, answer);
    }

    int foo(TreeNode* root, int k, int &count, int& answer) {
        if (root == nullptr) {
            return 0;
        }


        int result = foo(root->left, k, count, answer);
        count++;
        if (count == k) answer = root->val;
        foo(root->right, k, count, answer);
        return answer;
        

    }
};
