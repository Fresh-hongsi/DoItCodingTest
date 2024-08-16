#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> adjList(501);
vector<int> result(501,0);
vector<int> selfBuild(501,0);
vector<int> inDegree(501, 0);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int time = 0;
		cin >> time;

		selfBuild[i] = time;
		while (1) {
			int temp = 0;
			cin >> temp;
			if (temp == -1) {
				break;
			}
			adjList[temp].push_back(i);
			inDegree[i]++;
			
		}

	}


	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto k : adjList[cur]) {
			
			result[k] = max(result[k], result[cur] + selfBuild[cur]);
			inDegree[k]--;
			if (inDegree[k] == 0) {
				q.push(k);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << result[i]+selfBuild[i] << '\n';
	}
	return 0;
}





