#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;


int N = 0;
vector<vector<int>> adjList(100001); // 양방향 인접리스트
vector<bool> visited(100001, false); // 방문표시 배열
vector<int> parent(100001, 0); // 각 정점의 부모 정점 값 저장

void dfs(int cur) {

	
	visited[cur] = true;
	for (auto k : adjList[cur]) {
		if (visited[k] == false) {
			visited[k] = true; // 방문표시
			parent[k] = cur;
			dfs(k);
		}
	}
	
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> N;

	// 양방향 인접리스트 세팅
	for (int i = 1; i <= N - 1; i++) {
		int st = 0;
		int end = 0;

		cin >> st >> end;

		adjList[st].push_back(end);
		adjList[end].push_back(st);
	}

	// 루트 노드 1번에서 dfs 스타트
	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

	return 0;

}


