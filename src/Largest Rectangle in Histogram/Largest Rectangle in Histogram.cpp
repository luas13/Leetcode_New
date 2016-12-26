//Its better to store index of element in the stack because
//at any point of time, u can get both the element and its value
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int l = heights.size();
        if (l < 2)
            return (l == 0 ?  0: heights[0]);
            
        stack<int> s;
        int i=0;
        int max_area = INT_MIN;
        
        while (i<l)
        {
            if (s.empty() || heights[s.top()] <= heights[i])
               s.push(i++);
               
            else
            {
                int topi = s.top();
                s.pop();
                
                max_area = max(max_area, heights[topi] * (s.empty() ? i : i-1 - s.top()) );
            }
        }
        
        while (!s.empty())
        {
            int topi = s.top();
            s.pop();
                
            max_area = max(max_area, heights[topi] * (s.empty() ? l : l-1 - s.top()) );
        }
        
        return max_area;
    }
};