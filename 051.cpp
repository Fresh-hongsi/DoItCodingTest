#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

int N = 0;
int M = 0;
vector<int> parent(201, 0); // 각 노드의 부모 저장
vector<int> path(1001,0); // 여행할 도시 배열

int find(int a) {

	if (a == parent[a]) {
		return a;
	}

	else {
		return parent[a] = find(parent[a]);
	}
}

void makeUnion(int a, int b) {

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

	cin >> N >> M;

	// 최초에 각 집합의 대표 노드는 자기 자신임
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp = 0;
			cin >> temp;

			if (temp == 1) {
				// 만약 연결되어있으면 union 수행
				makeUnion(i, j);
				
			}
		}
	}

	// 여행할 도시 입력받음
	for (int i = 0; i < M; i++) {
		int temp = 0;
		cin >> temp;
		path[i]=temp;
	}

	int firstNode = path[0];
	int representNode = parent[firstNode];
	bool flag = true;
	
	// 모든 여행 경로에 대해 같은 대표 부모를 갖고 있으면 같은 집합에 속해있는 것이고, 그렇다면 여행할 수 있는 경로임
	for (int i = 1; i < M; i++) {
		
		if (representNode != find(path[i])) { // 이 부분 중요!!! parent[path[i]]가 아니라 find(path[i])다! 왜냐하면 parent에 들어있는 게 집합의 대표라 할 수 없기 때문이다
			cout << "NO\n";
			flag = false;
			break;
		}

	}

	if (flag == true) {
		cout << "YES\n";
	}

	return 0;

}
