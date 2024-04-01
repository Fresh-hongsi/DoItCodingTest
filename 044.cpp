#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple> // 튜플 선언
using namespace std;

vector<tuple<long, long, long>> adjList[10]; // 대상 / 비율의 분자 / 비율의 분모 저장
long lcm = 1; // 최소공배수
long quantity[10] = { 0, }; // 각 재료별 양
bool visited[10] = { false, }; // 방문 표시 배열

// 최대 공약수 구하는 함수
long gcd(long a, long b) {

	if (b == 0) {
		return a;
	}

	else {
		return gcd(b,a%b);
	}

}

void DFS(long node) {
	
	visited[node] = true;

	for (tuple<long, long, long> i : adjList[node]) {
		
		long next = get<0>(i);
		if (visited[next] != true) {
			quantity[next] = quantity[node] * get<2>(i) / get<1>(i);
			DFS(next);
		}
	}


}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long N = 0;
	cin >> N;

	// 인접 리스트에 저장 및 임시 최소공배수 구하기
	for (long i = 0; i < N-1; i++) {

		long a, b, p, q = 0;
		cin >> a >> b >> p >> q;

		adjList[a].push_back(make_tuple(b, p, q)); // a와 b의 비율을 p:q
		adjList[b].push_back(make_tuple(a, q, p)); // b와 a의 비율은 q:p

		lcm *= p * q / gcd(p, q); // 최선의 최소공배수를 구하는 과정 - 추후에 어차피 다시 최대공약수로 나눌 것임
	}

	// 기준 노드를 잡고, dfs 수행하며 비율 계산 통해 각 노드에 값 저장하기
	quantity[0] = lcm; // 0번째 노드를 우선 기준으로 잡기

	DFS(0); // DFS 통해 모든 재료에 대한 양을 계산해보기

	long curGcd = lcm; // quantity 배열을 돌아다니면서 최대공약수를 찾아갈 것
	for (int i = 0; i < N; i++) {

		curGcd = gcd(curGcd, quantity[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << quantity[i] / curGcd << ' ';
	}

	return 0;







}
