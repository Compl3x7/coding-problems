// Runtime: 2ms | Beats 98.55% of users
// Memory: 14.38MB | Beats 37.34% of users
// Time complexity: O(n)
// Spacial complexity O(n)

class Solution 
{
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            std::unordered_map<int, int> map;
            for (int i = 0; i < nums.size(); i++)
            {
                int complement = target - nums[i];
                if (map.contains(complement))
                {
                    int j = map[complement];
                    return {i, j};
                }
                else
                    map[nums[i]] = i;
            }

            //Problem description assures that there's always at least one solution in nums so this shouldn't happen.
            return {-1 , -1};                    
        }
};
