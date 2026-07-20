/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int solve(TreeNode* root,int &cnt){

if(root==NULL)return 0;

int leftv=solve(root->left,cnt);
int rightv=solve(root->right,cnt);

if(root->val>=leftv && root->val>=rightv)cnt++;

return max(root->val,max(leftv,rightv));



}

    int countDominantNodes(TreeNode* root) {
        
   int cnt=0;

   solve(root,cnt);
   return cnt;


    }
};