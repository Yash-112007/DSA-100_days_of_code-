#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    
    // sort array
    qsort(nums, numsSize, sizeof(int), compare);

    
    // maximum possible triplets
    int maxSize = numsSize * numsSize;

    
    // allocate memory
    int **result = (int **)malloc(maxSize * sizeof(int *));
    
    *returnColumnSizes = (int *)malloc(maxSize * sizeof(int));
    
    
    *returnSize = 0;

    
    for(int i = 0; i < numsSize - 2; i++)
    {
        
        // skip duplicate
        if(i > 0 && nums[i] == nums[i - 1])
            continue;

        
        int left = i + 1;
        
        int right = numsSize - 1;

        
        while(left < right)
        {
            
            int sum = nums[i] + nums[left] + nums[right];

            
            if(sum == 0)
            {
                
                result[*returnSize] = (int *)malloc(3 * sizeof(int));

                
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                
                (*returnColumnSizes)[*returnSize] = 3;

                
                (*returnSize)++;

                
                // skip duplicate left
                while(left < right && nums[left] == nums[left + 1])
                    left++;

                
                // skip duplicate right
                while(left < right && nums[right] == nums[right - 1])
                    right--;

                
                left++;
                right--;
            }
            
            else if(sum < 0)
            {
                left++;
            }
            
            else
            {
                right--;
            }
        }
    }

    
    return result;
}
