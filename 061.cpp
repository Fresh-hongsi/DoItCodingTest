#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 플로이드 - 워셜은 시작점,끝점이 아닌 모든 노드와 관련된 최소경로 알고리즘
int max_len = 100000001;
vector<vector<int>> adjMatrix(100, vector<int>(100, max_len)); // 인접 행렬 사용

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0; // 도시 개수
	int M = 0; // 버스 개수
	cin >> N >> M;

	// 자기 자신으로 시작해서 자기 자신으로 오는 경로에 대해서는 0
	for (int i = 0; i < N; i++) {
		adjMatrix[i][i] = 0;
	}

	// 인접행렬 나머지 세팅
	for (int i = 0; i < M; i++) {
		int a = 0;
		int b = 0;
		int c = 0;
		cin >> a >> b >> c;

		adjMatrix[a - 1][b - 1] = min(adjMatrix[a-1][b-1],c);


	}

	// 플로이드 워셜 사용
	for (int k = 0; k < N; k++) { // 중간 경로
		for (int s = 0; s < N; s++) { // 시작점
			for (int e = 0; e < N; e++) { // 끝점
				adjMatrix[s][e] = min(adjMatrix[s][e], adjMatrix[s][k] + adjMatrix[k][e]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (adjMatrix[i][j] == 100000001) {
				cout << 0 << ' ';
			}
			else {
				cout << adjMatrix[i][j] << ' ';
			}
			
		}
		cout << '\n';
	}

	return 0;
}
