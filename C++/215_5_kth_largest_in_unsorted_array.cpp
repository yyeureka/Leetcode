#include <vector>
#include <queue>
#include <algorithm>
#include <xfunctional>
using namespace std;

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

解题思路：
1、使用quick sort思想的quick select，O(n)时间
2、最小priority queue，O(N) best case / O(N^2) worst case time + O(1) memory
   所有nums都push进去，pq超过k时开始pop，返回pq.top()即k个最大值中的最小值即第k大
3、最大priority queue，pop第k个出来
4、max-heap，pop_heap k次，倒数第k个即为第k大
5、sort以后，默认从小到大排序，[]返回第k大元素，O(NlogK) time + O(K) memory
*/

class Solution {
public:
	int kthLargestElement(int n, vector<int> &nums) {
		if (nums.empty()) return -1;

		return quickSelect(nums, 0, nums.size() - 1, n); //k不减1
	}

	int quickSelect(vector<int> &nums, int start, int end, int k) {
		if (start >= end) return nums[k - 1];

		int i = start;
		int j = end;
		int pivot = nums[start]; //pivot要先保存

		while (i <= j) { //不是<
			while (i <= j && nums[i] > pivot) i++; //先左先右无所谓
			while (i <= j && nums[j] < pivot) j--;

			if (i <= j) swap(nums[i++], nums[j--]);
		}

		if (k - 1 <= j) quickSelect(nums, start, j, k);
		if (k - 1 >= i) quickSelect(nums, i, end, k);
		return nums[k - 1];
	}
};

//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		priority_queue<int, vector<int>, greater<int>> pq;
//		for (auto i : nums) {
//			pq.push(i);
//			if (pq.size() > k) pq.pop();
//		}
//		return pq.top();
//	}
//};

//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		sort(nums.begin(), nums.end());
//		return nums[nums.size() - k];
//	}
//};

//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		priority_queue<int> pq(nums.begin(), nums.end());
//		while (k-- > 1) pq.pop();
//		return pq.top();
//	}
//};
//
//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		make_heap(nums.begin(), nums.end());
//		auto iter = nums.end();
//		while (k-- > 0) pop_heap(nums.begin(), iter--);
//		return *iter;
//	}
//};