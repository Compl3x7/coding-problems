// Runtime: 80ms | Beats 27.27% of users
// Memory: 90.01MB | Beats 90.01% of users
// Time complexity: O(n)
// Spacial complexity O(1)

int max(int n, int m)
{
    return n > m ? n : m;
}

int maxSubArray(int* nums, int numsSize) 
{
    int c_sum = nums[0];
    int max_c_sum = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        c_sum = max(c_sum + nums[i], nums[i]);
        max_c_sum = max(c_sum, max_c_sum);
    }
    return max_c_sum;
}