class Solution {
public:
    int myAtoi(string str) {
        int l = str.length();
        if (!l)
            return 0;
        
        int i=0;
        while(i<l && str[i] == ' ')
            i++;
        
        int sign = 1, base = 0;
        
        // increment i only if you encounter '+' or '-'
        if (str[i] == '+')
        {
            sign = 1;
            i++;
        }
        else if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
        
        while(i<l && str[i] >= '0' && str[i] <= '9')
        {
            if (base > INT_MAX/10 || (base == INT_MAX/10 && str[i] > '7'))
            {
                return (sign == 1 ? INT_MAX: INT_MIN);
            }
            
            // bracket is extremely imp here, else overflow
            base = base*10 + (str[i] - '0');
            i++;
        }
        
        return sign*base;
    }
};