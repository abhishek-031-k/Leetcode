class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode* evenhead = head->next;
        ListNode* odd = head;
        ListNode* even = evenhead;
        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};