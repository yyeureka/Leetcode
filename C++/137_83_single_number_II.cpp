#include <vector>
using namespace std;

/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,3,2]
Output: 3
Example 2:
Input: [0,1,0,1,0,1,99]
Output: 99

解题思路：
1、one为重复一次的bit，two为重复两次的bit
因为其他数是出现三次的，也就是说，对于每一个二进制位，
如果只出现一次的数在该二进制位为1，那么这个二进制位在全部数字中出现次数无法被3整除。
对于每一位，我们让Two，One表示当前位的状态。

我们看Two和One里面的每一位的定义，对于ith(表示第i位)：
如果Two里面ith是1，则ith当前为止出现1的次数模3的结果是2
如果One里面ith是1，则ith目前为止出现1的次数模3的结果是1
注意Two和One里面不可能ith同时为1，因为这样就是3次，每出现3次我们就可以抹去（消去）。
那么最后One里面存储的就是每一位模3是1的那些位，综合起来One也就是最后我们要的结果。

如果B表示输入数字的对应位，Two+和One+表示更新后的状态
那么新来的一个数B，此时跟原来出现1次的位做一个异或运算，&上~Two的结果(也就是不是出现2次的)，
那么剩余的就是当前状态是1的结果。
同理Two ^ B （2次加1次是3次，也就是Two里面ith是1，B里面ith也是1，那么ith应该是出现了3次，
此时就可以消去，设置为0），我们相当于会消去出现3次的位。
但是Two ^ B也可能是ith上Two是0，B的ith是1，这样Two里面就混入了模3是1的那些位！
我们得消去这些！我们只需要保留不是出现模3余1的那些位ith，而One是恰好保留了那些模3余1次数的位，
`取反不就是不是模3余1的那些位ith么？最终对(~One+)取一个&即可

2、sort，以3为单位比较i和i+1是否相等
3、hash
*/

class Solution {
public:
	int singleNumberII(vector<int> &A) {
		int one = 0;
		int two = 0;

		for (int num : A) {
			one = (one ^ num) & ~two; //清除第三次出现的bit
			two = (two ^ num) & ~one; //清除第一次出现的bit
		}

		return one;
	}
};

//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		int one = 0;
//		int two = 0;
//		int three = 0;
//		for (int i : nums) {
//			two |= one & i;		//将某个i是否出现两次置进two
//			one ^= i;			//将这个i从出现一次的one中清除
//			three = one & two;  //出现两次并出现一次即为出现三次
//			one &= ~three;		//将出现三次的从one中清除
//			two &= ~three;		//将出现三次的从two中清除
//		}
//		return one;
//	}
//};

//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//		for (int i = 0; i < nums.size(); i += 3) {
//			if (i + 1 >= nums.size() || nums[i + 1] != nums[i]) return nums[i];
//		}
//		return 0;
//	}
//};

//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		unordered_map<int, int> m;
//		for (int i : nums) m[i]++;
//		for (auto i : m) {
//			if (1 == i.second) return i.first;
//		}
//		return 0;
//	}
//};