/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void preorder(struct TreeNode* root, int* ans, int* count){
    if(root != NULL){
        ans[*count] = root->val;
        (*count)++;
        preorder(root->left, ans, count);
        preorder(root->right, ans, count);
    }
}

int countNode(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + countNode(root->left) + countNode(root->right);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int count = 0;
    int size = countNode(root);
    int* ans = (int *)malloc(size * sizeof(int));

    preorder(root, ans, &count);
    *returnSize = size;
    return ans;
}