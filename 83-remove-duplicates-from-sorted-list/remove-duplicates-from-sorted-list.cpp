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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* curr = head->next;
        ListNode * prev  = head;
        while(curr!=NULL){
            if(curr->val ==prev->val){
                prev->next  = curr->next;
                delete curr;
                curr = prev->next;
            }
            else{
                prev = prev->next;
                curr = curr->next;
            }
        }

       return head;
    }
};