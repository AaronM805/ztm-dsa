#include <limits.h>
int maxSubArray(int* nums, int size)
{
    int total = 0;
    int max = INT_MIN;
    for(int i = 0; i < size; i++)
    {
        if(total >= 0)
            total += nums[i];
        else
            total = nums[i];
        if(total > max)
            max = sum;
    }
    return max;
}
