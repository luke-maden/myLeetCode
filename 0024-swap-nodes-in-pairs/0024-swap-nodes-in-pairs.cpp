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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr){
            return head;
        }

        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        ListNode* ptr3;

        ptr3 = new ListNode(0, head);
        head = ptr3;

        while(ptr2){
            ptr3->next = ptr2;
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;

            ptr3 = ptr1;
            ptr1 = ptr1->next;
            if(ptr1){
                ptr2 = ptr1->next;
            } else {
                ptr2 = nullptr;
            }
        }

        return head->next;

    }
};