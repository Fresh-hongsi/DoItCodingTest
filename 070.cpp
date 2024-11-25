#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int N = 0;
vector<vector<int>> tree(26, vector<int>(2, 0));

// 전위순회
void preOrder(int cur) {

	if (cur == -1) {
		return;
	}
	cout << (char)(cur + 'A');
	preOrder(tree[cur][0]);
	preOrder(tree[cur][1]);
}

// 중위순회
void inOrder(int cur) {	
	if (cur == -1) {
		return;
	}
	inOrder(tree[cur][0]);
	cout << (char)(cur + 'A');
	inOrder(tree[cur][1]);
}

// 후위순회
void postOrder(int cur) {
	if (cur == -1) {
		return;
	}
	postOrder(tree[cur][0]);
	postOrder(tree[cur][1]);
	cout << (char)(cur + 'A');
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		char nodeChar;
		char left;
		char right;
		cin >> nodeChar >> left >> right; // 노드, left, right 자식 입력받음

		int node = nodeChar - 'A'; // 현재 노드를 배열 계산에 용이하게 하기 위해 int형으로 변환
		
		// 왼쪽 자식 세팅
		if (left == '.') {
			tree[node][0] = -1;
		}
		else {
			tree[node][0] = left-'A';
		}
		
		// 오른쪽 자식 세팅
		if (right == '.') {
			tree[node][1] = -1;
		}
		else {
			tree[node][1] = right - 'A';
		}


	}

	preOrder(0); // A부터 전위순회
	cout << '\n';
	inOrder(0); // A부터 중위순회
	cout << '\n';
	postOrder(0); // A부터 후위순회

	return 0;

	
}
