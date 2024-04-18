#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int N = 0;
int M = 0;
vector<int> parent(1000001, 0);


// 집합의 대표 노드 찾기
// 계속 해서 파고 들면서 집합의 우두머리 노드를 찾으면,
// 다시 재귀가 풀리며 돌아올 때 우두머리 노드로 parent 세팅
int find(int a) {
	if (parent[a] == a) {
		return a;
	}

	else {
		return parent[a] = find(parent[a]);
	}
}

void makeUnion(int f, int s) {
	
	f = find(f); // f가 속한 집합의 대표 노드 찾기
	s = find(s); // s가 속한 집합의 대표 노드 찾기

	if (f != s) {
		parent[s] = f; 
	}

}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	// 처음에 각 노드는 자기 자신이 대표가 되어 집합을 형성
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int option = 0;
		int a = 0;
		int b = 0;

		cin >> option >> a >> b;

		if (option == 0) {
			makeUnion(a, b);
		}

		if (option == 1) {
			int first = find(a);
			int second = find(b);

			if (first == second) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}
