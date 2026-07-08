class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return true;

        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        count /= 2;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while (count--) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;

        // Reverse second half
        ListNode* front = NULL;
        ListNode* rev = NULL;

        while (curr != NULL) {
            front = curr->next;
            curr->next = rev;
            rev = curr;
            curr = front;
        }

        // Compare
        ListNode* head1 = head;
        ListNode* head2 = rev;

        while (head1 != NULL && head2 != NULL) {
            if (head1->val != head2->val)
                return false;

            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};