#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <string>
#include <tuple>
using namespace std;

int V = 0;
int E = 0;
vector<tuple<int, int, long>> eList;
vector<int> parent(10001,0);

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

bool comp(tuple<int, int, long> a, tuple<int, int, long> b) {

	return get<2>(a) < get<2>(b);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E;

	// 유니온 배열 세팅
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	// 간선리스트 세팅
	for (int i = 0; i < E; i++) {
		int s = 0;
		int e = 0;
		long w = 0;
		cin >> s >> e >> w;

		eList.push_back(make_tuple(s, e, w));
	}

	// 그 후 가중치 별 오름차순 설정
	sort(eList.begin(), eList.end(), comp);

	//for (int i = 0; i < E; i++) {
	//	cout << get<0>(eList[i]) << ' ' << get<1>(eList[i]) << ' ' << get<2>(eList[i]) << '\n';
	//}

	int counter = 0;
	int idx = 0;
	long sum = 0;
	while (counter < V - 1) { // 노드 수 -1 개를 찾으면 최소스패닝트리 찾은 것
		int s = get<0>(eList[idx]);
		int e = get<1>(eList[idx]);
		long w = get<2>(eList[idx]);

		if(find(parent[s])!=find(parent[e])) // 부모가 다르다면 유니언
		{
			idx++;
			unionAB(min(s, e), max(s, e));
			counter++;
			sum += w;
		}
		else { // 부모가 같다면 유니언 불허
			idx++;
			continue;
		}
	}
	
	cout << sum;
	return 0;
}
