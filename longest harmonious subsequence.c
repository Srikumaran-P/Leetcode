int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int findLHS(int* nums, int numsSize) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int l = 0, r = 0, maxLength = 0;
    while (r < numsSize) {
        // count if the difference is 1
        if ((nums[r] - nums[l]) == 1) {
            maxLength = (maxLength > (r - l + 1)) ? maxLength : (r - l + 1);
        }
        // Adjust the window size
        if ((nums[r] - nums[l]) > 1) {
            l++;
        }
        if ((nums[r] - nums[l]) <= 1) {
            r++;
        }
    }
    
    return maxLength;
}
