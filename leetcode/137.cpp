/*137. Single Number II
 *Given an array of integers, every element appears three times except for one. Find that single one.
 * */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() < 3)
            return nums[0];
        vector<int> A(32,0);
        for (int i = 0; i < nums.size(); i++)
        {
            int tmp = nums[i];
            int n = 0;
            for(int j = 0; j < 32; j++)
            {
                A[j] =  (((tmp >> j) & 1) + A[j]) % 3;
            }
        }
        int r = 0;
        for (int i = 0; i < 32; i++)
            r += (A[i] << i);
        return r;
    }
};
