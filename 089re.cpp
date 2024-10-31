#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	vector<int> arr(N, 0);
	vector<int> left(N, 0);
	vector<int> right(N, 0);
	int result = 0;

	// 입력
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;

		arr[i] = temp;
	}

	// 좌측부터 연속하는 가장 큰 누적값 찾아보기(수 제거 없이)
	// 10 6 9 10 15 21 -14 12 33 32
	left[0] = arr[0];
	result = arr[0];

	for (int i = 1; i < N; i++) {
		left[i] = max(arr[i], left[i - 1] + arr[i]);
		result = max(result, left[i]); // 최댓값도 갱신해가기
	}

	// 우측부터 연속하는 가장 큰 누적값 찾아보기(수 제거 없이)
	//  21 11 15 12 11 6 -2 33 21 -1
	right[N - 1] = arr[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		right[i] = max(right[i + 1] + arr[i], arr[i]);
	}

	// 하나 뺀 값 중 뭐가 가장 큰 지 확인하기
	// 어차피 가장 앞 항과 가장 뒷 항의 경우엔, 만약 빼는 개 더 나았으면 애초에 위의 로직에서 갱신되었을 것이기 때문에
	// 2번째 항부터 N-1번째 항까지만 빼보고, 기존에 구했던 result보다 커지는 경우 갱신해가면 됨
	for (int i = 1; i < N - 1; i++) {
		result = max(result, left[i - 1] + right[i + 1]);
	}
	

	cout << result;
	return 0;
	
}
