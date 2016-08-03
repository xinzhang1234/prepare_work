/*201. Bitwise AND of Numbers Range
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 *
 * For example, given the range [5, 7], you should return 4.*
 */

/*find the first common prefix of m and n in binary*/
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n)
            return m;
        vector<int> v1, v2;
        for(int i = 0; i < 32; i++)
        {
            v1.push_back(((m & (1 << i)) >> i) & 1);
            v2.push_back(((n & (1 << i)) >> i) & 1);
        }
        
        int r = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (v1[i] == v2[i])
                r += (v1[i] << i);
            else
                break;
        }
        return r;
        
    }
};
 
