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
                
                //sort the array from pos, so that the same number will be together
                // *** Imp point is not to sort the array from beginning
                // bcz lets say with {1,1,2} u get [[1,2,1], [2,1,1]]
                // if u sort from begin [[1,2,1], [2,1,1]] -> [[1,1,2], [1,1,2]]
                // so purpose destroyed
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