int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count = 0, ans = 0;
    for (int i = 0; i < numsSize; i++) {
        count = (nums[i] == 0) ? 0 : count + 1;
        ans = (count > ans) ? count : ans;
    }
    return ans;
    
}
