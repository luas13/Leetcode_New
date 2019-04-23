/*
1. Maintain a vector of vector<int>, Initially this will contain the vector of num given
2. Swap values at index 'pos' (pos starts with 0 til l-1) with "all the numbers present at
pos+1 till l-1 one at a time". 
3. Do this for every vector<int> present at any moment in the vector<vector<int>>.
4. Make sure you first sort every vector<int> from 'pos' till end. 
*/

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
                
                //take each number after index pos to pos
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


/*
Example:
Input: [1,1,2,3,4,3]

1 1 2 3 4 3
after
1 1 2 3 3 4
2 1 1 3 3 4
3 1 2 1 3 4
4 1 2 3 3 1
after
1 1 2 3 3 4  // 1st old vector
2 1 1 3 3 4  // 2nd old vector
3 1 1 2 3 4  // 3rd old vector
4 1 1 2 3 3  // 4th old vector

1 2 1 3 3 4  // Swapped version of 1st old vector, 1st index value not disturbed, i.e. "1"
1 3 2 1 3 4
1 4 2 3 3 1

2 3 1 1 3 4  // Swapped version of 2nd old vector, 1st index value not disturbed, i.e. "2"
2 4 1 3 3 1

3 2 1 1 3 4  // Swapped version of 3rd old vector, 1st index value not disturbed, i.e. "3"
3 3 1 2 1 4
3 4 1 2 3 1

4 2 1 1 3 3  // Swapped version of 4th old vector, 1st index value not disturbed, i.e. "4"
4 3 1 2 1 3 

so on...
*/
