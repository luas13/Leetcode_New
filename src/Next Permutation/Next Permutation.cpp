/*
Analysis

The steps to solve this problem:
1) scan from right to left, find the first element that is less than its previous one.

4 5 6 3 2 1 
  |
  p
2) scan from right to left, find the first element that is greater than p.

4 5 6 3 2 1 
    |
    q
3) swap p and q

4 5 6 3 2 1 
swap
4 6 5 3 2 1 

4) reverse elements [p+1, nums.length]

4 6 1 2 3 5 
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int s= nums.size();
        if(s <= 1)
            return;
        int vind= s-1;
        int cind= s-1;
        
        while(vind > 0){
            if(nums[vind] > nums[vind - 1])
                break;
            vind--;
        }
        
        if(vind > 0)
        {
            vind--;                               // point to the index corresponding to which value is smaller than next
            
            while(cind > vind){
                if( nums[cind] > nums[vind])
                    break;
                cind--;
            }
        
            int t= nums[cind];
            nums[cind]= nums[vind];
            nums[vind]= t;
            
            vind++;
        }
        
        cind= s-1;
        
        while(vind < cind){
            int t= nums[cind];
            nums[cind]= nums[vind];
            nums[vind]= t;
            
            vind++;
            cind--;
        }
        
    }
};
