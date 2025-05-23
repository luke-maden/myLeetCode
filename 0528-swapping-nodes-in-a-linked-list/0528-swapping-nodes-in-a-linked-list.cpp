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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> indices;
        ListNode* ptr = head;

        while(ptr != nullptr){
            indices.push_back(ptr);
            ptr = ptr->next;
        }

        swap(indices[k - 1]->val, indices[indices.size() - k]->val);

        return head;
    }
};