/*
This question is not related to trapping rain-water because here we want
to find two lines, which together with x-axis forms a container. x-axis is
important here.

Not related with largest rectangle in a histogram.

A very simple question

Start by evaluating the widest container, using the first and the last line. 
All other possible containers are less wide, so to hold more water, they need 
to be higher. Thus, after evaluating that widest container, skip lines at 
both ends that don’t support a higher height. Then evaluate that new container 
we arrived at. Repeat until there are no more possible containers left.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = height.size();
        if (!l)
            return 0;
        
        int max_area = 0;
        int lo = 0, hi = l-1;
        while(lo < hi)
        {
            int h = min(height[lo], height[hi]);
            max_area = max(max_area, h * (hi-lo) );
            
            while(height[lo] <= h && lo < hi)
                lo++;
            while(height[hi] <= h && hi > lo)
                hi--;
        }
        return max_area;
    }
};