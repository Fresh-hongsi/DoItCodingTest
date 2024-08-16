#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int max_len = 999;
vector<vector<int>> adjMatrix(100, vector<int>(100, max_len)); // 인접 행렬


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	// 인접행렬 입력받음(이때, 두 노드 간에 길이 있다면 노드 간 길이를 모두 1로 함)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp = 0;
			cin >> temp;
			if (temp == 1) {
				adjMatrix[i][j] = 1;
			}
		}
	}

	// 플로이드-워셜 시작 -> 만약 길이 있다면 무한대에서 특정 길이 값으로 업데이트
	for (int k = 0; k < N; k++) {
		for (int s = 0; s < N; s++) {
			for (int e = 0; e < N; e++) {
				adjMatrix[s][e] = min(adjMatrix[s][e], adjMatrix[s][k] + adjMatrix[k][e]);
			}
		}
	}

	// 길이 무한대가 아니라면 길이 있다는 것이므로 1, 길이가 무한대라면 길이 없다는 뜻이므로 0
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (adjMatrix[i][j] != max_len) {
				cout << 1 << ' ';
			}
			else {
				cout << 0 << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
