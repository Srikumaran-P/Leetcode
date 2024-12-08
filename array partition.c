int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize) {
    int sum = 0, i = 0;
    qsort(nums, numsSize, sizeof(int), compare);

    while(i < numsSize)
    {
        sum = sum + nums[i];
        i = i + 2;
    }
    return sum;
}
