#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
// 트라이 자료구조를 활용한 풀이

class Node {
public:
	Node* next[26]; // 각 노드는 알파벳 26자를 next 포인터로 가질 수 있음
	bool isEnd; // 마지막 노드 여부

	// 생성자, isEnd는 false로 처리하며 생성
	Node() : isEnd(false) {
		for (int i = 0; i < 26; i++) {
			next[i] = nullptr;
		}
	}

	// 소멸자, 노드 삭제 시 자신의 하위 노드도 함께 삭제
	~Node(){
		for (auto& k : next) {
			delete k;
		}
	}


	// insert함수
	void insert(const char* key) {
		
		if (*key == 0) { // 널문자 '\0'에 도달			
			isEnd = true; // 문자열 끝에 도달했음을 표시
		}

		else {
			int next_index = *key - 'a';
			if (next[next_index] == nullptr) { // 다음 노드가 없으면
				next[next_index] = new Node(); // 노드 생성
			}
			next[next_index]->insert(key + 1); // 다음 노드 삽입 시도
		}
	}

	// find 함수
	Node* find(const char* key) {
		if (*key == 0) { // 끝에 도달했으면
			return this;
		}

		int next_index = *key - 'a';
		if (next[next_index] == nullptr) { // 다음 노드가 없으면 nullptr 반환
			return nullptr;
		}
		else {
			return next[next_index]->find(key+1); // 다음 노드 찾기
		}
	}
};



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	int m = 0;
	cin >> n >> m;
	int count = 0;
	Node* root = new Node(); // 루트 노드는 비워두기

	// 트라이 세팅
	while (n--) {
		char text[501];
		cin >> text;

		root->insert(text);
	}

	// 해당 문자열이 트라이 내에서 찾을 수 있는 지 확인
	while (m--) {
		char text[501];
		cin >> text;
		Node * result = root->find(text);

		// 만약 nullptr이 아니고 마지막까지 도달했다면, 해당 문자열 찾음
		if (result && result->isEnd == true) {
			count++;
		}
		
	}

	cout << count;
	return 0;

}
