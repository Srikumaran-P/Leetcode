int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result=(int*) malloc(nums1Size* sizeof(int));
    *returnSize=nums1Size;
    for(int i=0;i<nums1Size;i++){
        int c=0;
        int r=-1;
        for(int j=0;j<nums2Size;j++){
            if(nums2[j]==nums1[i]){
            c=1;
            }
            if(c && nums2[j]>nums1[i]){
                r=nums2[j];
                break;
            }
        }
    result[i]=r;
}
return result;
}
