// 1st Method: ~ 9ms better with space also
//    The algroithm - Take each element in array to the pos's index.
//    And pos varies from [0..nums.size()-2]
//    The max limit of pos is nums.size()-2 so that at least 1 element
//    on the right of pos gets swapped with pos value
//
//    For example: 
//    
//         0) initalization 
// 
//             pos = 0
//             [1, 2, 3]   
//
//         1) take each element into the pos's index, i.e. 0 
//            for all the vectors present in vector of vectors
//
//             pos = 0
//             [1, 2, 3]  ==> [ [2, 1, 3],
//                              [3, 2, 1]] 
//
//             then we have total 3 answers
//             [1, 2, 3],  [2, 1, 3] , [3, 2, 1] 
//            
//         2) take each element into the pos's index, i.e. 1
//            for all the vectors present in vector of vectors
//
//             pos = 1  , pos=0 kept intact
//             [1, 2, 3]  ==>  [1, 3, 2]
//             [2, 1, 3]  ==>  [2, 3, 1]
//             [3, 2, 1]  ==>  [3, 1, 2] 
//
//             then we have total 6 answers
//             [1, 2, 3],  [2, 1, 3] , [3, 2, 1], [1, 3, 2], [2, 3, 1], [3, 1, 2]
//
//          3) pos = 2 which greater than nums.size()-2, return.
//

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > vv;
        vv.push_back(nums);
        
        if(nums.size() < 2){
            return vv;
        }
        
        int pos=0;
        
        // for every position
        while(pos < nums.size()-1){
            
            // This is a very imp step, otherwise infinite loop
            // because vv.size() increases inside the coming loop
            int s= vv.size();
            
            // for each vector in vector of vector
            for(int i=0; i<s; i++){
                // Keep generating a vector by swapping all elements from
                // pos+1 to length-1. Generate total (length-1 - (pos+1) + 1)
                // vectors
                for(int j= pos+1; j < vv[i].size(); j++){
                    vector<int> v= vv[i];
                    
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
//2nd Method: DP with rotations ~13ms more than above + more space

//Assuming that we have an array of a = [1,2,3] we will start with

//r = [[1]]; // result
//t = [];    // interim result
//Then follow these three steps;

//1. For each item of our r (result) array we will add the next item of the input array.
//2. We will rotate each item it's length many times and will store each instance at the interim result array t. (well except for the first one not to waste time with 0 rotation)
//3. Once we finish with all items of r the interim array t should hold the next level of results so we make r = t; t = []; and carry on up until the length of the input array a.

//So the following are our steps;

//r array              t array
//[[1,2]]              [[1,2],
//                      [2,1]]
//[[1,2],[2,1]]        [[1,2,3],[2,3,1],[3,1,2],
//                      [2,1,3],[1,3,2],[3,2,1]]

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > result;
        int l = nums.size();
        
        if(l < 2){
            result.push_back(nums);
            return result;
        }
        
        vector<int> initial;
        initial.push_back(nums[0]);
        result.push_back(initial);
        //result.push_back(vector<int> (nums[0]));
        
        for(int i=1; i<l; i++)
        {
            vector<vector<int>> midresult;
            
            // For all the vectors in vector of vector rotate them
            for (int j=0; j<result.size(); j++)
            {
                result[j].push_back(nums[i]);
                // Push nums[i] element in result[j] and push to midresult
                midresult.push_back(result[j]);
        
                //each vector's length
                int eachveclen = result[j].size();
                
                // For result[j].size() - 1 times rotate result[j]
                // And push them to midresult
                
                vector<int> tmp;
                
                for(int k=1; k < eachveclen; k++)
                {
                    // Storing the rotated result[j]
                    //vector<int> tmp;  this too work, no need to initialise to empty vector alwz
                    tmp = vector<int>();
                    
                    for (int m=0; m<eachveclen; m++)
                        tmp.push_back(result[j][(k+m) % eachveclen]);
                    
                    midresult.push_back(tmp);
                }
            }
            
            result = midresult;
        }
        return result;
    }
};
*/
