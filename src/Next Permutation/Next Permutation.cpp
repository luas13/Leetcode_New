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