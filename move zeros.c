void moveZeroes(int* nums, int numsSize) {
    int c=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=0){
            int t=nums[i];
            nums[i] = nums[c];
            nums[c]=t;
            c++;
        }
    }
}
