class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = NULL;
        ListNode* curr = head;
        while(curr != NULL) {
            ListNode* front = curr->next;
            curr->next = temp;
            temp = curr;
            curr = front;
        }
        return temp;
    }
};