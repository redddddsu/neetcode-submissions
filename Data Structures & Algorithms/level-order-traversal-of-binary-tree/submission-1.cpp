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

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> result;

        if (root == nullptr) return result;

        while (!q.empty()) {
            vector<int> section;
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode *top = q.front();
                q.pop();
                section.push_back(top->val);

                if (top->left != nullptr) q.push(top->left);
                if (top->right != nullptr) q.push(top->right);
            }

            result.push_back(section);


        }

        return result;
        
    }
};
