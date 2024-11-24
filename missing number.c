int missingNumber(int* nums, int numsSize) {
    int ch;
    for (int i=0; i<=numsSize; i++) {
        ch=0;
        for (int j=0; j<numsSize; j++) {
            if (i==nums[j]) {
                ch=1;
            }
        }
        if (ch==0) {
            return i;
        }
    }
    return -1;
}
