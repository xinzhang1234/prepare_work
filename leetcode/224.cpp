/*224. basic calculator*/

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
*/
class Solution {
public:
    int calculate(string s) {
        stack<int> R;
        int num = 0;
        int total = 0;
        int sign = 1;
        
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                num = 10 * num + (s[i] -'0');
            else if (s[i] == '+')
            {
                total += sign * num;
                sign = 1;
                num = 0;
            }
            else if (s[i] == '-')
            {
                total += sign * num;
                sign = -1;
                num = 0;
            }
            else if (s[i] == '(')
            {
                R.push(total);
                R.push(sign);
                sign = 1;
                total = 0;
                
            }
            else if (s[i] == ')')
            {
                int s1 = R.top();
                R.pop();
                int t1 = R.top();
                R.pop();
                total += sign * num;
                num = 0;
                total *= s1;
                total += t1;
            }
            
        }
        return total;
    }
};
