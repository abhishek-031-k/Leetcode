class Solution {
public:

   void solve(TreeNode* root, int& sum){
    if(root == NULL)return;
      solve(root->right, sum);
      int x = root->val;
      root->val += sum;
      sum += x;
       solve(root->left, sum);
    
   }


    TreeNode* bstToGst(TreeNode* root) {
      TreeNode* temp = root;
      int sum = 0;
      solve(temp, sum);
     return root;
    }
};