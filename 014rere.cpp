#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <math.h>
using namespace std;


// 우선순위 큐 비교 구조체
struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) { // 절댓값이 같다면
			
			// 크기가 작은게 우선순위 높음 -- pq니까 반대
			return a > b;
		}

		else { // 절댓값이 다르다면
			//절댓값이 작은 게 우선순위 높음 -- pq니까 반대
			return abs(a) > abs(b);
		}
	}
};
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<int, vector<int>, cmp> pq;

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;

		if (temp != 0) {
			pq.push(temp);
		}
		else {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << '0' << '\n';
			}
		}
		
	}


	return 0;
}

