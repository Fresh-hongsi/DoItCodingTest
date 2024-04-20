#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <set>
using namespace std;

vector<int> parent(51, 0);
vector<int> knowTruthMember;
vector<vector<int>> partyMember(51, vector<int>(51, 0));

int find(int a) {
	if (a == parent[a]) {
		return a;
	}

	else {
		return parent[a] = find(parent[a]);
	}
}

void unionFunc(int a, int b) {

	int p1 = find(a);
	int p2 = find(b);


	if (p1 != p2) {
		parent[p2] = p1;
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0; // 사람 수
	int M = 0; // 파티 수
	int K = 0; // 진실을 아는 사람 수
	int answer = 0;

	cin >> N >> M >> K;

	parent.resize(N + 1);
	// 대표 노드 집합 초기화
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	// 진실을 알고 있는 사람을 knowTruthMember에 세팅
	for (int i = 0; i < K; i++) {
		int temp = 0;
		cin >> temp;
		knowTruthMember.push_back(temp);
	}

	// 파티와 각 파티원들을 partyMember에 저장
	for (int i = 0; i < M; i++) {
		int num = 0;
		cin >> num;
		partyMember[i].resize(num);

		for (int j = 0; j < num; j++) {
			int temp = 0;
			cin >> temp;
			partyMember[i][j] = temp;
		}
	}

	// 각 파티에 대해 맨 앞에 있는 대표 노드로 union_find 세팅해주기
	for (int i = 0; i < M; i++) {

		int frontNode = partyMember[i][0];
		
		for (int j = 1; j < partyMember[i].size(); j++) {
				unionFunc(frontNode, partyMember[i][j]);
		}
		

	}

	// 각 파티를 순회하며, 각 파티의 대표노드와 knowTruthMember의 find값이 일치하는 경우가 있으면 과장 불가
	for (int i = 0; i < M; i++) {

		bool flag = true;
		int cur = partyMember[i][0];

		for (int j = 0; j < knowTruthMember.size(); j++) {

			if (find(cur) == find(knowTruthMember[j])) {
				flag = false;
				break;
			}
		}

		if (flag == true) {
			answer++;
		}


	}
	cout << answer;
	return 0;
}
