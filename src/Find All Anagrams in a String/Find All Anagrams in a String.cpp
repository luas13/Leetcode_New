/*
This uses a window mechanism. Populate ptbale & stable 
after seeing pattern size string. Then start a loop from 
pl and traverse till sl. Keep comparing the vectors ptable
& stable after every character & append it to result.

When u see a new character from s, increment that character's count in stable 
while decrease the count of the past character which is at pl distance 
from the current character.

*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sl = s.length();
        int pl = p.length();
        vector<int> result;
        
        if (sl < pl)
            return result;
        
        vector<int> stable(26, 0);
        vector<int> ptable(26, 0);
        
        for(int i=0; i<pl; i++)
        {
            stable[s[i] - 'a']++;
            ptable[p[i] - 'a']++;
        }
        
        // u can compare the vectors like this
        if (stable == ptable)
            result.push_back(0);
        
        for(int i=pl; i<sl; i++)
        {
            ++stable[s[i]-'a'];
            --stable[s[i-pl]-'a'];
            
            if (stable == ptable)
                result.push_back(i-pl+1);
        }
        
        return result;
    }
};