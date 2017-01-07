class Solution {
public:
    // Only when the each word has unique characters
    /*
    string bitsort(string s)
    {
        int t=0;
        for(int i=0; i<s.size(); i++)
            t |= (1<<(s[i] - 'a'));
        
        string tmp;
        for(int i=0; i<26; i++)
            if (t & (1<<i))
                tmp += ('a'+ i);
                
        return tmp;
    }*/
    
    string bitsort(string s)
    {
        int t[26] ={0};
        for(int i=0; i<s.size(); i++)
            t[s[i]-'a']++; 
        
        string tmp;
        for(int i=0; i<26; i++)
            while (t[i]--)
                tmp += ('a'+ i);
                
        return tmp;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int l = strs.size();
        vector<vector<string>> result;
        if (!l)
            return result;
        
        map<string, vector<string>> ht;
        
        // Instead of sorting we use BITwise operation
        for(int i=0; i<l; i++)
        {
            string tmp = bitsort(strs[i]);
            ht[tmp].push_back(strs[i]);
        }
        
        for(auto it = ht.begin(); it != ht.end(); it++)
            result.push_back(it->second);
        
        return result;
    }
};