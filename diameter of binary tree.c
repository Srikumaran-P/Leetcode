
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b){
    if (a>=b){
        return a;
    }
    else{
        return b;
    }
}


int dfs_depth(struct TreeNode * r, int *my_diameter){
    int left_h, right_h; // this is the left and right height / depth 

    if (r==NULL){
        return -1; 
    }

    left_h=dfs_depth(r->left,my_diameter);
    right_h=dfs_depth(r->right,my_diameter);

    left_h++;
    right_h++;

    *my_diameter=max(*my_diameter,(left_h + right_h)); 

    return max(left_h,right_h);  // returns the maximum of the right and left depth which is to be 
    // used for the maximum diameter calculation 
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter; // this is the diameter

    diameter=0;

    if (root==NULL){
        return 0; 
    }

    dfs_depth(root,&diameter);

    return diameter;    
}
