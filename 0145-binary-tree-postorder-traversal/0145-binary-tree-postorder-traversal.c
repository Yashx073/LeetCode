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
void postorder(struct TreeNode* root, int* ans, int* count){
    if(root != NULL){
        postorder(root->left, ans, count);
        postorder(root->right, ans, count);
        ans[*count] = root->val;
        (*count)++;
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

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNode(root);
    int count = 0;
    int* ans = (int *)malloc(*returnSize * sizeof(int));
    postorder(root, ans, &count);
    return ans;
}