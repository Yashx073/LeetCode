/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count(struct TreeNode* root){
    struct TreeNode* temp = root;
    if(temp == NULL){
        return 0;
    }
    return 1 + count(temp->left) + count(temp->right);
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    
    struct TreeNode* temp = root;
    int n = log(count(temp));

    while(temp != NULL){
        if(temp->val == val){
            return temp;
        }
        else if(temp->val > val){
            temp = temp->left;
        }
        else if(temp->val < val){
            temp = temp->right;
        }
    }

    return NULL;

}