class Solution {
public:

    void solve(TreeNode* root, vector<int>&path, vector<vector<int>>&ans, int targetSum){
        if(root == NULL)return;
        path.push_back(root->val);
       if(root->val == targetSum && root->left == NULL && root->right == NULL)ans.push_back(path);
        solve(root->left, path, ans, targetSum - root->val);
         solve(root->right, path, ans, targetSum - root->val);
       
      path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       TreeNode* temp = root;
       vector<vector<int>>ans;
      vector<int>path;
      solve(temp, path, ans, targetSum);
       return ans;
    }
};