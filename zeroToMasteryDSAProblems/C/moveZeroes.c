void moveZeroes(int* nums, int numsSize){

    
    #if 0 
    int temp = 0;
    int i =0,j =0 ;
    
    

    for (j =0; j < numsSize-1; j++)
    {
            for (i =0; i < numsSize-1; i++)
            {
      
        if(nums[i]==0)
        {
            temp = nums[i];
            nums[i]= nums[i+1];
            nums[i+1]=temp;
        }
     
    }
    }
    #endif 
    
    
 
    int wp = 0;
    int i;
    for (i = 0; i < numsSize; i++)
        if (nums[i] != 0)
            nums[wp++] = nums[i];
    
    for (wp=numsSize-wp; wp != 0; wp--)
        nums[--i] = 0;

}


