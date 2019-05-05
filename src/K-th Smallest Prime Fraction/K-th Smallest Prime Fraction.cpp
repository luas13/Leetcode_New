/*
Time Complexity: O(max(n, k)logn) // n- no of elements in array
My points: 
*First loop of Insertion in pq is nlogn
*Popping and adding elements in next loop is klogn,
remember here the pq will always have n elements

Very similar to merge k sorted linked lists

check https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115531/C%2B%2B-9lines-priority-queue
it is like find k-th smallest element in n sorted array, 
which has a classic solution using priority_queue

consider an input of [n0, n1, n2, n3, n4], the possible factors are:
[n0/n4, n0/n3, n0/n2, n0/n1, n0/n0]
[n1/n4, n1/n3, n1/n2, n1/n1]
[n2/n4, n2/n3, n2/n2]
[n3/n4, n3/n3]
[n4/n4]


Priority queue is by default a max heap
Save some lines of code by pushing values multiplied by -1
i.e. negate the value, thus you don't require mean heap creation
and comparator code because here all the values are positve given

For priority queue of pair, where 
first is: ni/n(l-1)     // ith number / last number
second is: {i, l-1-i}   // start & end index of sorted array

example
content of pq in the beginning is:
{-n0/n4, {0, 4}}  // on top and rest pairs are
{-n1/n4, {1, 4}}
{-n2/n4, {2, 4}}
{-n3/n4, {3, 4}}
{-n4/n4, {4, 4}}

next step, with top not guarenteed, contents of pq will be:
{-n0/n3, {0, 3}}  // squeeze end index
{-n1/n4, {1, 4}}
{-n2/n4, {2, 4}}
{-n3/n4, {3, 4}}
{-n4/n4, {4, 4}}

Trobleshoot:
1. Multiply by -1.0 and not by -1
    comparision is done based on double value and not int
2. Squeeze end index and not begin index 
    after each step of processing, we are not interested in last index
    as we delete A[first_index]/A[last_index]. We are more interested
    in A[first_index]/A[last_index-1]
3. while (--k > 0) and not while (--k)
*/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int l = A.size();
        
        priority_queue<pair<double, pair<int, int>>> pq;
        for (int i=0; i<l; i++)
            pq.push(make_pair(-1.0*A[i]/A[l-1], make_pair(i, l-1)));
        
        while(--K > 0)
        {
            pair<int, int> tmp = pq.top().second;
            pq.pop();
            int i = tmp.first;
            int j = tmp.second;
            j--;                    // squeeze end index
            pq.push(make_pair(-1.0*A[i]/A[j], make_pair(i, j)));
        }
        
        return {A[pq.top().second.first], A[pq.top().second.second]};
    }
};