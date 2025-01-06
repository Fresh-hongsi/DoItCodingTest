#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

vector<long long> arr(1000001,0);
vector<long long> arr2(1001, 0);
long long N = 0;
long long M = 0;
long long answer = 0;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	// 구간합 구하기
	long long temp = 0;
	cin >> temp;
	arr[0] = temp;
	for (int i = 1; i < N; i++) {
		
		cin >> temp;
		arr[i] = arr[i-1]+temp;
	}


	// 나머지를 활용한 연산
	for (int i = 0; i < N; i++) {
		arr[i] = arr[i] % M; 
		arr2[arr[i]]++; // 해당 나머지인 수에 대해 개수 더해주기
		if (arr[i] == 0) { // 첫번째 구간 합에 바로 m으로 나누어떨어지는 경우 답 개수에 추가
			answer++;
		}
	}

	// 같은 나머지인 것들에 대해 nC2 수행 후 답 개수에 추가
	for (int i = 0; i < M; i++) {
		answer += (arr2[i] * (arr2[i] - 1)) / 2;
	}

	cout << answer;



	



	return 0;
}

