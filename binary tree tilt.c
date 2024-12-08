/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int tilt;

static void sum_children(struct TreeNode* n){
    int v = 0;
    int x = 0;
    if(n->left){ 
        sum_children(n->left);
        v += n->left->val;
        x += n->left->val;
    }
    if(n->right){
        sum_children(n->right);
        v -= n->right->val;
        x += n->right->val;
    } 
    v = v < 0 ? -1*v : v; //abs

    tilt += v;
    n->val += x;
    return;
}

static int findTilt(struct TreeNode* root) {
    if(!root) return 0;
    tilt = 0;
    sum_children(root);
    return tilt;
}
