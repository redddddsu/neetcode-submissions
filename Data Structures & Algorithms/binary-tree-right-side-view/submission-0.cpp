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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
    
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode *top = q.front();
                 if (i == q_size - 1) {
                    result.push_back(top->val);
                }
                q.pop();

                if (top->left != nullptr) q.push(top->left);
                if (top->right != nullptr) q.push(top->right);
            }
        }

        return result;


    }

  
};
