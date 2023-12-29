#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
定义一个数组作为桶，将序列中数据放进对应的桶
对非空桶中的数据进行排序（任意sort方法），将排序后的桶拼接起来
*/

void bucket_sort(vector<int> &input) {
	int bucket_size = 10;  //根据需求选取
	int min = input[0];
	int max = input[0];
	for (int i : input) {
		if (i < min) min = i;
		if (i > max) max = i;
	}

	vector<vector<int>> v((max - min) / bucket_size + 1);  //定义bucket
	for (int i : input) {
		v[(i - min) / bucket_size].push_back(i);  //将对应的数据放进bucket
	}
	int k = 0;
	for (auto i : v) {
		if (i.empty()) continue;
		sort(i.begin(), i.end());  //使用任意方法sort每个bucket
		for (int j : i) input[k++] = j;
	}
}

//void main() {
//	vector<int> input = { 78,17,39,26,72,94,21,12,23,68 };
//	bucket_sort(input);
//	for (int i : input) cout << i << endl;
//}