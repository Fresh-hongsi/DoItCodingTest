#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> temp(1000001, 0);

void merge_sort(int s, int e) {

	if (e - s < 1) // 가장 작은 부분까지 쪼개졌음
	{
		return;
	}

	// 그게 아니라면, 부분으로 더 쪼개기
	int m = s + ((e - s) / 2);

	merge_sort(s, m);
	merge_sort(m + 1, e);

	// 여기서부턴 병합하는 과정(두 배열을 병합하며 정렬하기)

	// 임시배열을 원래 배열에서 받아옴
	for (int i = s; i <= e; i++) {
		temp[i]=arr[i];
	}

	int index1 = s; // 앞 배열의 시작 인덱스
	int index2 = m + 1; // 뒷 배열의 시작 인덱스
	int k = s; // 병합완료 값을 저장할 배열의 시작 인덱스


	// 어느 한쪽 배열의 끝 인덱스에 도달할때까지 반복
	while (index1 <= m && index2 <= e) {

		// 뒷 배열의 값이 더 큰 경우
		if (temp[index1] < temp[index2]) {
			
			arr[k] = temp[index1]; // 앞배열의 값을 저장하기
			k++;
			index1++; // 앞배열은 다음 인덱스 가리킴

		}

		// 앞 배열의 값이 더 큰 경우
		else {
			arr[k] = temp[index2]; // 뒷배열의 값을 저장하기
			k++;
			index2++; // 뒷 배열은 다음 인덱스 가리킴
		}

		
		// 한쪽이 끝에 도달했으므로, 끝까지 도달하지 못한 것에 대해 배열에 넣어주기

		if (index1 > m) { // 앞배열이 끝에 도달 -> 뒷배열을 옮겨주기

			while (index2 <= e) {
				arr[k] = temp[index2];
				k++;
				index2++;
			}
		}

		if (index2 > e) { // 뒷배열이 끝에 도달 -> 앞배열을 옮겨주기

			while (index1 <= m) {
				arr[k] = temp[index1];
				k++;
				index1++;
			}
		}
	}

	


}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 병합정렬 이용
	int N = 0;
	cin >> N;

	

	// 입력
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;

		arr.push_back(temp);
	}

	// 병합정렬 시작
	merge_sort(0, N - 1);

	// 출력
	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}

	return 0;

}
