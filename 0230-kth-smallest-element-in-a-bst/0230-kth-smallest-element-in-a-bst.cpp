class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while(temp != NULL || !st.empty()) {
            while(temp != NULL) {
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            k--;
            if(k == 0) return temp->val;
            temp = temp->right;
        }
        return -1;
    }
};