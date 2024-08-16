#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <limits.h>
using namespace std;

typedef tuple<int, int, long> edge; // 간선 정보 자료구조 (s,e,v)
vector<edge> eList; // 간선 리스트
vector<long> min_length(500, LONG_MAX); // 최단 경로 저장 배열

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0; // 도시 개수
	int M = 0; // 버스 노선 개수

	cin >> N >> M;

	// 간선 리스트 세팅
	for (int i = 0; i < M; i++) {
		int s = 0;
		int e = 0;
		long v = 0;
		cin >> s >> e >> v;

		eList.push_back(make_tuple(s-1, e-1, v));
	}

	// 시작점 거리는 0
	min_length[0] = 0;

	for (int i = 0; i < N - 1; i++) { // 노드 개수-1만큼 반복 : 최단거리 세팅

		for (int j = 0; j < eList.size(); j++) {
			int s = get<0>(eList[j]);
			int e = get<1>(eList[j]);
			long v = get<2>(eList[j]);

			// 간선 시작점이 무한이 아니고, 해당 노드까지의 거리가 더 짧은 것을 발견했다면
			if (min_length[s] != LONG_MAX && min_length[e] > min_length[s] + v) {
				min_length[e] = min_length[s] + v;
			}
		}
	}

	// 한번 더 시도했을 때, 값이 작아지는 게 있다면 음의 사이클 존재
	bool flag = false; // 음의 사이클 여부
	for (int i = 0; i < eList.size(); i++) {
		int s = get<0>(eList[i]);
		int e = get<1>(eList[i]);
		long v = get<2>(eList[i]);

		if (min_length[s] != LONG_MAX && min_length[e] > min_length[s] + v) {
			flag = true; // 음의 간선 존재
			break;
		}

	}

	if (flag == true) {
		cout << -1;
	}
	else {
		for (int i = 1; i < N; i++) {
			if (min_length[i] != LONG_MAX) {
				cout << min_length[i] << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}


	return 0;
}

//// 플로이드-워셜
// const long long INF = LLONG_MAX / 2;
//vector<vector<long long>> adjMatrix(500, vector<long long>(500, INF));
//int main(void) {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	long long N = 0;
//	long long M = 0;
//	cin >> N >> M;
//
//	for (long long i = 0; i < N; i++) {
//		adjMatrix[i][i] = 0;
//	}
//
//	for (long long i = 0; i < M; i++) {
//		long long s = 0;
//		long long e = 0;
//		long long v = 0;
//		cin >> s >> e >> v;
//
//		adjMatrix[s - 1][e - 1] = v;
//	}
//
//	for (long long k = 0; k < N; k++) {
//		for (long long s = 0; s < N; s++) {
//			for (long long e = 0; e < N; e++) {
//				//평소의 플로이드 와샬을 사용할 떈 해당 코드가 없어도 되지만
//				// 1. 음수 가중치가 존재하는 상황에서
//				// 2. 아예 가지 못 하는 곳이 존재한다면
//				// 다음 코드 추가해야함
//				if (adjMatrix[s][e] > adjMatrix[s][k] + adjMatrix[k][e]) {
//					if (adjMatrix[s][k] == INF || adjMatrix[k][e] == INF) {
//						continue;
//					}
//					else {
//						adjMatrix[s][e] = adjMatrix[s][k] + adjMatrix[k][e];
//					}
//				}
//				
//			}
//		}
//	}
//
//	bool flag = false;
//	for (long long i = 0; i < N; i++) { // 음의 사이클 존재
//		if (adjMatrix[i][i] < 0) {
//			cout << -1;
//			flag = true;
//			break;
//		}
//	}
//	if(flag==false){
//		for (long long i = 1; i < N; i++) {
//			if (adjMatrix[0][i] != INF) {
//				cout << adjMatrix[0][i] << '\n';
//			}
//			else {
//				cout << -1 << '\n';
//			}
//		}
//	}/*
//	cout << '\n';
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << adjMatrix[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//*/
//	return 0;
//
//
//}
