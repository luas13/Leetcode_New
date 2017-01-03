/*
1) Create an empty stack and push -1 to it. The first element
   of stack is used to provide base for next valid string. 

2) Initialize result as 0.

3) If the character is '(' i.e. str[i] == '('), push index 
   'i' to the stack. 
   
2) Else (if the character is ')')
   a) Pop an item from stack (Most of the time an opening bracket)
   b) If stack is not empty, then find length of current valid
      substring by taking difference between current index and
      top of the stack. If current length is more than result,
      then update the result.
   c) If stack is empty, push current index as base for next
      valid substring.

3) Return result.
*/
class Solution {
public:
    // Imp Point is u need to push index of opening bracket
    // to stack and not the opening bracket itself. Then u 
    // can keep track of length of valid parenthesis
    
    //*** Create a stack and push -1 as initial index to it. ***
    
    int longestValidParentheses(string s) {
        int l= s.length();
        if (!l || l==1)
            return 0;
            
        stack<int> st;
        st.push(-1);
        int maxlen = 0;
        
        for(int i=0; i<l; i++)
        {
            if (s[i] == '(')
               st.push(i);
            else
            {
                st.pop();
                    
                if (st.empty())
                    st.push(i);
                else
                    maxlen = max(maxlen, i - st.top());
            }
        }
        return maxlen;
    }
};