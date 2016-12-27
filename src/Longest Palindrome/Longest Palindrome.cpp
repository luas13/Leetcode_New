using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int l= s.size();
        map<char,int> mymap;
        
        int i= 0;
        int j= 0;
        int c= 0;
        int max= INT_MIN;
        
        while(i<l){
            if(mymap.find(s[i]) == mymap.end()){
                mymap[s[i]] = 1;
            }
            else{
                mymap[s[i]]++;
            }
            i++;
        }
        
        map<char,int>::iterator it;
        for (it= mymap.begin(); it!=mymap.end(); it++){
            if (! (it->second % 2)){
                c+= it->second;
                //cout<<it->first<<" ";
            }
            else{
                if(max < it->second)
                    max= it->second;
                c+= it->second-1;
            }
        }
        //cout<<max<<endl;
        if (max != INT_MIN){
            //c+= max;
            return (c+1);
        }
        return c;
    }
};