#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int N = 0;
vector<vector<int>> adjList(50); // 양방향 인접리스트
int root = 0; // 루트 정점
int target = 0; // 타겟 정점
int result = 0; // 최종 리프노드 개수
vector<bool> visited(50, false); // 방문 표시 배열

void dfs(int cur) {
	
	int counter = 0;
	for (auto k : adjList[cur]) {
		if (visited[k] == false && k!=target) { // target이 아니고, 방문되지 않았다면 dfs 시도
			counter++;
			visited[k] = true;
			dfs(k);
		}
	}

	if (counter == 0) { // 만약 더 갈 곳이 없다면 리프노드
		result++;
	}
	
}



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;


		if (temp == -1) {
			root = i; // 루트 정점 세팅
		}
		else {
			adjList[i].push_back(temp);
			adjList[temp].push_back(i);
		}

	}
	
	
	cin >> target;

	if (root == target) { // root와 target이 같다면 리프노드는 0개
		result = 0;
	}
	else { // 그 외의 경우 탐색 시작
		visited[root] = true;
		dfs(root);
	}
	
	cout << result;

	return 0;

}

//0 1 2 3 4 5 6 7 8
//  0 0 2 2 4 4 6 6
//
//
//1
