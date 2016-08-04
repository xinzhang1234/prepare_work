/*268.  Missing Number
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 *
 * For example,
 * Given nums = [0, 1, 3] return 2.
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?*/

/* suppose sort array such that A[i] = i+1
   if the sorted array is correct, then the missing number must be 0;
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            while (nums[i] != i+1 && (nums[i]-1) < len && (nums[i]-1) >= 0)
            {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i = 0; i < len; i++)
        {
            if(nums[i] != (i+1))
                return i+1;
        }
        return 0;
    }
};
