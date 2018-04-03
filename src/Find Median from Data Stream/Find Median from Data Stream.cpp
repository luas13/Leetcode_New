// Soln: 1 Longer code
class MedianFinder {
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    double median;
    int left;
    int right;
public:
    MedianFinder()
    {
        median = INT_MAX;
        left = 0;
        right = 0;
    }
    
    // Adds a number into the data structure.
    void addNum(int num) {
        int x= num;
        if (x < median)
        {
            if (left > right)
            {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(x);
                right++;
                median = double(maxheap.top() + minheap.top())/double(2);
            }
            else if (left == right)
            {
                maxheap.push(x);
                left++;
                median = maxheap.top();
            }
            else
            {
                maxheap.push(x);
                left++;
                median = double(maxheap.top() + minheap.top())/double(2);
            }
        }
    
        // x > median push new element to minheap
        else
        {
            if (left > right)
            {
                minheap.push(x);
                right++;
                median = double(maxheap.top() + minheap.top())/double(2);
            }
            else if (left == right)
            {
                minheap.push(x);
                right++;
                median = minheap.top();
            }
            else
            {
                maxheap.push(minheap.top());
                minheap.pop();
                left++;
                minheap.push(x);
                median = double(maxheap.top() + minheap.top())/double(2);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return median;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();



// Soln: 2 Shorter Code
/*
https://leetcode.com/problems/find-median-from-data-stream/solution/

Two priority queues:

A max-heap lo to store the smaller half of the numbers
A min-heap hi to store the larger half of the numbers
The max-heap lo is allowed to store, at worst, one more element more than the min-heap hi. Hence if we have processed kk elements:

Adding a number num:

Add num to max-heap lo. Since lo received a new element, we must do a balancing step for hi. So remove the largest element from lo and offer it to hi.
The min-heap hi might end holding more elements than the max-heap lo, after the previous operation. We fix that by removing the smallest element from hi and offering it to lo.
The above step ensures that we do not disturb the nice little size property we just mentioned.

A little example will clear this up! Say we take input from the stream [41, 35, 62, 5, 97, 108]. The run-though of the algorithm looks like this:

Adding number 41
MaxHeap lo: [41]           // MaxHeap stores the largest value at the top (index 0)
MinHeap hi: []             // MinHeap stores the smallest value at the top (index 0)
Median is 41
=======================
Adding number 35
MaxHeap lo: [35]
MinHeap hi: [41]
Median is 38
=======================
Adding number 62
MaxHeap lo: [41, 35]
MinHeap hi: [62]
Median is 41
=======================
Adding number 4
MaxHeap lo: [35, 4]
MinHeap hi: [41, 62]
Median is 38
=======================
Adding number 97
MaxHeap lo: [41, 35, 4]
MinHeap hi: [62, 97]
Median is 41
=======================
Adding number 108
MaxHeap lo: [41, 35, 4]
MinHeap hi: [62, 97, 108]
Median is 51.5
*/

class MedianFinder {
    priority_queue<int> lo;                              // max heap
    priority_queue<int, vector<int>, greater<int>> hi;   // min heap

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // Add to max heap

        hi.push(lo.top());                               // balancing step
        lo.pop();

        if (lo.size() < hi.size()) {                     // maintain size property
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return lo.size() > hi.size() ? (double) lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};
