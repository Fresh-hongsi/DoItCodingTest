#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

// 위상 정렬 사용

vector<vector<pair<int, int>>> A(10001); // 정방향 인접리스트
vector<vector<pair<int, int>>> reverseA(10001); // 역방향 인접리스트
vector<int> inDegree(10001, 0); // 진입차수 배열
vector<int> result(10001, 0); // 임계 경로 배열
vector<int> visited(10001, 0); // 역방향 인접리스트 통해 1분도 쉬지 않고 달려야하는 도로 수 구할 떄 사용할 방문표시 배열
int city = 0; // 도시 수
int route = 0; // 길 수
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> city >> route;

	A.resize(city + 1);
	reverseA.resize(city + 1);
	inDegree.resize(city + 1);
	result.resize(city + 1);
	visited.resize(city + 1);

	for (int i = 0; i < route; i++) {
		int start = 0;
		int end = 0;
		int val = 0;
		cin >> start >> end >> val;

		A[start].push_back(make_pair(end, val)); // 정방향 인접리스트 세잍
		reverseA[end].push_back(make_pair(start, val)); // 역방향 인접리스트 세팅
		inDegree[end]++; // 진입 차수 세팅
	}

	
	int startDosi = 0; // 시작점 도시
	int endDosi = 0; // 도착점 도시

	cin >> startDosi >> endDosi;

	queue<int> q1; // 모든 사람이 만나는 시간을 구하기 위한 큐 세팅
	q1.push(startDosi);

	// 위상정렬 시도 통해 모든 사람이 도착지에 도착할 수 있는 시간을 구함
	while (!q1.empty()) {
		int cur = q1.front();
		q1.pop();

		for (auto next : A[cur]) {
			inDegree[next.first]--;
			result[next.first] = max(result[next.first], result[cur] + next.second);

			if (inDegree[next.first] == 0) {
				q1.push(next.first);
			}

		}
	}

	// 이제 1분도 쉬지 않고 달려야 하는 도로의 수 구하기 - 역방향 인접리스트 사용
	queue<int> q2; // 1분도 쉬지 않고 달려야 하는 도로의 수 구하기 위한 큐
	int resultCount = 0; // 1분도 쉬지 않고 달려야 하는 도로의 수
	q2.push(endDosi);
	visited[endDosi] = true;
	while (!q2.empty()) {
		int cur = q2.front();
		q2.pop();

		for (auto next : reverseA[cur]) {
			if (result[cur] == result[next.first] + next.second) {

				resultCount++;

				if (visited[next.first] == false) { // 큐에 중복 삽입되는 것 방지
					visited[next.first] = true;
					q2.push(next.first);
					
				}
			}
		}
	}

	cout << result[endDosi] << '\n' << resultCount;
	return 0;

}
