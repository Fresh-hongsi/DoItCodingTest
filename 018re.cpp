#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 삽입정렬로 풀이
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> arr;
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;

		arr.push_back(temp);
	}

	// 삽입 정렬 이용
	for (int i = 1; i < N; i++) {

		int cur = arr[i]; // 삽입 정렬할 대상
		int idx = i; // 삽입 대상이 최종적으로 삽입될 인덱스

		for (int j = i - 1; j >= 0; j--) {
			if (cur > arr[j]) {
				idx = j + 1;
				break;
			}

			if (j == 0) {
				idx = 0;
			}
		}

		// 시프트
		for (int j = i; j > idx; j--) {
			arr[j] = arr[j - 1];
		}

		// 삽입
		arr[idx] = cur;
	}

	int result = arr[0];
	for (int i = 1; i < N; i++) {
		arr[i] = arr[i]+arr[i - 1];
		result += arr[i];
	}

	cout << result;
	return 0;



}
