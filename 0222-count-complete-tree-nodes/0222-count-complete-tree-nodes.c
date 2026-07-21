/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNode(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + countNode(root->left) + countNode(root->right);
    }
}

int countNodes(struct TreeNode* root) {
    return countNode(root);
}