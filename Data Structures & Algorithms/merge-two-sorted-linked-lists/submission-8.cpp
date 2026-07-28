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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newList;
        ListNode *head;
        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;

        if (!ptr1 && !ptr2) {
            return nullptr;
        }


        if (ptr1 && ptr2) {
            if (ptr2 && ptr1->val > ptr2->val) {
                newList = ptr2;
                ptr2 = ptr2->next;
            }
            else if (ptr1) {
                newList = ptr1;
                ptr1 = ptr1->next;
            }
        } 
        else if (!ptr1) {
            newList = ptr2; 
            ptr2 = ptr2->next;
        }
        else if (!ptr2) {
            newList = ptr1;
            ptr1 = ptr1->next;
        }

        head = newList;

        while (ptr1 && ptr2) {
            if (ptr1->val > ptr2->val) {
                newList->next = ptr2;
                ptr2 = ptr2->next;
            }
            else {
                newList->next = ptr1;
                ptr1 = ptr1->next;
            }
            newList = newList->next;
        }

        while (ptr1) {
            newList->next = ptr1;
            ptr1 = ptr1->next;
            newList = newList->next;
        }

        
        while (ptr2) {
            newList->next = ptr2;
            ptr2 = ptr2->next;
            newList = newList->next;
        }
        return head;
    }
};
