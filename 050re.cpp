#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <limits.h>
#include <math.h>
using namespace std;

vector<int> parent(1000001, 0);

int find(int k) {

	if (k == parent[k]) {
		return k;
	}

	else {
		return parent[k] = find(parent[k]); // 이 부분이 시간 복잡도 줄인다!
	}
}

void unionAB(int a, int b) {

	parent[find(b)] = parent[find(a)];
}



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0; // 원소 개수
	int M = 0; // 질의 개수
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int queryType = 0;
		int a = 0;
		int b = 0;

		cin >> queryType >> a >> b;

		if (queryType == 0) {

			
			unionAB(min(a,b), max(a,b));
		}

		if (queryType == 1) {
			int first = find(a);
			int second = find(b);

			if (first == second) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}

}

// 1 2 3 4 5 6 7
// 1 2 1 2 5 1 6

//1 3
//2
//4 
//5
// 7
