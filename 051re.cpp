#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <limits.h>
#include <queue>
using namespace std;
// BFS 풀이
int N = 0;
int M = 0;
bool visited[200] = { false, };
bool group[200] = { 0, };
int counter = 0;
vector<vector<int>> adjList(200);

void bfs(int start) {
	visited[start] = true;
	group[start] = counter;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto k : adjList[cur]) {
			if (visited[k] != true) {
				visited[k] = true;
				group[k] = counter;
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

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp = 0;
			cin >> temp;

			if (temp == 1) {
				adjList[i].push_back(j);
			}

		}
	}

	
	for (int i = 0; i < N; i++) {
	
		if (visited[i] == false) {
			bfs(i);
			counter++;
		}
	}

	int g = 0;
	cin >> g;
	g = group[g - 1];
	bool flag = true;
	for (int i = 1; i < M; i++)
	{
		int temp = 0;
		cin >> temp;

		if (g != group[temp - 1]) {
			cout << "NO";
			flag = false;
			break;
		}
	}

	if (flag == true) {
		cout << "YES";
	}
	return 0;
}
