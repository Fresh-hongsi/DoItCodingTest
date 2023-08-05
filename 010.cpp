#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	deque<pair<int, int>> sequenceDeq; //특별한 기준으로 최소값 찾기 위해 덱 사용
	
	//D(i) = Min(A(i-L+1)...A(i))
	
	//입력
	int N = 0;
	int L = 0; 

	cin >> N >> L;


	for (int i = 1; i <= N; i++)
	{
		int num = 0;
		cin >> num;

		pair<int, int> current = pair<int, int>(i, num); //i: 현재 인덱스, num: 인덱스에 해당하는 값

		//만약 덱이 비워져있다면 무조건 하나 삽입
		//만약 앞의 값이 현재 값보다 작다면 앞 값은 더이상 최소가 아니므로 삭제
		while (sequenceDeq.size() && sequenceDeq.back().second > current.second)
		{
			sequenceDeq.pop_back();
		}

		//더 큰값 다 지워줬으면 현재 값으로 세팅
		sequenceDeq.push_back(current);


		//앞에서 인덱스 벗어나는 거 제거하기 위함
		if (sequenceDeq.front().first <= (i - L))
		{
			sequenceDeq.pop_front();
		}

		cout << sequenceDeq[0].second << ' ';

	}

	return 0;
	

	
}
