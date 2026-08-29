class Solution {
public:

    int pathsum(TreeNode* root, int &maxi){
        if(root == NULL)return 0;
        int leftsum = max(pathsum(root->left, maxi), 0);
        int rightsum = max(pathsum(root->right, maxi), 0);

        maxi = max(maxi, root->val + leftsum + rightsum);
        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    int z = pathsum(root, maxi);
    return maxi;
    }
};