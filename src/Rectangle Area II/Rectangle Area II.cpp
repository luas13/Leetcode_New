/* 
This problem is a 2D version of Merge Interval problem, i.e. merge
all the horizontal blocks going vertically


From solution: Line Sweep
-------------------------
Intuition

Imagine we pass a horizontal line from bottom to top over the shape. 
We have some active intervals on this horizontal line, which gets 
updated twice for each rectangle. In total, there are 2∗N events, 
and we can update our (up to N) active horizontal intervals for each update.

Algorithm

For a rectangle like rec = [1,0,3,1], the first update is to add 
[1, 3] to the active set at y = 0, and the second update is to remove 
[1, 3] at y = 1. Note that adding and removing respects multiplicity - 
if we also added [0, 2] at y = 0, then removing [1, 3] at y = 1 will 
still leave us with [0, 2] active.

This gives us a plan: create these two events for each rectangle, 
then process all the events in sorted order of y. The issue now is 
deciding how to process the events add(x1, x2) and remove(x1, x2) 
such that we are able to query() the total horizontal length of our 
active intervals.

We can use the fact that our remove(...) operation will always be on 
an interval that was previously added. Let's store all the (x1, x2) 
intervals in sorted order. Then, we can query() in linear time using 
a technique similar to a classic LeetCode problem, Merge Intervals.


Below is sligghtly changed version of above algorithm but does the 
same thing, i.e. merge horizontally while going vertically

Scan from y = 0, count the coverage of rectangles on x.
For example, at y = 0, the intervale [0, 3] is covered by rectangles.
The current sum of coverage is 3.

Then we move our scan line upper to next y.
At y = 1, we add (1 - 0) * 3 = 3 to area. Now area = 3.
And we update the sum of coverage to 2 because it's coverd on [0, 2].

Then we move our scan line upper to next y.
At y = 2, we add (2 - 1) * 2 = 2 to area. Now area = 5.
And we update the sum of coverage to 1 because it's coverd on [1, 2].

Then we move our scan line upper to next y.
At y = 3, we add (3 - 2) * 1 = 1 to area. Now area = 6.
And we update the sum of coverage to 0.

The final result is 6.

Pseudocode:
1. Initialize a vector(x) with 0 and store all the x-coordinates
2. Sort this vector (x), and remove duplicates
3. Create a map, where key is x vector's value and value is it's index
4. Create a vector, count. 
    count[i] means the number of overlaps on the interval [x[i], x[i + 1]]
5. Create a vector of vector, L, which stores values like this
    1st value: height
    2nd value: extreme left x coordiante
    3rd value: extreme right x coordinate
    4th value: +1 for starting left coordinate point and -1 for ending right coordinate 
                point of rectangle provided in vector of vector: rectangles
                
6. Sort L, which essentially sort it based on height
7. For all the rectangles saved in L
    a. calculate and update area 
    b. update count vector
    c. initialize curr sweeping x area = 0
    d. calculate the sweeping x area based on updated count array
    
8. Return area
    
*/

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int mod = 1000000000 + 7;
        vector<int> x = {0};
        for (auto v: rectangles)
        {
            x.push_back(v[0]);
            x.push_back(v[2]);
        }
        
        sort(x.begin(), x.end());
        vector<int>::iterator end_unique = unique(x.begin(), x.end());
        x.erase(end_unique, x.end());
        
        // create a map so as to get the intervals of x where you need to iterate.
        // It's efficient otherwise we would have to loop over each x-coordinate
        // beginning from minimum x-coordinate and maximum x-coordinate at every
        // level/interval of y 
        unordered_map<int, int> x_i;
        for(int i=0; i<x.size(); i++)
            x_i[x[i]] = i;
        
        vector<int> count(x.size(), 0);
        vector<vector<int>> L;
        for(auto v: rectangles)
        {
            L.push_back({v[1], v[0], v[2], 1});
            L.push_back({v[3], v[0], v[2], -1});
        }
        
        sort(L.begin(), L.end());
        
        long long curr_x_sum = 0, area = 0, curr_y = 0;
        
        for (auto v: L)
        {
            long long y = v[0], x1 = v[1], x2 = v[2], sign = v[3];
            area = (area + (y- curr_y) * curr_x_sum) % mod;
            curr_y = y;
            
            // count[i] means the number of overlaps on the interval [x[i], x[i + 1]]
			// i.e number of overlaps between different segments of rectangle
            
            // my points: count keeps track of 2 things:
            
            // a. stretch of x, when it plays a role of a horizontal marker, stating
            // blocks/segments starting from these points should be added to horizontal area. 
            // Please note, it does not contain point at which segments end, this is 
            // ascertained by i<x_i[x2] and not i<=x_i[x2]
            
            // b. nullify the event's contribution when we move upwards by count[i] += sign
            // sign will be -ve for end event
            // as we create two events per rectangle
			
			// When we encounter a new segment [x1, x2] the algorithm only consider 
            // the points in [x1, x2), means we never deal with the end point, then
            // when check if a segment is covered or not, we always check the start point 
            // if (count[i] > 0) cur_x_sum += x[i + 1] - x[i]
            
            for(int i=x_i[x1]; i<x_i[x2]; i++)
                count[i] += sign;
            
            curr_x_sum = 0;
            for(int i=0; i<x.size(); i++)
                if (count[i] > 0)
                    curr_x_sum += x[i+1] - x[i];
        }
        return area;
    }
};

/*
// with print statements

class Solution {
public:
    void display(vector<int>& arr)
    {
        for(auto e: arr)
            cout<<e<<" ";
        cout<<endl;
    }
    
    void display_L(vector<vector<int>>& L)
    {
        for(auto v: L)
        {
            for(auto e: v)
                cout<<e<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    
    int rectangleArea(vector<vector<int>>& rectangles) {
        int mod = 1000000000 + 7;
        // prepend with 0
        vector<int> x = {0};
        for (auto r : rectangles) {
            x.push_back(r[0]);
            x.push_back(r[2]);
        }
        
        cout<<"x is "<<endl;
        display(x);
        cout<<endl;
        
        sort(x.begin(), x.end());
        
        cout<<"Sorted x: "<<endl;
        display(x);
        cout<<endl;
        
        // resturns An iterator to the element that follows the last element not removed.
        vector<int>::iterator end_unique = unique(x.begin(), x.end());
        // eg. 10 20 20 20 30 30 20 20 10
        // 10 20 30 20 10 ?  ?  ?  ?
        //                ^
        
        // erase element from end_unique's iterator position till end
        x.erase(end_unique, x.end());
        
        cout<<"After erase x"<<endl;
        display(x);
        cout<<endl;
        
        unordered_map<int, int> x_i;
        for (int i = 0; i < x.size(); ++i) {
            x_i[x[i]] = i;
        }
        
        for (auto it= x_i.begin(); it != x_i.end(); it++)
            cout<<it->first<<"->"<<it->second<<endl;
        cout<<endl;
        
        vector<int> count(x.size(), 0);
        vector<vector<int>> L;
        for (auto r : rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            L.push_back({y1, x1, x2, 1});
            L.push_back({y2, x1, x2, -1});
        }
        
        cout<<"L is: "<<endl;
        display_L(L);
        cout<<endl;
        
        sort(L.begin(), L.end());
        
        cout<<"Sorted L is: "<<endl;
        display_L(L);
        cout<<endl;
        
        long long cur_y = 0, cur_x_sum = 0, area = 0;
        for (auto l : L) {
            long long  y = l[0], x1 = l[1], x2 = l[2], sig = l[3];
            area = (area + (y - cur_y) * cur_x_sum) % mod;
            cout<<"area: "<<area<<endl;
            cur_y = y;

            // count[i] means the number of overlaps on the interval [x[i], x[i + 1]]
			// i.e number of overlaps between different segments of rectangle
			
			// When we encounter a new segment [x1, x2] the algorithm only consider 
            // the points in [x1, x2), means we never deal with the end point, then
            // when check if a segment is covered or not, we always check the start point 
            // if (count[i] > 0) cur_x_sum += x[i + 1] - x[i]

            for (int i = x_i[x1]; i < x_i[x2]; i++)
            {
                count[i] += sig;
                cout<<"count["<<i<<"] "<<count[i]<<endl;
            }
            
            cur_x_sum = 0;
            for (int i = 0; i < x.size(); ++i) {
                if (count[i] > 0)
                    cur_x_sum += x[i + 1] - x[i];
            }
            cout<<"cur_x_sum: "<<cur_x_sum<<endl;
        }
        return area;
    }
};

For input: [[0,0,4,1],[2,0,4,4],[3,0,6,2]]

x is 
0 0 4 2 4 3 6 

Sorted x: 
0 0 2 3 4 4 6 

After erase x
0 2 3 4 6 

6->4
4->3
3->2
0->0
2->1

L is: 
0 0 4 1 
1 0 4 -1 
0 2 4 1 
4 2 4 -1 
0 3 6 1 
2 3 6 -1 


Sorted L is:    
y x1 x2 sign
0 0  4  1 
0 2  4  1 
0 3  6  1 
1 0  4  -1 
2 3  6  -1 
4 2  4  -1 

x_i map
6->4
4->3
3->2
0->0
2->1


area: 0
count[0] 1
count[1] 1
count[2] 1
cur_x_sum: 4
area: 0
count[1] 2
count[2] 2
cur_x_sum: 4
area: 0
count[2] 3
count[3] 1
cur_x_sum: 6
area: 6
count[0] 0
count[1] 1
count[2] 2
cur_x_sum: 4
area: 10
count[2] 1
count[3] 0
cur_x_sum: 2
area: 14
count[1] 0
count[2] 0
cur_x_sum: 0
*/