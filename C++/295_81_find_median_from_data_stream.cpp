#include <queue>
#include <vector>
#include <xfunctional>
using namespace std;

/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
For example,
[2,3,4], the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5
Design a data structure that supports the following two operations:
void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
Follow up:
If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?

Example:
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2

解题思路：#480简化版
maxheap保存小于等于median的元素，minheap保存大于median的元素
add num的时候less push，larger push less的top，如果less的size比larger的size小，less push larger的top
最后返回less的top或less的top和larger的top的一半
*/

class MedianFinder {
private:
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		left.push(num);
		right.push(left.top());
		left.pop();

		if (left.size() < right.size()) {
			left.push(right.top());
			right.pop();
		}
	}

	double findMedian() {
		if (left.size() > right.size()) return left.top();
		else return (left.top() + right.top()) / 2.0;
	}
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/