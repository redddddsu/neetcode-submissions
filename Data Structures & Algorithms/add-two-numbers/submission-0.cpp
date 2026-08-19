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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int total = 0;

        int first;
        int second;

        ListNode* head = nullptr;
        ListNode* result = nullptr;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            total = 0;
            if (l1 != nullptr) first = l1->val;
            else first = 0;

            if (l2 != nullptr) second = l2->val;
            else second = 0;

            int total = first + second + carry;
            if (total > 9) {
                total = total - 10;
                carry = 1;
            }
            else {
                carry = 0;
            }

            ListNode* newNode = new ListNode(total);

            if (head == nullptr) {
                head = newNode;
                result = newNode;
            } else {
                result->next = newNode;
                result = newNode;
            }
            if (l1 != nullptr) 
                l1 = l1->next;

            if (l2 != nullptr)
                l2 = l2->next;
        }
        return head;
    }
};
