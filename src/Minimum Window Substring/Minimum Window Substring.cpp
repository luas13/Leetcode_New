class Solution {
public:
    string minWindow(string s, string t) {
        int sl = s.length();
        int tl = t.length();
        if (!sl || !tl)
            return "";
        
        // unordered_map<char, int> need_to_find;
        // unordered_map<char, int> has_found;
        
        // Provides much optimization w.r.t. time
        int need_to_find[256] = {0};
        int has_found[256] = {0};
        
        int count = 0;
        int min_win_len=INT_MAX, min_win_beg = 0;
        
        for(int i=0; i<tl; i++)
            need_to_find[t[i]]++;
        
        for(int begin=0, end=0; end<sl; end++)
        {
            if (!need_to_find[s[end]])
                continue;
            has_found[s[end]]++;
            
            if (has_found[s[end]] <= need_to_find[s[end]])
                count++;
            
            if (count == tl)
            {
                while(has_found[s[begin]] > need_to_find[s[begin]] || need_to_find[s[begin]] == 0)
                {
                    if (has_found[s[begin]] > need_to_find[s[begin]])
                        has_found[s[begin]]--;
                    begin++;
                }
                
                if (min_win_len > end-begin+1)
                {
                    min_win_len = end-begin+1;
                    min_win_beg = begin;
                }
            }
        }
        
        return min_win_len == INT_MAX? "": s.substr(min_win_beg, min_win_len);
    }
};