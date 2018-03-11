/*
1 billion = 10^9
1 million = 10^6

if (n >= 1000000000) return helper(n/1000000000) + " Billion" + helper(n - 1000000000 * (n/1000000000));
and why not 
if (n >= 1000000000) return to_string(n/1000000000) + " Billion" + helper(n - 1000000000 * (n/1000000000));
because there might be 1 billion 998 million ...

else if (n >= 1) return string(" ") + below_20[n -1]; and why not
else if (n >= 1) return " " + below_20[n -1];
because it throws a compile error
invalid operands of types 'const char [2]' and 'const char* const' to binary 'operator+'

return helper(num).substr(1);
and why not
return helper(num);
because since we have recursiely utilised the helper functions to print smaller number as well
which has " " in it's prefix, eg. 123 would have been " One Hundred Twenty Three"

*/

class Solution {
private:
        static const char* const below_20[];
        static const char* const below_100[];
        string helper(int n)
        {
            if (n >= 1000000000) return helper(n/1000000000) + " Billion" + helper(n - 1000000000 * (n/1000000000));
            else if (n >= 1000000) return helper(n/1000000) + " Million" + helper(n - 1000000 * (n/1000000));
            else if (n >= 1000) return helper(n/1000) + " Thousand" + helper(n - 1000 * (n/1000));
            else if (n >= 100) return helper(n/100) + " Hundred" + helper(n - 100 * (n/100));
            else if (n >= 20) return string(" ") + below_100[n/10 - 2] + helper(n - 10 * (n/10));
            else if (n >= 1) return string(" ") + below_20[n -1];
            else return "";
        }
    
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        return helper(num).substr(1);
    }
};

const char* const Solution::below_100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const char* const Solution::below_20[] = {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};