#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
#include <limits.h>
using namespace std;

int main(void) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int M = 0;

	cin >> N >> M;
	vector<vector<int>> adjList(32001);
	vector<int> arr(32001, 0);

	for (int i = 0; i < M; i++) {
		int a = 0;
		int b = 0;
		cin >> a >> b;
		adjList[a].push_back(b);
		arr[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			q.push(i);
			cout << i<<' ';
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto k : adjList[cur]) {
			arr[k]--;
			if (arr[k] == 0) {
				q.push(k);
				cout << k << ' ';
			}
		}
	}




	return 0;
}

//1 - 3
//2 - 3
//3 -
//
//1 2 3 
//0 0 2
//
//1 - 
//2 -
//3 - 1
//4 - 2
//
//1 2 3 4
//1 1 0 0
//
//3 4
