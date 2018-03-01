/*
O(n^2) soln
1. First create all combinations of sum possible with first two arrays
2. Keep on checking -(of all combinations of sum possible with 3rd & 4th array) in the map
3. Keep on adding all the count possible with each sum combinations of 3rd & 4th array from 
the map's value (Imp)
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int l = A.size();
        if (!l)
           return 0;
        int count = 0;
        
        unordered_map<int,int> twosumCombinations;
        for (auto a: A)
            for(auto b: B)
                twosumCombinations[a+b]++;
        
        for(auto c: C)
            for(auto d: D)
                if (twosumCombinations.find(-(c+d)) != twosumCombinations.end())
                    count += twosumCombinations[-(c+d)];
                    
        return count;
    }
};