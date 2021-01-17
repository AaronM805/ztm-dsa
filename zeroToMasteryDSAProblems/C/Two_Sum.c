int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
int *returnVal = (int*)malloc((sizeof(int))*2); //Assign 2 int space
    *returnSize = 2; //Return size
    
    /*Start to scan*/
    for(int i = 0; i < numsSize; i++)
	{
        for(int j = i+1; j < numsSize; j++ )
		{
            if(target==nums[i]+nums[j]){  //if get an answer, return
                returnVal[0]= i;
                returnVal[1]= j;
                return returnVal;
            }
        }
    }
    return returnVal;
}