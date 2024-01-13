#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 우선순위 큐 비교 구조체
struct cmp
{
	// 우선순위 큐가 있을 때는 정렬조건이 다 반대방향임
	bool operator()(int a, int b)
	{
		// 만약 절댓값이 같은 두 수라면
		if (abs(a) == abs(b))
		{

			// 실제 값이 작은 게 우선순위가 높음
			return a > b;
		}

		else // 만약 절댓값이 다른 두 수라면

		{
			// 절대값이 작은 게 우선순위가 높음
			return abs(a) > abs(b);
		}
		
		
	}
};
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	priority_queue<int, vector<int>, cmp> pq; // 비교 함수를 구조체로 감싼 형태로 적용해줘야함

	// algorithm
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		

		if (temp == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}

			else
			{
				cout << '0' << '\n';
			}

		}

		else
		{
			pq.push(temp);
		}
	}

	
	return 0;
}
