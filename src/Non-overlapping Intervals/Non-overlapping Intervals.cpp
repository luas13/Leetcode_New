class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int>& i1, const vector<int>& i2) {return i1[0] < i2[0];};
        sort(intervals.begin(), intervals.end(), comp);
        int prev = 0, count= 0;
        
        for(int i=1; i<intervals.size(); i++)
        {
            if (intervals[i][0] < intervals[prev][1])
            {
                count++;
                // very imp: if intervals[i][1] < intervals[prev][1] then
                // also you need to update prev, not when it's >
                if (intervals[i][1] < intervals[prev][1])
                    prev = i;
            }
            else
                prev = i;
        }
        
        return count;
    }
};