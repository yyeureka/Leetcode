#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

解题思路：
1、利用了unordered_set查找的时间效率为O(1)，如果某数i，i-1不在set中，依次判断i+1、i+2...
2、union-find：代码较复杂，但近似线性时间
*/

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_set<int> memo;
		int maxLen = INT_MIN;

		for (int i : num) {
			memo.insert(i);
		}

		for (int i : num) {
			if (memo.find(i - 1) != memo.end()) { //这句是关键，否则就不是O(n)了
				continue;
			}

			int j = i + 1;
			while (memo.find(j) != memo.end()) {
				j++;
			}

			maxLen = max(maxLen, j - i);
		}

		return maxLen;
	}
};


//class Solution {
//public:
//	int longestConsecutive(vector<int>& nums) {
//		int size = nums.size();
//
//		UF uf(size);
//		unordered_map<int, int> m; //key为num，value为在nums中的idx
//		for (int i = 0; i < size; i++) {
//			if (m.find(nums[i]) != m.end()) continue; //易错
//
//			m[nums[i]] = i;
//			if (m.find(nums[i] + 1) != m.end()) {
//				uf.quick_union(i, m[nums[i] + 1]); //将num与num+1的union合并
//			}
//			if (m.find(nums[i] - 1) != m.end()) {
//				uf.quick_union(i, m[nums[i] - 1]); //将num与num-1的union合并
//			}
//		}
//		return uf.max_union();
//	}
//
//private:
//	class UF {
//	private:
//		vector<int> v;
//		vector<int> sz;
//
//		int get_root(int i) {
//			while (i != v[i]) { //path compression
//				v[i] = v[v[i]];
//				i = v[i];
//			}
//			return i;
//		}
//
//	public:
//		UF(int n) {
//			for (int i = 0; i < n; i++) {
//				v.push_back(i);
//				sz.push_back(1);
//			}
//		}
//
//		void quick_union(int p, int q) {
//			int i = get_root(p);
//			int j = get_root(q);
//			if (i == j) return;
//			if (sz[i] < sz[j]) { //weighted quick union
//				v[i] = j;
//				sz[j] += sz[i];
//			}
//			else {
//				v[j] = i;
//				sz[i] += sz[j];
//			}
//		}
//
//		int max_union() {
//			int res = 0;
//			for (int i : sz) res = max(res, i);
//			return res;
//		}
//	};
//};