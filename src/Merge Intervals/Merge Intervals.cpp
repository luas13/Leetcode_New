/*
Updated problem and easy solution
1. Sort based on start time
2. Push 1st interval
3. Loop from 2nd interval to last
4. If current element's start time is > end time of last interval in res (which is a vector)
		push in the current interval in the result
	else
		merge the last interval's end time in stack with current interval's end time
		make sure you take max, because this case can happen [(1, 6), (2, 4) ...]
		
*/
class Solution {
public:
    struct mycomp
    {
        bool operator()(vector<int>& i1, vector<int>& i2)
        {
            return i1[0] < i2[0];
        }
    };
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int l = intervals.size();
        if (!l)
            return {};
        
        // sort based on start time
        sort(intervals.begin(), intervals.end(), mycomp());
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for(int i=1; i<l; i++)
        {
            if (intervals[i][0] > res.back()[1])
                res.push_back(intervals[i]);
            else
                res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        
        return res;
    }
};

/*
An efficient approach is to first sort the intervals according 
to starting time. Once we have the sorted intervals, we can combine 
all intervals in a linear traversal. The idea is, in sorted array of 
intervals, if interval[i] doesn’t overlap with interval[i-1], then 
interval[i+1] cannot overlap with interval[i-1] because starting time 
of interval[i+1] must be greater than or equal to interval[i]. 
Following is the detailed step by step algorithm.

1. Sort the intervals based on increasing order of starting time.
2. Push the first interval on to a stack.
3. For each interval do the following
   a. If the current interval does not overlap with the stack 
       top, push it.
   b. If the current interval overlaps with stack top and ending
       time of current interval is more than that of stack top, 
       update stack top with the ending  time of current interval.
4. At the end stack contains the merged intervals. 
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 
/*
// Old problem statement and solution
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int l = intervals.size();
        vector<Interval> result;
        if (!l)
            return result;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){ return a.start < b.start;});
        
        stack<Interval> s;
        s.push(intervals[0]);
        
        for(int i=1; i<l; i++)
        {
            Interval top = s.top();
            if (top.end < intervals[i].start)
                s.push(intervals[i]);
            else if (top.end < intervals[i].end)
            {
                top.end = intervals[i].end;
                s.pop();
                s.push(top);
            }
        }
        
        while(!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};