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

void inorder(struct TreeNode* root, int* ans, int* count){
    if(root != NULL){
        inorder(root->left, ans, count);
        ans[*count] = root->val;
        (*count)++;
        inorder(root->right, ans, count);
    }
}

int countNode(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNode(root->left) + countNode(root->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNode(root);
    int* ans = (int *)malloc((*returnSize) * sizeof(int));
    int count = 0;
    inorder(root, ans, &count);
    return ans;
}