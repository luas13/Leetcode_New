/*
Go through this first
https://briangordon.github.io/2014/08/the-skyline-problem.html

https://www.geeksforgeeks.org/difference-set-multiset-unordered_set-unordered_multiset/

Multiset
(i) Stores elements in sorted order.
(ii) It allows storage of multiple elements.
(iii) We can erase more than 1 element by giving start iterator and end iterator.
eg. it's value at any instant can be : 2 10 10 12 45 85 90

A rectangle is stored like (left_coord, -height), (right_coord, height)
because these are the critical points where changes can occur
imp is -ve height with left coordinate, so that we process the height
during it's entry and remove that height's contribution when we exit

Significance of -ve: A rectangle's both critical point have same height.
We need a mechanism such that we know when we reach the right coordinate
of rectangle. when this occur, remove it's contribution from height multiset.
It's not required that you put -ve sign only with rectangle's left coordinate, 
you can attach with right coordinate as well & make left coordinate positive,
just make sure while processing each critical point, u check conditions accordingly
:
        ....
        
        for(auto b: buildings)
        {
            myset.emplace(make_pair(b[0], b[2]));
            myset.emplace(make_pair(b[1], -b[2]));
        }
        
        multiset<int> height({0});
        for(auto cp: myset)
        {
            if (cp.second > 0) height.emplace(cp.second);
            else height.erase(height.find(-cp.second));
            
        ....

Algo:
1. Create sorted set of critical points. A rectangle can give 2 critical points.
Since many rectangles can have same height so we use multiset here.

2. Since the multiset is sorted parse from left to right.

3. Create a multiset of int which only stores the heights of rectangle. Initialise
it with {0} which is important. Add to it when u begin processing a particular 
rectangle & remove from it once it's  contribution is over.

4. Important is to maintain the last pair pushed to result. Save it in curr
which is compared everytime with last element in height multiset.
If it's different then only we push in result. Last element essentially means
the largest height uptil now before it's contribution is not over.

eg. Input:
[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ]

Multiset after inserting crtical points. Check the use of implace in mutliset.
2 -10
3 -15
5 -12
7 15
9 10
12 12
15 -10
19 -8
20 10
24 8

Output:
[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]

*/

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        pair<int, int> curr ({0,0});
        vector<pair<int, int>> result;
        multiset<pair<int, int>> myset;
        
        for(auto b: buildings)
        {
            myset.emplace(make_pair(b[0], -b[2]));
            myset.emplace(make_pair(b[1], b[2]));
        }
        
        multiset<int> height({0});
        for(auto cp: myset)
        {
            if (cp.second < 0) height.emplace(-cp.second);
            else height.erase(height.find(cp.second));
            
            if(*height.rbegin() != curr.second)
            {
                curr.first = cp.first;
                curr.second = *height.rbegin();
                result.push_back(curr);
            }
        }
        return result;
    }
};