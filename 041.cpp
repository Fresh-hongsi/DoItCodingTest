#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void)
{
	// 오일러 피 - 서로소
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n = 0;
	cin >> n;
	long long result = n;

	for (long long p = 2; p <= sqrt(n); p++) // 제곱근까지만 수행
	{
		if (n % p == 0) // p가 소인수인지 확인
		{
			result -= result / p;
		}

		// 해당 소인수 지우기
		while (n % p == 0)
		{
			n /= p;
		}
	}

	if (n > 1) // 아직 소인수 구성이 남아있는 경우
	{
		result = result - result / n;
	}

	cout << result;
	return 0;
}
