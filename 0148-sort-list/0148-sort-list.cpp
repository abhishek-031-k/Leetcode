class Solution {
public:

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(left != NULL && right != NULL){
            if(left->val > right->val){
                temp->next = right;
                temp = temp->next;
                right = right->next;
            }
            else {
                temp->next = left;
                temp = left;
                left = left->next;
            }
        }
        if(left)temp->next = left;
        else temp->next = right;
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
      if(head == NULL || head->next == NULL)return head;
      ListNode* middle = findMiddle(head);
      ListNode* right = middle->next;
      ListNode* left = head;        
      middle->next = NULL;
      left = sortList(left);
      right = sortList(right);
      return merge(left, right);
    }
};