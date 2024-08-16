#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

// 플로이드-워셜 사용
vector<vector<int>> adjMatrix(100, vector<int>(100, 999999));
vector<int> baconNum(100, 999999);
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int M = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		adjMatrix[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int s = 0;
		int e = 0;
		cin >> s >> e;

		adjMatrix[s - 1][e - 1] = 1;
		adjMatrix[e - 1][s - 1] = 1;
	}

	for (int k = 0; k < N; k++) {
		for (int s = 0; s < N; s++) {
			for (int e = 0; e < N; e++) {
				adjMatrix[s][e] = min(adjMatrix[s][e],adjMatrix[s][k] + adjMatrix[k][e]);
			}
		}
	}

	// 각 노드 별 베이컨 수 구해서 bacinNum배열에 세팅
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N;j++) {
			sum += adjMatrix[i][j];
		}
		baconNum[i] = sum;
		//cout << "sum" << i << ' ' << sum << '\n';
	}

	// 가장 작은 베이컨 수 찾아서. 해당 베이컨 수 가진 최소번호 노드 찾아 출력
	int min_Num = *min_element(baconNum.begin(), baconNum.end());
	for (int i = 0; i < N; i++) {
		if (baconNum[i] == min_Num) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}

