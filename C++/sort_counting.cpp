#include <vector>
#include <iostream>
using namespace std;

/*

*/

void counting_sort(vector<int> &input, int max) {
	vector<int> v(max, 0);
	for (int i : input) v[i - 1]++;
	int j = 0;
	for (int i = 0; i < max; i++) {
		while (v[i]-- > 0) input[j++] = i + 1;
	}
}

//void main() {
//	vector<int> input = { 5,1,4,2,8 };
//	counting_sort(input, 8);
//	for (int i : input) cout << i << endl;
//}