#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <functional>
using namespace std;

// dp 중요 예제!

int N = 0;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	cin >> N;
	vector<int> A(N, 0); // 배열 
	vector<int> L(N, 0); // 좌측부터 접근
	vector<int> R(N, 0); // 우측부터 접근


	for (int i = 0; i <N; i++) {
		int temp = 0;
		cin >> temp;

		A[i] = temp;
	}

	// 좌측부터 시작했을 때 
	L[0] = A[0];
	int result = L[0];

	for (int i = 1; i < N; i++) {
		L[i] = max(A[i], L[i - 1] + A[i]);

		//하나도 제거하지 않았을 때를 기본 최댓값으로 저장
		result = max(result, L[i]);
	}

	// 우측부터 시작했을 때
	R[N-1] = A[N-1];

	for (int i = N-2; i >= 0; i--) {
		R[i] = max(A[i], R[i + 1] + A[i]);
	}


	//i = 1이나 i = N일 때는 배열의 첫 번째 또는 마지막 요소를 제거하는 경우입니다.이때의 최대 부분합 계산이 의미가 없는 이유는, 문제의 조건이 "어떤 하나의 요소를 제거했을 때 최대 부분합을 구하라"는 것이기 때문입니다.
	//
	//자세한 이유 :
	//첫 번째 요소 제거(i = 1)
	//
	//첫 번째 요소를 제거하면 부분합은 두 번째 요소부터 시작하게 됩니다.이 경우에는 사실상 L[1] + R[2]를 계산하는 것과 다름없어 새로운 값이 되지 않습니다.
	//마지막 요소 제거(i = N)
	//
	//마지막 요소를 제거하면 마지막 전 요소까지의 부분합만 남습니다.이는 사실상 L[N - 1]와 같은 의미이므로, 특별히 새로운 조합이 추가되는 것이 아닙니다.
	//따라서 첫 번째와 마지막 요소를 제거하는 경우는 기본 L 또는 R 값에 포함되므로 중복 계산이 됩니다.

	for (int i = 1; i < N-1; i++) {
		int temp = L[i - 1] + R[i + 1];
		result = max(result, temp);
	}

	cout << result<<'\n';



	return 0;
}
