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
   ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0, head);

    ListNode* first = &dummy;
    ListNode* second = &dummy;

    // Move first n+1 positions ahead
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }

    // Move both pointers
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // second is now before the node to delete
    ListNode* temp = second->next;
    second->next = temp->next;
    delete temp;

    return dummy.next;
}
};
