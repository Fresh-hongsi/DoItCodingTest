#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <string>
using namespace std;

vector<vector<pair<int, int>>> adjList(1000); // 인접리스트
vector<bool> visited(1000, false);// 방문표시 배열
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 우선순위 큐
vector<int> minLength(1000, 0);// 길이저장 배열

void dijkstra(int len, int st) {

	pq.push(make_pair(len, st));
	
	while (!pq.empty()) {
		int curNode = pq.top().second;
		int curLen = pq.top().first; // 현재까지의 최소길이
		pq.pop();

		if (visited[curNode] == true) {
			continue;
		}
		visited[curNode] = true;

		for (pair<int, int> k : adjList[curNode]) {
			int nextLen = k.first;
			int nextNode = k.second;

			if (curLen + nextLen < minLength[nextNode]) {
				minLength[nextNode] = curLen + nextLen;
				pq.push(make_pair(curLen + nextLen, nextNode));
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int M = 0;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int s=0;
		int e=0;
		int v=0;

		cin >> s >> e >> v;

		adjList[s - 1].push_back(make_pair(v, e-1));
	}

	int start = 0;
	int end = 0; 
	cin >> start >> end;
	start -= 1;
	end -= 1;

	for (int i = 0; i < 1000; i++) {
		if (i != start) {
			minLength[i] = 1000000001;
		}
		else {
			minLength[i] = 0;
		}
	}

	dijkstra(0, start);

	//for (auto k : minLength) {
	//	cout << k << '\n';
	//}

	cout << minLength[end];
	return 0;

}
