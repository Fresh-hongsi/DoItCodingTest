#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

vector<vector<bool>> visited(201, vector<bool>(201, false)); 
vector<bool> answer(201, false); // 가능한 c의 물 값
int from[6] = { 0,0,1,1,2,2 }; // 물을 주는 쪽 
int to[6] = { 1,2,0,2,0,1 }; // 물을 받는 쪽
int now[3]; // 현재 a,b,c의 물 양을 저장할 배열
int total = 0; // 물 전체 양
void bfs() {
	queue<pair<int, int>> q; // 물 두개로 관리 a, b
	q.push(make_pair(0, 0));
	visited[0][0] = true; // a울 0, b물 0일 때는 이미 방문 - a,b 결정되면 c는 알아서 결정되므로!
	answer[now[2]] = true;

	while (!q.empty()) {

		int curA = q.front().first;
		int curB = q.front().second;
		int curC = now[2] - curA - curB; // 최초 c 물 양에서 현재 a,b,물 양 빼면 현재 c 물 양임
		q.pop();

		for (int i = 0; i < 6; i++) {
			int next[3] = { curA,curB,curC };

			next[to[i]] += next[from[i]]; // 물을 주기
			next[from[i]] = 0; // 물을 줬으므로 준 컵은 제로

			if (next[to[i]] > now[to[i]]) { //물이 넘친 경우
				
				next[from[i]] = next[to[i]] - now[to[i]]; // 넘친 양만큼 준 컵에 담기
				next[to[i]] = now[to[i]]; // 받은 컵은 최대 양으로 바꾸기
			}

			if (visited[next[0]][next[1]] == false) { // 한번도 적용해보지 않은 경우라면
				visited[next[0]][next[1]] = true;
				q.push(make_pair(next[0], next[1]));

				if (next[0] == 0) { // 만약 a컵이 비었다면
					answer[next[2]] = true;

				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> now[0] >> now[1] >> now[2];
	total = now[2];

	bfs();
	for (int i = 0; i < 201; i++) {
		if (answer[i] == true) {
			cout << i << ' ';
		}
	}

	return 0;


}
