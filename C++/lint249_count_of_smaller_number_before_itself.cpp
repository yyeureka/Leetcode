#include "head.h"

/*
Give you an integer array (index from 0 to n-1, where n is the size of this array, data value from 0 to 10000) . For each element Ai in the array, count the number of element before this element Ai is smaller than it and return count number array.

Example 1:
Input:
[1,2,7,8,5]
Output:
[0,1,2,3,2]
Example 2:
Input:
[7,8,2,1,3]
Output:
[0,1,0,0,2]

Clarification
Before you do this, we suggest you complete the following three questions: Segment Tree Build， Segment Tree Query II，and Count of Smaller Number before itself I 。

解题思路：
1、binary indexed tree
   初始bit[1]~bit[maxNum]均为0
   每一个num，更新A(num)的值为1，并更新相应的bit[?]
   对每一个num，计算prefixSum(num-1),有几个比它小的就是几个1相加
2、segment tree
*/

class Solution {
private:
	class BITree {
	private:
		vector<int> bit; //1~range为有效值
	public:
		BITree(int range) { //range为最大数上限
			bit = vector<int>(range + 2, 0);
		}

		void update(int index, int val) {
			index++;
			while (index < bit.size()) {
				bit[index] += val;
				index += lowBit(index);
			}
		}

		int prefixSum(int index) {
			int sum = 0;

			index++;
			while (index > 0) {
				sum += bit[index];
				index -= lowBit(index);
			}

			return sum;
		}

		int lowBit(int index) {
			return index & (-index);
		}

	};
public:
	vector<int> countOfSmallerNumberII(vector<int> &A) {
		vector<int> result;
		BITree *tree = new BITree(10000);

		for (int num : A) {
			result.push_back(tree->prefixSum(num - 1)); //-1易错
			tree->update(num, 1);
		}

		return result;
	}
};