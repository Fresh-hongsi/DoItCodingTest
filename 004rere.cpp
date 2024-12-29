#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int M = 0;

	cin >> N >> M;

	vector<vector<int>> v(1025, vector<int>(1025, 0));
	vector<vector<int>> vSum(1025, vector<int>(1025, 0));

	// 일반 벡터 입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp = 0;
			cin >> temp;
			v[i][j] = temp;
		}
	}


	// 구간합 배열 세팅
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vSum[i][j] = vSum[i - 1][j] + vSum[i][j - 1] + v[i][j] - vSum[i - 1][j - 1];
		}
	}
	// 입력에 대한 구간합 구하기
	for (int i = 0; i < M; i++) {
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		cin >> a >> b >> c >> d;

		int result = vSum[c][d] + vSum[a - 1][b - 1] - vSum[c][b - 1] - vSum[a - 1][d];

		cout << result << '\n';
	}
	return 0;
}
