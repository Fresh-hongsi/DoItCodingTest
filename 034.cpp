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
	int result = 0;
	deque<int> dq;

	cin >> N;

	// 덱에 입력
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		dq.push_back(temp);
	}

	// 덱의 자료들을 오름차순 정렬
	sort(dq.begin(), dq.end());
	
	
	while (1)
	{
		// 덱에 남아있는 게 두개 이상일 때,
		// 가장 앞 쪽에 있는 두 데이터가 0이하이면
		// 그 두개의 수를 이용해 max값 찾아서 result에 더해주기
		// 가장 앞의 두 수가 0보다 커지기 전까지 반복
		// 그 이유는 앞의 두 수가 0 이하일 때 양수로 만들 여지가 있어서임
		if (dq.size() > 1 && dq[0]<=0 && dq[1]<=0)
		{
			int a = dq.front();
			dq.pop_front();
			int b = dq.front();
			dq.pop_front();

			int front_max = max(a + b, a * b);
			result += front_max;
			continue;
			
		}

		// 덱의 앞쪽 처리가 끝났으면
		// 덱에 남아있는 게 두 개 이상일 때
		// 가장 뒤에 있는 두 데이터의 max값 찾아서 result에 더해주기
		if (dq.size() > 1)
		{
			int a = dq.back();
			dq.pop_back();
			int b = dq.back();
			dq.pop_back();

			int back_max = max(a + b, a * b);
			result += back_max;
		}


		// 만약 덱에 있는 게 1개라면, 
		// 나머지 그 데이터 한 개를 result에 더해주기
		if (dq.size() == 1)
		{
			int remain = dq.front();
			dq.pop_front();

			result += remain;
		}

		// 만약 덱에 남아있는 게 없다면
		// 반복문 탈출
		if (dq.size() == 0)
		{
			break;
		}
		

	}

	cout << result;
	return 0;

	

	


}
