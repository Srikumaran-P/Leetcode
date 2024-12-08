/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isIdentical(struct TreeNode* t1,struct TreeNode* t2){
    if(t1==NULL && t2==NULL){
    return true;
   }
   if(t1==NULL||t2==NULL){
    return false;
   }
   return isIdentical(t1->right,t2->right) && isIdentical(t1->left,t2->left) && (t1->val==t2->val);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if(subRoot==NULL){
        return true;
    }
    if(root==NULL){
        return false;
    }
    if(isIdentical(root,subRoot)){
        return true;
    }
    return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
}
