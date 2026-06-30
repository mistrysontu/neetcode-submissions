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
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* tailNext = tail->next;

        ListNode* prev = tailNext;
        ListNode* next = head;
        ListNode* curr = head;
        while(curr != tailNext) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *curr = dummy, *tail = dummy;

        while(true) {
            tail = curr;
            for(int i = 0; i < k; i++) {
                tail = tail->next;
                if(tail == nullptr) {
                    return dummy->next;
                }
            }

            ListNode* groupHead = curr->next;
            curr->next = reverse(groupHead, tail);

            curr = groupHead;
        }
        return dummy->next;
    }
};
