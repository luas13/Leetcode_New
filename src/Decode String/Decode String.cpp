/*
Just push all the characters untill u encounter ']' to the stack
If u encounter ']', 
    create a tmp string by popping from stack.
    *U need to reverse this tmp string.
    
    create a tmp string, bc of count
    
    create a processed string pasting bc times the tmp string
    
    push this processed string back into the stack.
    
At the end the stack contains the processed string.
* but in reverse order. Reverse & return it.

* A small thing, string(1, c) is a way to cast a character to string in c++.

*/

class Solution {
public:
    string decodeString(string s) {
        int l = s.length();
        if (!l)
            return ("");
        stack<char> st;
        
        for(int i=0; i<l; i++)
        {
            if (s[i] != ']')
                st.push(s[i]);
            else
            {
                string tmp, proc, count;
                while(!st.empty() && (st.top() >= 'a' && st.top() <= 'z') || (st.top() >= 'A' && st.top() <= 'Z'))
                {
                    tmp = st.top() + tmp;
                    st.pop();
                }
                
                if (st.top() == '[')
                    st.pop();
                
                while(!st.empty() && st.top() >= '0' && st.top() <= '9')
                {
                    count = st.top() + count;
                    st.pop();
                }
                
                for(int i=0; i<stoi(count); i++)
                    proc +=tmp;
                
                for(char c: proc)
                    st.push(c);
            }
        }
        
        string res;
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

/*
class Solution {
public:
    string decodeString(string s) {
        int l = s.length();
        string result;
        if (!l)
            return result;
        
        stack<char> st;
        for(int i=0; i<l; i++)
        {
            if (s[i] != ']')
                st.push(s[i]);
            else
            {
                string tmp, procs;
                while(!st.empty() && ( st.top() >= 'a' && st.top() <= 'z' || st.top() >= 'A' && st.top() <= 'Z') )
                {
                    char a = st.top();
                    st.pop();
                
                    tmp += string(1, a);
                }
                reverse(tmp.begin(), tmp.end());
                
                if (st.top() == '[')
                    st.pop();
                
                string bc;
                while(!st.empty() && st.top() >='0' && st.top() <='9')
                {
                    bc = st.top() + bc;
                    st.pop();
                }
                
                for(int i=0; i<stoi(bc); i++)
                    procs += tmp;
                
                for(int i=0; i<procs.length(); i++)
                    st.push(procs[i]);
            }
        }
        
        while(!st.empty())
        {
            result += string(1, st.top());
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
*/
