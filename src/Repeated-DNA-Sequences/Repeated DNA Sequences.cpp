/*
 All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

Solution:
1)Starting from every character,get a substring of length 10 
2)Calculate its hash value
3)Increment the count in unordered_map with hash as the key
4)Check if the count is 2,insert it into result string

*/

#define MAX_LEN 10

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> data;
        hash<string> hash_func;  //Unary function object class that defines the default hash function used by the 
                                 //standard library
        vector<string> res;
        
        for(int i=0; (i + MAX_LEN) <= s.size(); i++)
        {
            string str= s.substr(i, MAX_LEN);
            int hash_code= hash_func(str);
            data[hash_code]++;
            
            if(data[hash_code] == 2)
                res.push_back(str);
        }
        
        return res;
        
    }
};
