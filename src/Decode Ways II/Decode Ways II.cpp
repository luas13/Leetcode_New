class Solution {
public:
    int numDecodings(string s) {
        int l = s.size();
        int M = 1e9 + 7;
        vector<long> dp(l+1, 0);
        
        //dp[i] = total no of ways of decoding first i characters of string
        
        dp[0] = 1;
        
        // 0 is returned directly if the first character of the string is 0
        if (s[0] == '0') return 0;
        dp[1] = (s[0] == '*')? 9: 1;
        
        for (int i=2; i<=l; i++)
        {
            // Currently traversed character S[i-1], only three cases possible, 
            // 0 or 1 to 9 of the number, or an asterisk.
            
            // This situation is relatively simple, because 0 can not be separated, 
            // can only be with the previous number, 
            // so no contribution of dp[i-1] to dp[i] and the previous number can only 
            // be 1 or 2, the other direct return 0 can. So when the previous number 
            // is 1 or 2, Dp[i], The number of species is equal to dp[i-2]
            
            // If the previous number is an asterisk, then the previous number can 
            // be 1 or 2, which is equal to twice times the dp[i-2] and if 
            // the previous number is 0, return directly to 0.
            if (s[i-1] == '0')
            {
                if (s[i-2] == '1' || s[i-2] == '2')
                    dp[i] = dp[i-2];
                else if (s[i-2] == '*')
                    dp[i] = 2*dp[i-2];
                else
                    return 0;
            }
            
            // Figure out the current number can be split out alone, 
            // so dp[i] at least equal to dp[i-1]
            
            // It is also necessary to discuss the type of the previous number
            // to further increase the decoding method. If the curr & previous digit
            // makes a no that is less than or equal to 26, dp[i] also needs to add dp[i-2]
            
            // If the preceding number is an asterisk, and if the current number is 
            // less than or equal to 6, Then the previous number can be 1 or 2, 
            // at this time dp[i] need to add twice times the dp[i-2], 
            // if greater than 6, then the previous number can only be 1, 
            // so dp[i] can only add dp[i-2]. 
            else if (s[i-1] >= '1' && s[i-1] <= '9')
            {
                dp[i] = dp[i-1];
                if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6') )
                    dp[i] += dp[i-2];
                else if (s[i-2] == '*')
                    dp[i] += (s[i-1] <= '6')? (2* dp[i-2]) : dp[i-2];  
            }
            
            // Finally if the current number is an asterisk, then create 
            // 9 separate decoding ways, so dp[i] at least 9 times times the dp[i-1]
            
            // It is also necessary to discuss the type of the previous number
            // to further increase the decoding method. If the previous number is 1, 
            // then the current 9 cases can be combined with the previous number of 
            // two digits, so dp[i] need to add 9 times times the dp[i-2];
            
            // If the previous number is 2, then only 6 of the cases less than or equal 
            // to 6 can be combined with the previous number of two digits, so dp[i] 
            // need to add 6 times times the dp[i-2]
            
            // If the previous number is an asterisk, then the sum of the above 
            // two cases, dp[i] need to add 15 times times the dp[i-2].
            else
            {
                dp[i] = 9* dp[i-1];
                if (s[i-2] == '1') dp[i] += 9 * dp[i-2];
                else if (s[i-2] == '2') dp[i] += 6 * dp[i-2];
                else if (s[i-2] == '*')
                    dp[i] += 15 * dp[i-2];
            }
            
            dp[i] %= M; 
        }
        
        return dp[l];
    }
};