#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr; // 정렬할 배열
vector<int> temp(1000001, 0); // 임시 배열
long result = 0; // 총 swap 개수

void merge_sort(int s, int e) {
	if (e - s < 1) {
		return;
	}

	int m = s + (e - s) / 2;

	merge_sort(s, m);
	merge_sort(m + 1, e);

	// 재귀 타고 넘어오면 여기서부터 정렬

	// 임시배열에 갖고오기
	for (int i = s; i <= e; i++) {
		temp[i] = arr[i];
	}
	int index1 = s;
	int index2 = m + 1;
	int k = s;

	while (index1 <= m && index2 <= e) {

		// 앞 배열에 있는 게 큰 경우
		if (temp[index1] > temp[index2]) {
			
			arr[k] = temp[index2];
			result += (index2 - k); // 뒤에서 얼마나 앞으로 가야하는 지 계산

			k++;
			index2++;
		}

		// 뒷 배열에 있는 게 앞보다 크거나 같은 경우
		else {
			arr[k] = temp[index1];

			k++;
			index1++;
		}

		
	}

	// 인덱스 끝까지 못간 값들 배열에 넣어주기
	while (index1 <= m) {
		arr[k] = temp[index1];
		k++;
		index1++;
	}

	while (index2 <= e) {
		arr[k] = temp[index2];
		k++;
		index2++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t = 0;
		cin >> t;

		arr.push_back(t);
	}

	merge_sort(0, N - 1);
	cout << result<<'\n';

	return 0;



}
