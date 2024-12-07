/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *prev;
int min;
void Inorder(struct TreeNode* root)
{
    if(root==NULL) return;
    Inorder(root->left);
    if(prev !=NULL)
    {
        int diff = root->val - prev->val;
        if(diff < min)
        {
            min = diff;
        }
    }
    prev = root;
    Inorder(root->right);

}
int getMinimumDifference(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    min = INT_MAX;
    prev = NULL;
    Inorder(root);
    
    return min;
}
