// Soln 1: O(1) extra space
// https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

/*
Push(x) : Inserts x at the top of stack.

If stack is empty, insert x into the stack and make minEle equal to x.
If stack is not empty, compare x with minEle. Two cases arise:
1. If x is greater than or equal to minEle, simply insert x.
2. If x is less than minEle, insert (2*x – minEle) into the stack and make 
minEle equal to x. For example, let previous minEle was 3. Now we want 
to insert 2. We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.


Pop() : Removes an element from top of stack.

Remove element from top. Let the removed element be y. Two cases arise:
1. If y is greater than or equal to minEle, the minimum element in the stack 
is still minEle.
2. If y is less than minEle, the minimum element now becomes (2*minEle – y), 
so update (minEle = 2*minEle – y). This is where we retrieve previous minimum 
from current minimum and its value in stack. For example, let the element 
to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.


Important Points:

** Stack doesn’t hold actual value of an element if it is minimum so far.
** Actual minimum element is always stored in minEle

*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<long> s;
    long minEle;
    
    MinStack() {
        
    }
    
    // void push(int x) - this needs to be changes to pass the testcase
    void push(long x) {
        if (s.empty())
        {
            s.push(x);
            minEle = x;
        }
        else
        {
            if (x < minEle)
            {
                s.push(2*x - minEle);
                minEle = x;
            }
            else
                s.push(x);
        }
    }
    
    void pop() {
        if (s.empty())
            return;
        long y = s.top();
        s.pop();
        
        if (y < minEle)
            minEle = 2*minEle - y;
        // else
        // {
        //     cout<<"Element is ", y;
        // }
    }
    
    int top() {
        if (s.empty())
            return -1;
        long y = s.top();
        if (y < minEle)
            return minEle;
        else
            return y;
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */