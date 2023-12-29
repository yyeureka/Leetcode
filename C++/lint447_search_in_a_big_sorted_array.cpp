#include "head.h"

/*
Given a big sorted array with non-negative integers sorted by non-decreasing order. The array is so big 
so that you can not get the length of the whole array directly, and you can only access the kth number 
by ArrayReader.get(k) (or ArrayReader->get(k) for C++).
Find the first index of a target number. Your algorithm should be in O(log k), where k is the first index 
of the target number.
Return -1, if the number doesn't exist in the array.

Example 1:
Input: [1, 3, 6, 9, 21, ...], target = 3
Output: 1
Example 2:
Input: [1, 3, 6, 9, 21, ...], target = 4
Output: -1

Challenge
O(logn) time, n is the first index of the given target number.

Notice
If you accessed an inaccessible index (outside of the array), ArrayReader.get will return 2,147,483,647.

����˼·��
�ȱ������ҵ��߽��>target��λ��
��bs��target
*/

//class Solution {
//public:
//	int searchBigSortedArray(ArrayReader * reader, int target) { //c++�б�������
//		if (NULL == reader) return -1;
//
//		int start = 0;
//		int end = 0;
//		while (reader->get(end) < target) {
//			start = end;
//			end = 2 * end + 1;
//		}
//
//		while (start + 1 < end) {
//			int mid = start + (end - start) / 2;
//
//			if (target == reader->get(mid)) return mid;
//			else if (target > reader->get(mid)) start = mid;
//			else end = mid;
//		}
//
//		if (target == reader->get(start)) return start;
//		if (target == reader->get(end)) return end;
//		return -1;
//	}
//};