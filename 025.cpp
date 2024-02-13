#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<bool> visited(2001, false);
vector<vector<int>> adjMatrix;
bool flag = false;

void dfs(pair<int, int> cur) {

	// 만약 이미 방문된 정점이라면 더 dfs할 수 없음
	if (visited[cur.first] == true) {
		return;
	}

	// 방문한 적 없는 정점이라면
	else {

		visited[cur.first] = true; // 방문표시 해주기

		// 만약 관계를 모두 다 찾았다면
		if (cur.second == 5) {
			flag = true; // 관계 찾음 표시
			return; // 더 dfs할 필요 없으므로 종결

		}
		
		// 다음 dfs 세팅 후 호출
		for (auto v : adjMatrix[cur.first]) {
			
			dfs(make_pair(v, cur.second + 1));
			
			if (flag == true) {
				return;
			}
		}

		// 만약 해당 정점에서 다 돌아봤는데 가능한 게 없다면
		// 지금 정점을 방문표시 취소 하고 이전 재귀로 돌아가기
		visited[cur.first] = false;
	}
	




}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V = 0;
	int E = 0;

	cin >> V >> E;

	adjMatrix.resize(V);

	// 인접리스트 세팅
	for (int i = 0; i < E; i++) {

		int s = 0;
		int e = 0;
		cin >> s >> e;
		adjMatrix[s].push_back(e);
		adjMatrix[e].push_back(s);
	}

	for (int i = 0; i < V; i++) {

		visited = vector<bool>(2001, false); // 방문표시 초기화
		int start = i;
		dfs(make_pair(i, 1));

		if (flag == true)
		{
			cout << "1";
			break;
		}
		
	}

	if (flag == false) {
		cout << "0";
	}
	
	return 0;





}
