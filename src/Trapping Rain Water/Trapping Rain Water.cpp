class Solution {
public:
    // The easiest question, just think of calculating the amount
    // of water trapped on EACH elevation/tower
    int trap(vector<int>& height) {
        int l = height.size();
        if (!l || l==1)
            return 0;
            
        int water =0;    
        // leftmax[i] is max element on left side including it
        vector<int> leftmax(l, 0);
        vector<int> rightmax(l, 0);
        
        leftmax[0] = height[0];
        for(int i=1; i<l; i++)
            leftmax[i] = max(leftmax[i-1], height[i]);
        
        rightmax[l-1] = height[l-1];
        for(int i=l-2; i>=0; i--)
            rightmax[i] = max(rightmax[i+1], height[i]);
            
        for(int i=0; i<l; i++)
            water += min(leftmax[i], rightmax[i]) - height[i];
            
        return water;
    }
};