#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <deque>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	deque<pair<int, int>> dq; // pair의 구조: 앞의 int는 인덱스, 뒤의 int는 now값

	int arrLength = 0; 
	int windowSize = 0;

	cin >> arrLength >> windowSize;

	for (int i = 0; i < arrLength; i++)
	{
		int now = 0;
		cin >> now;

		if (!dq.empty()) // 만약 덱이 비어있지 않다면
		{

			// 현재 now값보다 큰 pair의 second값이 있다면, 그 pair을 계속해서 덱에서 제거
			while (!dq.empty() && dq.back().second >= now)
			{
				dq.pop_back();

			}

			// 그리고 맨 뒤에 현재 now를 pair로 만들어서 덱에 넣어줌
			dq.push_back(make_pair(i, now));

			// 인덱스 범위 밖인 덱의 요소를 앞에서 계속 제거해줌
			while (!dq.empty() && dq.front().first < i - windowSize + 1)
			{

				dq.pop_front();

			}

			// 그 후 가장 앞에 있는 pair.second값 출력
			cout << dq.front().second << ' ';
			
		}

		else // 만약 덱이 비어있따면
		{
			dq.push_back(make_pair(i, now));

			// 그 후 가장 앞에 있는 pair.second값 출력
			cout << dq.front().second << ' ';
		}


	}

	return 0;


}
