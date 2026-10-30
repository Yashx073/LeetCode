/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorder(struct TreeNode* root, int* ans, int* count){
    if(root != NULL){
        inorder(root->left, ans, count);
        ans[*count] = root->val;
        (*count)++;
        inorder(root->right, ans, count);
    }
}

int count(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + count(root->left) + count(root->right);
    }
}

int kthSmallest(struct TreeNode* root, int k) {
    int n = count(root);
    int cout = 0;
    int* ans = (int *)malloc(n * sizeof(int));
    inorder(root, ans, &cout);
    return ans[k-1];
}