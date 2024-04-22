#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
// 위상 정렬 사용

int N = 0; // 건물 개수
vector<int> inDegree(501, 0); //진입 차수 배열
vector<vector<int>> adjList(501); // 인접리스트
vector<int> selfBuild(501, 0); // 각 건물 자체를 짓는데 걸리는 시간
vector<int> answer(501, 0); // 각 건물이 완성되기까지 걸리는 최소 시간 정답 배열

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int end = i;
		int val = 0;
		cin >> val;
		selfBuild[end] = val; // 건물 짓는 데 걸리는 시간 입력받음

		int start = 0;
		while (start != -1) {
			cin >> start;
			if (start == -1) {
				break;
			}
			else {
				adjList[start].push_back(end); // 인접리스트 세팅
				inDegree[end]++; // 진입 차수 세팅
			}
		}
	}

	queue<int> q;
	// 위상 정렬 시도
	// 진입 차수가 0인 것을 큐에 넣어두기
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	// 위상정렬 시도
	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (auto k : adjList[cur]) {

			// 말이 최솟값이지, min이 아니라 max임을 주의하자
			// 모든 테크 트리를 수용할 수 있는 최솟값을 찾아야하는 것이므로,
			// 기존 건물 테크트리 시간보다 더 큰 시간이 들면 그걸 answer로 두어야함
			answer[k] = max(answer[k], answer[cur] + selfBuild[cur]);
			inDegree[k]--;
			if (inDegree[k] == 0) {
				q.push(k);
			}
		}
	}

	// 자기 건물 짓는 데 걸리는 시간을 answer에 각각 더해주기
	for (int i = 1; i <= N; i++) {
		answer[i] += selfBuild[i];
		cout << answer[i] << '\n';
	}

	return 0;
	

}

//1 2 3 4 5
//0 1 1 2 1


