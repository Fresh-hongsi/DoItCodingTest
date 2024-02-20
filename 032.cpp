#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int K = 0;

	vector<int> arr;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;

		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end(), greater<>());
	int count = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		int cur = arr[i];
		if (cur > K)
		{
			continue;
		}

		int share = K / cur; // 몫 구하기
		count += share; // 필요 동전 개수 업데이트
		
		K -= (share * cur); // 남은 금액 구하기

		if (K == 0)
		{
			break;
		}
		
	}

	cout << count;
	return 0;
}
