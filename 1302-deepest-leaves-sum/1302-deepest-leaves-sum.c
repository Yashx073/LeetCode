/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int depth(struct TreeNode* root){

    if(root == 0){
        return 0;
    }

    struct TreeNode* temp = root;

    int left = depth(temp->left);
    int right = depth(temp->right);

    return (left > right) ? left + 1 : right + 1;
}

void sumN(struct TreeNode* root, int curr, int max, int* sum){
    if(root == NULL){
        return ;
    }

    if(curr == max){
        *sum += root->val;
    }

    sumN(root->left, curr+1, max, sum);
    sumN(root->right, curr+1, max, sum);
}

int deepestLeavesSum(struct TreeNode* root) {
    if(root == 0){
        return 0;
    }
    
    int s = 0;
    sumN(root, 1, depth(root), &s);
    return s;
    
}