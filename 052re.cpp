#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <limits.h>
#include <queue>
using namespace std;

int N = 0; // 사람 수
int M = 0; // 파티 수
vector<int> parent(51, 0);
vector<int> knowTruthMem; // 진실을 알고 있는 사람들
vector<int> partyMem;

int find(int a) {
	if (parent[a] == a) {
		return a;
	}

	else {
		return parent[a] = find(parent[a]);
	}
}

void unionAB(int a, int b) {

	parent[find(b)] = parent[find(a)];
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	int num = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int temp = 0;
		cin >> temp;
		knowTruthMem.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int k = 0;
		cin >> k;

		int frontNode = 0;
		cin >> frontNode;
		partyMem.push_back(frontNode);
		for (int j = 1; j < k; j++) {
			int temp = 0;
			cin >> temp;

			unionAB(frontNode, temp);
		}
	}
	int answer = 0;
	for (int i = 0; i < partyMem.size(); i++) {
		
		int cur = partyMem[i];
		bool flag = false;
		for (int j = 0; j < knowTruthMem.size(); j++) {
			if (find(cur) == find(knowTruthMem[j])) {
				flag = true;
				break;
			}
			
		}
		if (flag == false) {
			answer++;
		}
	}
	cout << answer;
	return 0;

}

