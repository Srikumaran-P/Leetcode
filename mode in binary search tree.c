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


//First Pass (Count Maximum Frequency): Traverse the BST in-order and find the maximum frequency of any value. This pass only counts the frequency and does not store any values.
//First Pass: findMaxFrequency traverses the tree and finds that the maximum frequency (maxCount) is 2 (for value ‘2’).
void findMaxFrequency(struct TreeNode* root,int* maxCount,int *prevVal,int*  currentCount)
{
    if(root == NULL) return;
    findMaxFrequency( root->left, maxCount,prevVal,currentCount);

    if(*prevVal == root->val)
    {
        (*currentCount)++;
    }
    else {
        *prevVal = root->val;
        *currentCount = 1;        
    }

    if(*currentCount > *maxCount)
    {
        *maxCount = *currentCount;
    }
    findMaxFrequency(root->right, maxCount,prevVal,currentCount);
}


//Second Pass (Collect Modes): Traverse the BST in-order again. This time, compare each value’s frequency with the maximum frequency found in the first pass. If they match, store the value in a pre-allocated array.
//Second Pass: collectModes traverses the tree again. This time, it collects values that have a frequency equal to maxCount. It finds ‘2’ two times and adds it to the modes array.
void collectModes(struct TreeNode* root,int* modes,int* modeIndex,int maxCount,int *prevVal,int*  currentCount)
{
    if(root == NULL) return;

    collectModes(root->left, modes, modeIndex, maxCount, prevVal, currentCount);

    if(*prevVal == root->val) {
        (*currentCount)++;
    }
    else {
        *prevVal = root->val;
        *currentCount = 1;       
    }

    if(*currentCount == maxCount)
    {
        modes[(*modeIndex)++] = root->val;
    }
    collectModes(root->right, modes, modeIndex, maxCount, prevVal, currentCount);

}

// Helper function to count the number of modes
int countModes(struct TreeNode* root, int maxCount, int *prevVal, int* currentCount) {
    if (root == NULL) return 0;

    int leftModes = countModes(root->left, maxCount, prevVal, currentCount);

    if (*prevVal == root->val) {
        (*currentCount)++;
    } else {
        *prevVal = root->val;
        *currentCount = 1;
    }

    int totalModes = leftModes + ((*currentCount == maxCount) ? 1 : 0);

    return totalModes + countModes(root->right, maxCount, prevVal, currentCount);
}


int* findMode(struct TreeNode* root, int* returnSize) {

    int maxCount= 0;
    int prevVal = INT_MIN;
    // Use INT_MIN to handle the smallest integer value in the tree
    int currentCount = 0;

    // First pass to find the maximum frequency
    findMaxFrequency(root, &maxCount, &prevVal, &currentCount);

    // Reset variables for counting modes
    prevVal = INT_MIN;
    currentCount = 0; 
    
    // Additional pass to count the number of modes
    int modeCount = countModes(root, maxCount, &prevVal, &currentCount);

    // Allocate array to store modes (maximum size needed is maxCount)
    int* modes = malloc(modeCount* sizeof(int));
    
    int modeIndex =0;

    // Check if malloc was successful
    if (!modes) {
        *returnSize = 0;
        return NULL;
    }


    // Reset variables for second pass
    prevVal = INT_MIN;
    currentCount = 0;
    modeIndex = 0;

    // Second pass to collect modes
    collectModes(root, modes, &modeIndex, maxCount, &prevVal, &currentCount);
    
    *returnSize = modeIndex;
    
    return modes;

}
