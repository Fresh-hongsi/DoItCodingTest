#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	deque<int> dq;
	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}


	while (dq.size() >= 1)
	{
		if (dq.size() == 1)
		{
			cout << dq.front();
			dq.pop_front();
			break;
		}

		// 가장 위에 있는 거 버리기
		dq.pop_front();

		// 가장 위에 있는 거 가장 뒤로 옮기기
		int front = dq.front();
		dq.pop_front();
		dq.push_back(front);


	}

	return 0;
}
