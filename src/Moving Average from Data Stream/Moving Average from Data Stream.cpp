/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

*/

class MovingAverage{
private:
	double sum;
	int size;
	queue<int> avgQueue;

public:
	MovingAverage(int s)
	{
		this->size = s;
		this->sum = 0;
	}

	double next(int v)
	{
		if (avgQueue.size() > size)
		{
			sum -= avgQueue.front();
			avgQueue.pop();
		}
		avgQueue.push(v);
		sum += v;
		return sum/avgQueue.size();
	}
};