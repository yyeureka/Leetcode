#include "head.h"

/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example 1:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1 // return 1.00000
m.next(10) = (1 + 10) / 2 // return 5.50000
m.next(3) = (1 + 10 + 3) / 3 // return 4.66667
m.next(5) = (10 + 3 + 5) / 3 // return 6.00000
*/

class MovingAverage {
public:
	int window;
	double sum;
	vector<int> stream;

	MovingAverage(int size) {
		window = size;
		sum = 0;
	}

	double next(int val) {
		stream.push_back(val);
		sum += val;

		if (stream.size() > window) {
			sum -= stream[stream.size() - window - 1];
		}

		return sum / min((int)stream.size(), window); //рв╢М
	}
};

/**
* Your MovingAverage object will be instantiated and called as such:
* MovingAverage obj = new MovingAverage(size);
* double param = obj.next(val);
*/