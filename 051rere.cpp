#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <limits.h>
#include <queue>
using namespace std;

// union-find 풀이
int N = 0;
int M = 0;
vector<int> parent(200, 0);

int find(int k) {

	if (k == parent[k]) {
		return k;
	}

	else {
		return parent[k] = find(parent[k]);
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

	for (int i = 0; i < parent.size(); i++){
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp = 0;
			cin >> temp;

			if (temp == 1) {
				unionAB(min(i, j), max(i, j));
			}

		}
	}




	int g = 0;
	cin >> g;
	g = find(parent[g - 1]);
	bool flag = true;
	for (int i = 1; i < M; i++)
	{
		int temp = 0;
		cin >> temp;

		if (g != find(parent[temp - 1])) {
			cout << "NO";
			flag = false;
			break;
		}
	}

	if (flag == true) {
		cout << "YES";
	}
	return 0;
}
