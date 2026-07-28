/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_map<int, int> cycle;

        ListNode *temp = head;
        while (temp) {
            cycle[temp->val]++;
            if (cycle[temp->val] > 2) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
