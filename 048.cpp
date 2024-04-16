#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#define Blue 2
#define Red 3
using namespace std;


vector<vector<int>> adjList(20001);
int K = 0;
int V = 0;
int E = 0;
vector<int> visited(20001, 0);
//vector<bool> visited(20001, false);
//vector<char> color(20001, 'W');


//bool BFS(int st) {
//	queue<pair<int, char>> q;
//	visited[st] = true;
//	q.push(make_pair(st, 'B'));
//	bool f = true;
//
//	while (!q.empty()) {
//		int curNode = q.front().first;
//		char curColor = q.front().second;
//		q.pop();
//		char nextColor;
//		if(curColor=='W'){
//			nextColor = 'B';
//		}
//		if (curColor == 'B') {
//			nextColor = 'R';
//		}
//		if (curColor == 'R') {
//			nextColor = 'B';
//		}
//
//		for (auto m : adjList[curNode]) {
//			if (color[m] == 'W') {
//				color[m] = nextColor;
//				q.push(make_pair(m, nextColor));
//			}
//			else {
//				if (color[m] != nextColor) {
//					f = false;
//					break;
//				}
//			}
//		}
//	}
//
//	return f;
//}


void DFS(int cur) {

	if (visited[cur] == 0) { // 방문 안했으면 빨간색으로
		visited[cur] = 2;
	}

	for (auto n : adjList[cur]) {
		
		if (visited[n] == 0) { // 다음 노드 방문 안했다면
			if (visited[cur] == 2) { // 현재 노드 빨간색이면
				visited[n] = 3; // 다음 노드 파란색
			}

			else if (visited[cur] == 3) { // 현재 노드 파란색이면
				visited[n] = 2; // 다음 노느 빨간색
			}

			DFS(n);
		}

		
	}
}

bool check() {

	bool flag = true;
	for (int i = 1; i <= V; i++) {

		for (auto n : adjList[i]) {
			if (visited[i] == visited[n]) {
				return false;
			}
		}
	}
	return flag;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> K;

	while (K--) {
		cin >> V >> E;
		int flag = true;
		for (int i = 0; i < E; i++) {
			int start = 0;
			int end = 0;
			cin >> start >> end;

			adjList[start].push_back(end);
			adjList[end].push_back(start);
		}

		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0) {
				DFS(i);

			}
		}

		bool c = check();
		if (c == true) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		visited = vector<int>(20001, 0);
		adjList = vector<vector<int>>(20001);
		/*color = vector<char>(20001, 'W');*/


		/*for (int i = 1; i <= V; i++) {

			if (color[i] == 'W') {
				flag = BFS(i);
				if (flag == false) {
					cout << "NO\n";
					break;
				}
			}
			
		}
		if (flag == true) {
			cout << "YES\n";
		}

		visited = vector<bool>(20001, false);
		adjList = vector<vector<int>>(20001);
		color = vector<char>(20001, 'W');*/
	}

	return 0;
}
