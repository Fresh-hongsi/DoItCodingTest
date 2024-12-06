#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;

// 세그먼트 트리 - 최솟값 구하기

vector<long long> tree;
long long leftStartIndex = 0;
long long treeHeight = 0;
long long treeSize = 0;
long long firstInputSize = 0;
long long N = 0;
long long M = 0;

// 최솟값 기반 트리 세팅하기
void treeSet(long long index) {
	while (index != 0) {
		if (tree[index / 2] > tree[index]) {
			tree[index / 2] = tree[index];
		}
		index--;
	}
}

// 범위 내의 최솟값 구하기
long long findMin(long long st, long long en) {

	long long minimum = 1000000001;

	while (st <= en) {
		if (st % 2 == 1) {
			minimum = min(minimum, tree[st]);
			st++;
		}

		if (en % 2 == 0) {
			minimum = min(minimum, tree[en]);
			en--;
		}

		st /= 2;
		en /= 2;
	}

	return minimum;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	firstInputSize = N;

	// 트리 높이 구하기
	while (N > 0) {
		treeHeight++;
		N /= 2;
	}

	treeSize = (long long)(pow(2, treeHeight+1)); // 트리 크기 구하기
	tree.resize(treeSize + 1); // 트리 크기 재조정
	for (int i = 0; i < treeSize + 1; i++) {
		tree[i] = 1000000001; // 최솟값을 구하는 것이므로 최댓값으로 세팅
	}
	leftStartIndex = treeSize / 2 - 1; // 리프노드 시작점 계산
	
	
	// 초기 트리 입력
	for (long long i = leftStartIndex + 1; i <= leftStartIndex + firstInputSize; i++) {
		cin >> tree[i];
	}

	treeSet(treeSize - 1);
	
	for (long long i = 0; i < M; i++) {
		long long start = 0;
		long long end = 0;
		cin >> start >> end;

		// 트리에 맞게 인덱스 변경
		start += leftStartIndex;
		end += leftStartIndex;
		long long result = findMin(start, end);
		cout << result << '\n';
	}

	/*cout << treeHeight << ' ' << treeSize;*/
	

	return 0;
}
