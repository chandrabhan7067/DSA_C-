    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if(root != NULL && root->left == NULL && root->right == NULL && targetSum - root->val == 0){
    //         return true;
    //     }
    //     if(root == NULL){
    //         return false;
    //     }
        
    //     return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    // }