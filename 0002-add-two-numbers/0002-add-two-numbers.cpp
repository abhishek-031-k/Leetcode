class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* x = l1;
        ListNode* y = l2;
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;
        int store = 0;
        while (x != NULL || y != NULL) {
            int sum = store;
            if(x)sum += x->val;
            if(y)sum += y->val;
            ListNode* node = new ListNode(sum % 10);
            store = sum / 10;
            curr->next = node;
            curr = curr->next;
            if(x)x = x->next;
            if(y)y = y->next;
        }
        if(store){
            ListNode* newNode = new ListNode(1);
            curr->next = newNode;
        }
        return ans->next;
    }
};