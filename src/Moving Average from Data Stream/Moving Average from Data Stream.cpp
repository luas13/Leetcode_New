/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

*/

#include <iostream>
#include <queue>

using namespace std;

class MovingAverage{
private:
	double sum;
	int size;
	queue<int> avgQueue;

public:
	MovingAverage(int s)
	{
		size = s;
		sum = 0;
	}

	void printq(queue<int> q)
	{
	    cout<<"Current queue is: ";
	    while(!q.empty())
	    {
	        cout<<q.front()<<" ";
	        q.pop();
	    }
	}
	
	double next(int v)
	{
		if (avgQueue.size() >= size)
		{
			sum -= avgQueue.front();
			avgQueue.pop();
		}
		avgQueue.push(v);
		sum += v;
		
		printq(avgQueue);
		return sum/avgQueue.size();
	}
};

int main()
{
    MovingAverage m(3);
    
    cout<<"\nMoving Avg: "<<m.next(1)<<endl;
    cout<<"\nMoving Avg: "<<m.next(10)<<endl;
    cout<<"\nMoving Avg: "<<m.next(4)<<endl;
    cout<<"\nMoving Avg: "<<m.next(3)<<endl;
    
    return 0;
}
