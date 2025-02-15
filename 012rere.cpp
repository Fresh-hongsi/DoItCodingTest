#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stack>
using namespace std;


// 내 방식으로 풀기!!

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	vector<int> v; // 입력값 저장 배열
	stack<int> st; // 스택
	vector<int> result; // 정답값 저장(추후 rever해야 진짜 정답)

	// 값 입력받아 벡터에 저장
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}

	// 무조건 가장 끝에 있는 값은 자기 기준 오큰수 없으므로 result에 -1저장, st에 자기 자신 값 저장
	result.push_back(-1);
	st.push(v[N - 1]);


	// 마지막 인덱스 바로 전 인덱스부터 오큰수 구하기
	for (int i = N - 2; i >= 0; i--) {
		int cur = v[i]; // 현재 바라보고 있는 값

		
		while (!st.empty()) { // 스택이 비어있지 않다면
			int top = st.top(); // 현재 스택의 top값
			if (cur < st.top()) { // 만약 cur이 top이 작다면
				result.push_back(st.top()); //오큰수 발견한 것이므로, result에 오큰수값 저장
				st.push(cur); // 그리고 자기 자신값이 누군가의 오큰수일 수 있으므로 저장
				break; // 다음 인덱스 값을 알아보기 위해 탈출
			}
			else if (cur >= st.top()) { // 만약 cur이 top보다 크거나 같다면, 다른 오큰수가 있는 지 st pop해가며 알아봐야힘
				st.pop(); 
			}
		}
		if (st.empty()) { // 만약 st을 다 pop해봤는데도 오큰수가 없다면, cur이 가장 큰 것이므로 해당 인덱스에 대해서는 오큰수가 -1임
			result.push_back(-1);
			st.push(cur);
		}

	}

	// 결과값을 reverse한게 최종 정답
	reverse(result.begin(), result.end());
	for (auto k : result) {
		cout << k << ' ';
	}

	return 0;

}
