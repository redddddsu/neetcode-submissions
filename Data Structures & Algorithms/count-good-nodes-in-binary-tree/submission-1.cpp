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
         if (root == nullptr) {
            return 0;
        }
    
        int result = 0;
        int most = 0;
        queue<TreeNode*> q;
        queue<int> maxQ;
        maxQ.push(root->val);
        q.push(root);

        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode *top = q.front();
                int most = maxQ.front();
                q.pop();
                maxQ.pop();

                if (top->val >= most) {
                    result++;
                }

                int newMost = max(most, top->val);

                if (top->left != nullptr) {
                    q.push(top->left);
                    maxQ.push(newMost);
                }
                if (top->right != nullptr) {
                    q.push(top->right);
                    maxQ.push(newMost);
                }
            }
        }

        return result;
    }
};
