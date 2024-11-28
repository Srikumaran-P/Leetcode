/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* temp = (int*)malloc((numsSize+2)*sizeof(int));
    *returnSize = numsSize+1;
    for(int i = 0; i<=numsSize+1; i++){
        temp[i] = i;
    }

    for(int i = 0; i<numsSize; i++){
        temp[nums[i]] = 0;
    }

    int* ans = (int*)malloc((numsSize+2)*sizeof(int));
    *returnSize = numsSize;
    int a = 0;
    for(int j = 0; j<numsSize+1; j++){
        if(temp[j] != 0){
            ans[a] = temp[j];
            a++;
        }
    }

    *returnSize = a;
    return ans;
    free(ans);
    free(temp);
}
