class Solution {
public:

    TreeNode* bstToGst(TreeNode* root) {
    vector<int>ans;
       stack<TreeNode*>st;
       int sum = 0;
       if(root == NULL)return root;
       TreeNode* temp = root;
       while(true){
        if(temp != NULL){
            st.push(temp);
            temp = temp->right;
        }
        else {
            if(st.empty())break;
            temp  = st.top();
           int x = temp->val;
            temp->val += sum;
                sum += x;
            st.pop();
            ans.push_back(temp->val);
            temp = temp->left;
        }
       }
       return root;
    }
};