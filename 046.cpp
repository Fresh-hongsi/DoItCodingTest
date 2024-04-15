#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int N = 0;
int K = 0;
int M = 0;
int X = 0;
vector<vector<int>> adjList(300001);
vector<bool> visited(300001, false);
vector<int> answer;

void bfs(int start) {

	queue<pair<int, int>> q;
	visited[start] = true;
	q.push(make_pair(start, 0));

	while (!q.empty()) {
		int curNode = q.front().first;
		int curLength = q.front().second;
		q.pop();

		if (curLength == K) {
			answer.push_back(curNode);
			continue;
		}

		else {
			for (int nextNode : adjList[curNode]) {
				if (visited[nextNode] == false) {
					visited[nextNode] = true;
					q.push(make_pair(nextNode, curLength + 1));
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++) {
		int start = 0;
		int end = 0;
		cin >> start >> end;

		adjList[start].push_back(end);
	}

	bfs(X);

	sort(answer.begin(), answer.end());

	if (answer.size() < 1) {
		cout << -1;
	}
	else {
		for (auto p : answer) {
			cout << p << '\n';
		}
	}

	return 0;
	

}
