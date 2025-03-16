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
        ListNode* ptr = head;
        ListNode* del = head;

        while(del->next != nullptr){
            del = del->next;
            if(n > 0){
                n--;
            } else {
                ptr = ptr->next;
            }
        }

        if(ptr == del){
            delete ptr;
            return nullptr;
        } else if (ptr == head && n > 0){
            del = ptr;
            ptr = ptr->next;
            delete del;
            return ptr;
        }

        del = ptr->next;
        ptr->next = del->next;

        delete del;
        return head;
    }
};