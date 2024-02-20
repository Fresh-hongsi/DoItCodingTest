#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 정렬!!! 즉 가장 작은 게 top에 있다

	int result = 0;

	// 우선 순위 큐에 값 넣기 - 우선순위큐는 일반적인 자료구조와 달리 정렬 기준이 반대이므로, 가장 작은 값이 top에 놓여지도록 구현한 것임
	for (int i = 0; i < N; i++)
	{
		long temp = 0;
		cin >> temp;
		pq.push(temp);
	}


	while (pq.size() != 1)
	{
		int a = pq.top(); // 현재 우선순위 큐에서 가장 작은 값 찾기
		pq.pop();
		int b = pq.top(); // 현재 우선순위 큐에서 두번째로 작은 값 찾기
		pq.pop();

		pq.push(a + b); // 새로 값 세팅해서 넣어주기
		result += (a + b); // 결과값 업데이트

	}
	
	cout << result;
	return 0;

}
