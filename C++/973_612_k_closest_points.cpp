#include "head.h"

/*
Given some points and an origin point in two-dimensional space, find k points which are nearest to the origin.
Return these points sorted by distance, if they are same in distance, sorted by the x-axis, and if they are same in the x-axis, sorted by y-axis.

Example 1:
Input: points = [[4,6],[4,7],[4,4],[2,5],[1,1]], origin = [0, 0], k = 3
Output: [[1,1],[2,5],[4,4]]
Example 2:
Input: points = [[0,0],[0,9]], origin = [3, 1], k = 1
Output: [[0,0]]

解题思路：#973到[0,0]的距离，更简单
1、quick select第k+1个，左边即为前k小，lint612不能用这种方法
2、size k的maxheap——nlogk
3、heapify，再pop出k个点——n+klogn
4、minheap——nlogn
5、直接sort Point——nlogn
*/

class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		quickSelect(points, 0, points.size() - 1, K);

		return vector<vector<int>>(points.begin(), points.begin() + K);
	}

	void quickSelect(vector<vector<int>>& points, int start, int end, int K) {
		if (start >= end) {
			return;
		}

		int i = start;
		int j = end;
		int pivot = getDistance(points[(i + j) / 2]);

		while (i <= j) {
			while (i <= j && getDistance(points[i]) < pivot) {
				i++;
			}
			while (i <= j && getDistance(points[j]) > pivot) {
				j--;
			}

			if (i <= j) {
				swap(points[i++], points[j--]);
			}
		}

		if (j >= K) {
			quickSelect(points, start, j, K);
		}
		if (i <= K) {
			quickSelect(points, i, end, K);
		}
	}

	int getDistance(vector<int> a) {
		return (a[0] * a[0] + a[1] * a[1]);
	}
};

////maxheap
//Point p;
//
//struct cmp {
//	const bool operator()(Point a, Point b) {
//		int distanceA = (a.x - p.x) * (a.x - p.x) + (a.y - p.y) * (a.y - p.y);
//		int distanceB = (b.x - p.x) * (b.x - p.x) + (b.y - p.y) * (b.y - p.y);
//		if (distanceA != distanceB) {
//			return distanceA < distanceB;
//		}
//		if (a.x != b.x) {
//			return a.x < b.x;
//		}
//		return a.y < b.y;
//	}
//};
//
//class Solution {
//public:
//	vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
//		p = origin;
//
//		priority_queue<Point, vector<Point>, cmp> maxheap;
//		for (auto i : points) {
//			maxheap.push(i);
//			if (maxheap.size() > k) {
//				maxheap.pop();
//			}
//		}
//
//		vector<Point> results(k);
//		for (int i = k - 1; i >= 0; i--) {
//			results[i] = maxheap.top();
//			maxheap.pop();
//		}
//
//		return results;
//	}
//};

//minheap
//Point p;
//
//struct cmp {
//	const bool operator()(Point a, Point b) {
//		int distanceA = (a.x - p.x) * (a.x - p.x) + (a.y - p.y) * (a.y - p.y);
//		int distanceB = (b.x - p.x) * (b.x - p.x) + (b.y - p.y) * (b.y - p.y);
//		if (distanceA != distanceB) {
//			return distanceA > distanceB;
//		}
//		if (a.x != b.x) {
//			return a.x > b.x;
//		}
//		return a.y > b.y;
//	}
//};
//
//class Solution {
//public:
//	vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
//		p = origin;
//
//		priority_queue<Point, vector<Point>, cmp> minheap;
//		for (auto i : points) {
//			minheap.push(i);
//		}
//
//		vector<Point> results;
//		for (int i = 0; i < k; i++) {
//			results.push_back(minheap.top());
//			minheap.pop();
//		}
//
//		return results;
//	}
//};

//sort
//Point p;
//
//bool cmp(Point a, Point b) { //易错，sort的cmp写成function
//	int distanceA = (a.x - p.x) * (a.x - p.x) + (a.y - p.y) * (a.y - p.y);
//	int distanceB = (b.x - p.x) * (b.x - p.x) + (b.y - p.y) * (b.y - p.y);
//	if (distanceA != distanceB) {
//		return distanceA < distanceB;
//	}
//	if (a.x != b.x) {
//		return a.x < b.x;
//	}
//	return a.y < b.y;
//}
//
//class Solution {
//public:
//	vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
//		p = origin;
//
//		sort(points.begin(), points.end(), cmp);
//		return vector<Point>(points.begin(), points.begin() + k);
//	}
//};