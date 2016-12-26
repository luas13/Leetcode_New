class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector< vector<int> > vv;
        vv.push_back(nums);
        
        if(nums.size() < 2){
            return vv;
        }
        
        int pos=0;
        
        while(pos < nums.size()-1){
            int s= vv.size();
            
            for(int i=0; i<s; i++){
                
                //sort the array, so that the same number will be together
                sort(vv[i].begin() + pos, vv[i].end());
                
                //take each number to the first
                for(int j= pos+1; j < vv[i].size(); j++){
                    vector<int> v= vv[i];
                    
                    if(j>0 && v[j] == v[j-1])
                        continue;
                        
                    int t= v[j];
                    v[j]= v[pos];
                    v[pos]= t;
                    
                    vv.push_back(v);
                }
            }
            
            pos++;
        }
        
        return vv;
    }
};