int findPoisonedDuration(int* nums , int numsSize, int duration) {

int count = 0;

for(int i = 0 ; i < numsSize-1 ; i++)
{
    if(nums[i]+duration-1 >= nums[i+1])
    {
        count += (nums[i+1]-nums[i]);
    }
    else
    {
        count += duration ;
    }

}


return count+(duration) ;

}
