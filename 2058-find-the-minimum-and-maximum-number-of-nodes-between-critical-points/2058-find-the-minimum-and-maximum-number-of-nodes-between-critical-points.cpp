class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       vector<int>v;
       if(head == NULL || head->next == NULL)return {-1, -1};
       ListNode* t1 = head;
       ListNode* t2 = head->next; 
       int i = 0;
       while(t2->next != NULL){
         if((t2->val > t2->next->val && t2->val > t1->val) ||
         (t2->val < t2->next->val && t2->val < t1->val))v.push_back(i);
         i++;
         t1 = t1->next;
         t2 = t2->next;
       }
       if(v.size() < 2) return {-1, -1};
        int mini = INT_MAX;
        for(int j = 1; j < v.size(); j++) {
            mini = min(mini, v[j] - v[j-1]);
        }
        int maxi = v[v.size()-1] - v[0];
        return {mini, maxi};

    }
};