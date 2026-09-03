
class Solution {
public:

    TreeNode* findright(TreeNode* root){
        if(root->right == NULL)return root;
       return  findright(root->right);
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL)return root->right;
        if(root->right == NULL)return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastright = findright(root->left);
        lastright->right = rightChild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return NULL;
        if(root->val == key)return helper(root);

        TreeNode* temp = root;
        while(temp != NULL){
            if(temp->val > key){
                if(temp->left != NULL && temp->left->val == key){
                    temp->left = helper(temp->left);
                    break;
                }
                else temp = temp->left;
            }
            else{
                if(temp->right != NULL && temp->right->val == key){
                    temp->right = helper(temp->right);
                    break;
                }
                else temp = temp->right;
            }
        }
        return root;
    }
};