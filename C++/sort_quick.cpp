#include <vector>
#include <iostream>
using namespace std;

/*
left定为pivot，将小于pivot的放在pivot左边，else放在pivot的右边
并对pivot的左边和右边分别做quick sort（不包括pivot）
*/

void partition(vector<int> &input, int left, int right) {
	if (left >= right) return;

	int i = left;
	int j = right;
	int pivot = input[(left + right) / 2];

	while (i <= j) {
		while (i <= j && input[i] < pivot) i++;
		while (i <= j && input[j] > pivot) j--;
		
		if (i <= j) swap(input[i++], input[j--]);
	}

	partition(input, left, j);
	partition(input, i, right);
}

void quick_sort(vector<int> &input) {
	partition(input, 0, input.size() - 1);
}

//void main() {
//	vector<int> input = { 5,1,4,2,8 };
//	quick_sort(input);
//	for (int i : input) cout << i << endl;
//}