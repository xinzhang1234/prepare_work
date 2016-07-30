/*
 * 179. Largest Number
 * Given a list of non negative integers, arrange them such that they form the largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need to return a string instead of an integer.
 *
 *
 * */
/*
First, cmp each element in vector
if ab > ba, then a > b
*/
 #include <math.h>
    int bit(int a)
    {
        if (a == 0)
            return 1;
        int cnt = 0;
        while(a)
        {
            cnt++;
            a = a/10;
        }
        return cnt;
    }
    
    bool cmp(int a, int b)
    {
        int a_t = bit(a);
        int b_t = bit(b);
        if (a * pow(10, b_t) + b > b * pow(10, a_t)+a)
            return true;
        else
            return false;
    } 
    
class Solution {
public:

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string s = "";
        bool all_zeros = true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                all_zeros = false;
            s += to_string(nums[i]);
            cout << nums[i] << endl;
        }
        if (all_zeros)
            return "0";
        return s;
    }
};












