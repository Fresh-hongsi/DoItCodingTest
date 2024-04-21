#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue> // 위상정렬에 큐 사용
using namespace std;

int N = 0;
int M = 0;
vector<vector<int>> adjList(32001); // 인접리스트
vector<int> inDegree(32001, 0); // 각 노드에 대한 진입차수 배열
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int start=0;
		int end = 0;

		cin >> start >> end;
		adjList[start].push_back(end);
		inDegree[end]++;
	}

	queue<int> q;

	// 진입 차수가 0인 노드들 큐에 삽입해두기
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	// 큐가 빌 때까지 수행
	while (!q.empty()) {
		int cur = q.front();
		cout << cur<<' ';
		q.pop();
		for (auto k : adjList[cur]) { // 현재 노드랑 연결되어있는 노드에 대한 진입 차수 1씩 감소시키기, 만약 0이 되면 큐에 해당 노드 삽입
			inDegree[k]--;
			if (inDegree[k] == 0) {
				q.push(k);
			}
		}

	}

	return 0;

}
