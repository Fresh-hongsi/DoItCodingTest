#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <cmath>
using namespace std;

long long N = 0; // 수의 개수
long long M = 0; // 변경이 일어나는 횟수
long long K = 0; // 구간합 구할 횟수
long long treeHeight = 0; // 트리의 높이
long long Length = 0; // 입력받을 숫자 크기
long long treeSize = 0; // 트리의 길이
vector<long long> tree;

// 모든 트리 값 세팅
void setTree(long long i) {
	while (i != 1) {
		tree[i / 2] += tree[i];
		i--;
	}
	
}

// 값 변경
void changeVal(long long index, long long val) {
	long diff = val - tree[index];

	while (index > 0) {
		tree[index] = tree[index] + diff;
		index /= 2;
	}
}

// 구간합
long getSum(long long s, long long e) {
	long long partSum = 0;

	while (s <= e) {
		
		if (s % 2 == 1) {
			partSum += tree[s];
			s++;
		}

		if (e % 2 == 0) {
			partSum += tree[e];
			e--;
		}

		s /= 2;
		e /= 2;
	
	}

	return partSum;

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;

	Length = N;

	// 트리의 높이 계산
	while (Length!=0) {
		Length /= 2;
		treeHeight++;
	}

	treeSize = (long long)(pow(2, treeHeight + 1));  // 트리의 길이 구하기
	long long leftNodeStartIdx = treeSize / 2 - 1; // 리프노드의 시작점(후술할 계산 편의성 위해 1을 더 빼줌)
	tree.resize(treeSize + 1); // 트리 크기 재조정

	// 데이터 입력
	for (long long i = 1 + leftNodeStartIdx; i <= N + leftNodeStartIdx; i++) {
		cin >> tree[i];
	}

	// 리프노드를 제외한 노드의 값 설정
	setTree(treeSize - 1);

	for (long long i = 0; i < M + K; i++) {
		long long a = 0; // 커맨드
		long long s = 0; // 시작 노드 
		long long e = 0; // 끝 노드 / 값
		cin >> a >> s >> e;
		if (a == 1) { //값 변경
			changeVal(s + leftNodeStartIdx, e);
		}
		else if (a == 2) { // 구간합 구하기
			s = s + leftNodeStartIdx;
			e = e + leftNodeStartIdx;
			cout << getSum(s, e) << '\n';
		}
	}


	return 0;

}
