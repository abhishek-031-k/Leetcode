class Solution {
public:
    int subtree(TreeNode* root, int& count, int& nodes) {
        if (root == NULL)return 0;

        int leftNodes = 0, rightNodes = 0;
        int leftSum = subtree(root->left, count, leftNodes);
        int rightSum = subtree(root->right, count, rightNodes);

        nodes = 1 + leftNodes + rightNodes;
        int sum = root->val + leftSum + rightSum;

        if (sum / nodes == root->val)count++;
        return sum;
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0, nodes = 0;
        subtree(root, count, nodes);
        return count;
    }
};