/*
 *151. Reverse Words in a String
 Given an input string, reverse the string word by word.

 For example,
 Given s = "the sky is blue",
 return "blue is sky the".

 Update (2015-02-12):
 For C programmers: Try to solve it in-place in O(1) space.

 click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
 */

/*hard part is how to reduce the multiple blank within a string
use a blank sign to indicate whether we need a blank or not*/
class Solution {
public:
    void reverse(string &s, int i, int j)
    {
        while(i < j)
            swap(s[i++], s[j--]);
    }
    
    void reverseWords(string &s) {
    bool blank = false;
    int i = 0;
    int j = 0;
    int len = s.size();
    while(i < len)
    {
        if (s[i] != ' ')
        {
            s[j++] = s[i++];
            blank = true;
        }
        else
        {
            if(blank)
            {
                s[j++] = s[i++];
                blank = false;
            }
            else
                i++;
        }
    }
    if (j > 0 && s[j-1] == ' ')
        s = s.substr(0,j-1);
    else
        s = s.substr(0,j);
    reverse(s, 0, s.size()-1);
    len = s.size();
    blank = false;
    j = 0;
    for (i = 0; i < len; i++)
    {
        if (s[i] != ' ')
            continue;
        else
        {
            reverse(s, j, i-1);
            j = i+1;
        }
    }
    reverse(s, j, i-1);
     
    }
};
