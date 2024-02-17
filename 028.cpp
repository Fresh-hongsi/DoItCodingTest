#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 아이디어: 임의의 노드에서 가장 긴 경로로 연결된 노드는 트리의 지름에 해당하는 두 노드 중 하나이다. 
// BFS로 풀이

int N = 0; // 정점의 개수
vector<vector<pair<int, int>>> adjMatrix(100001); // 인접리스트
vector<bool> visited(100001,false); // 방문 표시 배열
vector<int> dist(100001, 0); // 기준 정점으로부터 각 정점까지의 길이 저장
int result = 0;

void BFS(int start) {

	queue<int> q;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {

		int cur = q.front(); // 현재 정점
		int r = dist[cur]; // 현재 정점까지의 거리 가져옴
		q.pop();


		for (auto n : adjMatrix[cur])
		{
			if (visited[n.first] == false) { // 다음 정점이 아직 방문되지 않은 곳이라면

				int next = n.first; // 다음 정점 번호
				int val = n.second; // 현재 정점과 다음 정점 사이의 거리

				visited[next] = true; // 다음 정점 방문표시
				dist[next] = r+val; // 기준정점부터 next정점까지의 거리세팅
				q.push(next); // 큐에 push
			}
			
		}




	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	// 인접리스트 세팅
	for (int i = 0; i < N; i++) {

		int s=0;
		int e = 0;
		int l = 0;
		cin >> s;

		while (1) {
			cin >> e;
			if (e == -1) {
				break;
			}
			else {
				cin >> l;
			}

			adjMatrix[s].push_back(make_pair(e, l));
		}
		
	}

	// bfs 시도
	
	BFS(1); // 임의의 정점(기준 정점)에서 가장 거리가 먼 정점을 찾기 위해 bfs시도
	int maxIndex = 0; // 기준정점으로부터 가장 먼 정점 인덱스
	int maxResult = 0; // 기준정점으로부터 가장 먼 정점까지의 길이
	for (int i = 1; i <= N; i++) {
		if (dist[i] > maxResult) {
			maxResult = dist[i];
			maxIndex = i;
		}
	}
	

	// 찾은 가장 먼 정점에서부터 다시 dfs하기 위한 초기화
	visited = vector<bool>(100001, false);
	dist = vector<int> (100001, 0);
	
	BFS(maxIndex); 
	int max2Index = 0; // maxIndex에 있는 정점으로부터 가장 먼 정점 인덱스
	int max2Result = 0; // maxIndex에 있는 정점으로부터 가장 먼 정점까지의 길이
	for (int i = 1; i <= N; i++) {
		if (dist[i] > max2Result) {
			max2Result = dist[i];
			max2Index = i;
		}
	}

	// 가장 길이가 먼 distance값이 트리의 지름
	cout << max2Result;
	return 0;



}
