#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adjMatrix;
vector<bool> visited(1001, false);
int N = 0;
int M = 0;
int V = 0;

void dfs(int v) {

	// 이미 와본 곳이라면 return
	if (visited[v] == true) {
		return;
	}

	// 방문 표시
	visited[v] = true;
	cout << v << ' ';

	// 다음 방문할 곳 찾아서 dfs 시도
	for (auto next : adjMatrix[v]) {

		dfs(next);
	}

}

void bfs(int v) {

	queue<int> q;
	visited[v] = true; // 시작 정점 방문표시
	q.push(v); // 우선 시작 정점 넣어주기

	while (!q.empty()) {

		int cur = q.front();
		cout << cur << ' ';
		q.pop();

		for (auto next : adjMatrix[cur]) {
			if (visited[next] == false) {

				visited[next] = true;
				q.push(next);
			}
		}
	}
	



}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> V;

	adjMatrix.resize(N + 1);

	// 인접리스트 세팅
	for (int i = 0; i < M; i++) {
		int s = 0;
		int e = 0;

		cin >> s >> e;

		adjMatrix[s].push_back(e);
		adjMatrix[e].push_back(s);

	}

	// 정렬
	for (int i = 1; i <= N; i++) {
		sort(adjMatrix[i].begin(), adjMatrix[i].end());
	}

	dfs(V);
	
	visited = vector<bool>(1001, false); // 방문 표시 배열 초기화
	cout << '\n';
	bfs(V);


	return 0;





}
