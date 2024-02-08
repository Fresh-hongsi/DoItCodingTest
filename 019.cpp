#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void swap(vector<int>& a, int i, int j)
{
	int temp = a[j];
	a[j] = a[i];
	a[i] = temp;
	return;
}

int partition(vector<int>& a, int S, int E) {

	// 배열의 size가 2라면 그냥 정렬해서 반환
	if (S + 1 == E) {
		if (a[S] > a[E]) {
			swap(a, S, E);
		}

		return E;
	}

	// 그게 아니라면 피봇의 위치를 잡아줘야함
	int M = (S + E) / 2; // 우선 피봇의 인덱스를 가운데 위치를 잡아주고,
	swap(a, S, M); // 인덱스 관리 편하게 잡은 피봇과 s번째 인덱스의 값을 swap

	int pivotVal = a[S];
	int i = S + 1;
	int j = E;

	while (i <= j) {

		while (pivotVal < a[j] && j>=S+1) { // 현재 피봇보다 작은 수가 나올 때까지 j--
			j--;
		}
		while (pivotVal > a[i] && i <= E) { // 현재 피봇보다 큰 수가 나올 때까지 i++
			i++;
		}

		if (i <= j) {
			swap(a, i++, j--);
		}
	}

	a[S] = a[j];
	a[j] = pivotVal;
	return j;


}

void quickSort(vector<int>& a, int S, int E, int idx) {

	int pivot = partition(a, S, E); // 현재 피봇의 인덱스 구하기

	if (idx==pivot) { // 피봇 == index라면, K번째 수의 위치를 찾은 것

		return;
	}

	else if (idx<pivot) { // index<pivot이라면, s~pivot-1의 인덱스에 대해 다시 찾아봐야함
		quickSort(a, S, pivot - 1, idx);
	}

	else {
		quickSort(a, pivot + 1, E, idx); // index>pivot이라면 pivot+1~e의 인덱스에 대해 다시 찾아봐야함
	}
}





int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int K = 0;

	cin >> N >> K;

	vector<int> arr;

	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;

		arr.push_back(temp);
	}

	// 퀵 정렬 적용
	quickSort(arr, 0, N - 1, K - 1);
	cout << arr[K - 1]; // k번째 수 출력

	return 0;
}
