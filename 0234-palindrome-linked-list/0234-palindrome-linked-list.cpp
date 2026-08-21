class Solution {
public:

   ListNode* reverse(ListNode* head){
       ListNode* temp = head;
       ListNode* prev = NULL;
       while(temp != NULL){
          ListNode* front = temp->next;
          temp->next = prev;
          prev = temp;
          temp = front;
       }
       return prev;
   }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead = reverse(slow->next);
        slow = head, fast = newhead;
        bool flag = true;
        while(fast != NULL){
            if(fast->val != slow->val){
                flag = false;
                break;
            }
            slow = slow->next;
            fast = fast->next;
        }
       reverse(newhead);
       return flag;
    }
};