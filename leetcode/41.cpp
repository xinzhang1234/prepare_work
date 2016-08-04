/*41. First Missing Positive
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.*/


/*the final sorted array should be like this
  0  1  2  3  4
  1  2  3  4  5
  find the array[i] != i+1
  if all the element in sorted array is correct, the missing value must be len + 1, for the above array, the missing number is 6  
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            while (nums[i] != (i+1) && (nums[i]-1) < len && (nums[i]-1) >= 0 && nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }
        for(int i = 0; i < len; i++)
        {
            if (nums[i] != (i+1))
                return i+1;
        }
        return len+1;
    }
    
};
