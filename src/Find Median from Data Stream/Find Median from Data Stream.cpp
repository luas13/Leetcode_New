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