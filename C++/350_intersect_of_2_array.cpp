#include <vector>
#include <unordered_map>
using namespace std;

/*
Given two arrays, write a function to compute their intersection.
Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

解题思路：
1、hash
2、sort+two pointer
3、简单粗暴：在nums1里find nums2的所有元素，如果找到，从nums1里删除
*/

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		unordered_map<int, int> m;
		for (int i : nums1) m[i]++;
		for (int i : nums2) {
			if (--m[i] >= 0) res.push_back(i); 
			//先判断key存在，节省空间
			//if (m.find(i) != m.end() && --m[i] >= 0) res.push_back(i);
		}
		return res;
	}
};

//class Solution {
//public:
//	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//		vector<int> res;
//		for (int i : nums2) {
//			auto it = find(nums1.begin(), nums1.end(), i);
//			if (it != nums1.end()) {
//				res.push_back(i);
//				nums1.erase(it);
//			}
//		}
//		return res;
//	}
//};

//class Solution {
//public:
//	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//		vector<int> res;
//		sort(nums1.begin(), nums1.end());
//		sort(nums2.begin(), nums2.end());
//		int i = 0;
//		int j = 0;
//		while (i < nums1.size() && j < nums2.size()) {
//			if (nums1[i] == nums2[j]) {
//				res.push_back(nums1[i]);
//				i++;
//				j++;
//			}
//			else if (nums1[i] > nums2[j]) j++;
//			else i++;
//		}
//		return res;
//	}
//};