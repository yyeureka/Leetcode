#include <vector>
#include <iostream>
using namespace std;

/*
divide and conquer分治法
把输入序列分成两个子序列，对这两个子序列分别采用归并排序
将两个排序好的子序列合并成一个最终的排序序列
*/

void merge_sort(vector<int> &input, int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2;
	merge_sort(input, start, mid);
	merge_sort(input, mid + 1, end);

	vector<int> tmp(input.size());
	int left = start;
	int right = mid + 1;

	for (int i = start; i <= end; i++) {
		if (left > mid) tmp[i] = input[right++];
		else if (right > end) tmp[i] = input[left++];
		else if (input[left] < input[right]) tmp[i] = input[left++];
		else tmp[i] = input[right++];
	}

	for (int i = start; i <= end; i++) {
		input[i] = tmp[i];
	}
}