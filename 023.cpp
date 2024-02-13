#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> A; // 인접리스트
vector<bool> visited; // 방문표시 배열

void dfs(int k) {

	if (visited[k] == true) // 이미 방문된 곳이라면 더 팔 필요없이 return
	{
		return;
	}

	// 그게 아니라면 방문표시하고, 더 파보기
	visited[k] = true;

	for (auto v : A[k]) {
		
		dfs(v);
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int N = 0; // 정점 개수
	int M = 0; // 간선 개수

	cin >> N >> M;

	A.resize(N + 1); 
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++) {
		int s = 0;
		int e = 0;

		cin >> s >> e;

		// 인접리스트 세팅(양방향 간선)
		A[s].push_back(e);
		A[e].push_back(s);
	}

	int result = 0;

	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			dfs(i);
			result++;
		}
	}

	cout << result << '\n';
	return 0;
}
