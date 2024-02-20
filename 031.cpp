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
	cin >> N>>K;

	int s = 1;
	int e = K;
	int result = 0;
	while (s <= e)
	{
		int m = (s + e) / 2; // 중앙값 구하기
		int count = 0;

		// 현재 중앙값보다 작거나 같은 수의 개수를 count하기
		for (int i = 1; i <= N; i++)
		{
			count = count + min(m / i, N);
		}

		if (count < K) // 이 경우 ARR[K]는 현재 중앙값 M보다 더 큰 수여야함 -> 즉 result는 현재 m보다 무조건 커야함
		{
			s = m + 1;
		}
		else // 이 경우 ARR[K]는 현재 중앙값 M보다 더 작은 수여야할 수도 있음 -> result는 현재 m일수도 있고, 더 작은 수일 수도 있음
		{
			result = m; // 임시 저장값에 저장
			e = m - 1;
		}
	}

	cout << result;
	return 0;

	
	

}
