#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0; // 강의의 수
	int M = 0; // 담을 블루레이 개수

	vector<int> arr; // 강의를 담을 벡터

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;

		arr.push_back(temp);
	}


	int s=0; // 이분탐색 시작은 가장 긴 강의 - 즉 각 블루레이 안에 들어갈 수 있는 가장 작은 값
	int e = 0; // 이분탐색 끝은 모든 강의 길이의 합 - 즉 블루레이 안에 들어갈 수 있는 가장 큰 값

	for (int i = 0; i < N; i++) {
		e += arr[i];
		if (s < arr[i]) {
			s = arr[i];
		}
	}

	int count; // m이 결정되었을 때, 그 값을 바탕으로 만든 블루레이 개수

	while (s <= e)
	{
		count = 0; // 블루레이 개수 초기화
		int m = (s + e) / 2; // 블루레이 길이 정해주기
		int sum = 0;

		for (int i = 0; i < N; i++) {

			sum+= arr[i];

			if (sum > m)
			{
				count++;
				sum = arr[i];
			}

		}

		count++; // 마지막 영상까지 도달한 최종 블루레이 개수 추가

		

		// count < M -> 블루레이 용량을 더 최소화시킬 여지가 있다는 것  
		if (count <= M)
		{
			e = m - 1;

		}

		// count > M -> 블루레이 용량을 늘려야함
		else if (count > M)
		{
			s = m + 1;
		}

		
	}

	cout << s;
	return 0;


}
