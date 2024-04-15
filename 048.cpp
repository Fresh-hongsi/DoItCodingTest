#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;

int N = 0;
int M = 0;
vector<vector<int>> adjList(10001);
vector<bool> visited(10001, false);
vector<int> answer(10001, 0);

void bfs(int st) {

	queue<int> q;
	visited[st] = true;
	q.push(st);

	while (!q.empty()) {
		int curNode = q.front();
		q.pop();

		for (int k : adjList[curNode]) {
			if (visited[k] == false) {
				visited[k] = true;
				answer[k]++;
				q.push(k);
			}
		}
	}


	
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		
		int start = 0;
		int end = 0;
		cin >> start >> end;

		adjList[start].push_back(end);
	}

	for (int i = 1; i <= N; i++) {
	
		bfs(i);
		visited = vector<bool>(10001, false);
	}

	
	int maximum = *max_element(answer.begin(), answer.end());

	for (int i = 1; i <= N; i++) {
		if (answer[i] == maximum) {
			cout << i << ' ';
		}
	}


	return 0;
}
