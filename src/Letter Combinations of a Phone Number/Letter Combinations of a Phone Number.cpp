/*
The important part is swap() function which swaps the value in constant time

Simple and efficient iterative solution.

Explanation with sample input “234”

Initial state:

result = {""}
Stage 1 for number “1”:

result has {""}
candiate is “abc”
generate three strings “” + “a”, “”+“b”, “”+“c” and put into tmp,
tmp = {“a”, “b”,“c”}
swap result and tmp (swap does not take memory copy)
Now result has {“a”, “b”, “c”}
Stage 2 for number “2”:

result has {“a”, “b”, “c”}
candidate is “def”
generate nine strings and put into tmp,
“a” + “d”, “a”+“e”, “a”+“f”,
“b” + “d”, “b”+“e”, “b”+“f”,
“c” + “d”, “c”+“e”, “c”+“f”
so tmp has {“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf” }
swap result and tmp
Now result has {“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf” }
Stage 3 for number “3”:

result has {“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf” }
candidate is “ghi”
generate 27 strings and put into tmp,
add “g” for each of “ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf”
add “h” for each of “ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf”
add “h” for each of “ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf”
so, tmp has
{“adg”, “aeg”, “afg”, “bdg”, “beg”, “bfg”, “cdg”, “ceg”, “cfg”
“adh”, “aeh”, “afh”, “bdh”, “beh”, “bfh”, “cdh”, “ceh”, “cfh”
“adi”, “aei”, “afi”, “bdi”, “bei”, “bfi”, “cdi”, “cei”, “cfi” }
swap result and tmp
Now result has
{“adg”, “aeg”, “afg”, “bdg”, “beg”, “bfg”, “cdg”, “ceg”, “cfg”
“adh”, “aeh”, “afh”, “bdh”, “beh”, “bfh”, “cdh”, “ceh”, “cfh”
“adi”, “aei”, “afi”, “bdi”, “bei”, “bfi”, “cdi”, “cei”, “cfi” }
Finally, return result.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        int l = digits.length();
        if (!l)
            return result;
        // vector<string> result;
        result.push_back("");
        
        for(int i=0; i<l; i++)
        {
            int num = digits[i] - '0';
            if (num < 0 || num > 9)
                break;
            string cand = v[num];
            if (cand.empty()) continue;
            
            vector<string> tmp;
            for(int j=0; j<cand.length(); j++)
            {
                for(int k=0; k<result.size(); k++)
                {
                    tmp.push_back(result[k] + cand[j]);
                }
            }
            
            result.swap(tmp);
        }
        
        return result;
    }
};