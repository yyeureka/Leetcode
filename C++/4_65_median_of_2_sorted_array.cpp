#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5

解题思路：
1、定义二分：
   长为n的A有0~n共n+1中划分法(BS的l和r) 以i划分(BS的mid)：
   A[0],A[1]...A[i-1] | A[i]...A[n-1]
   B[0],B[1]...B[j-1] | B[j]...B[m-1]
   median的定义：
   a.左右两部分相等：i+j=n-i+m-j+1(奇数的median放左边)=>j=(n+m+1)/2-i
   b.左max<=右min:
   若A[i-1]>B[j],则i太大应往左移
   若B[j-1]>A[i],则i应往右移
   else即为找到，odd时为max(A[i-1],B[j-1]),even时为min(A[i],B[j])和max(A[i-1],B[j-1])的均值
2、找第k小方法：
   A、B分别取0~k/2-1个元素
   如A[k/2-1]>B[k/2-1],即第k小不在B中,从A的0开始和B的k/2开始找第k-k/2小——哪个小丢哪个的数
*/
 
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) swap(nums1, nums2); //分割少的那一半
		int n = nums1.size();
		int m = nums2.size();

		int l = 0;
		int r = n; //易错！！
		while (l <= r) { //易错
			int i = l + (r - l) / 2;
			int j = (n + m + 1) / 2 - i; //如果奇数 median在左边 如果偶数 左右两边相等

			if (i > 0 && nums1[i - 1] > nums2[j]) r = i - 1;
			else if (i < n && nums2[j - 1] > nums1[i]) l = i + 1; //条件i<n易错
			else {
				int l_max = INT_MIN; //易错，不能=0
				if (i > 0) l_max = max(l_max, nums1[i - 1]);
				if (j > 0) l_max = max(l_max, nums2[j - 1]);

				if ((n + m) & 1) return l_max;

				int r_min = INT_MAX; //易错，不能=0
				if (i < n) r_min = min(r_min, nums1[i]);
				if (j < m) r_min = min(r_min, nums2[j]);

				return (l_max + r_min) / 2.0;
			}
		}
		return 0.0;
	}
};

//class Solution {
//public:
//	double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
//		int size = A.size() + B.size();
//
//		if (size & 1) {
//			return findKth(A, 0, B, 0, size / 2 + 1); //易错
//		}
//		else {
//			return (findKth(A, 0, B, 0, size / 2) + findKth(A, 0, B, 0, size / 2 + 1)) / 2.0;
//		}
//	}
//
//	int findKth(vector<int> &A, int start1, vector<int> &B, int start2, int k) {
//		if (start1 >= A.size()) {
//			return B[start2 + k - 1];
//		}
//		if (start2 >= B.size()) {
//			return A[start1 + k - 1];
//		}
//		if (1 == k) {
//			return min(A[start1], B[start2]);
//		}
//
//		if (start1 + k / 2 - 1 >= A.size()) {
//			return findKth(A, start1, B, start2 + k / 2, k - k / 2); //易错 k-k/2不能写成k/2
//		}
//		else if (start2 + k / 2 - 1 >= B.size()) {
//			return findKth(A, start1 + k / 2, B, start2, k - k / 2);
//		}
//		else if (A[start1 + k / 2 - 1] < B[start2 + k / 2 - 1]) {
//			return findKth(A, start1 + k / 2, B, start2, k - k / 2);
//		}
//		else {
//			return findKth(A, start1, B, start2 + k / 2, k - k / 2);
//		}
//	}
//};


