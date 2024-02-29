#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int gcd(int max, int min)
{
	// 나머지가 0이되는 순간 gcd는 min임
	if (max % min == 0)
	{
		return min;
	}
	// 그게 아니라면
	else {
		// 재귀적 방식으로 다시 최대공약수 구하기
		int temp = max % min;
		return gcd(min, temp);
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 테스트케이스 입력
	int tc = 0;
	cin >> tc;

	while (tc--) {
		int a = 0;
		int b = 0;

		cin >> a >> b;

		int minimum = min(a, b);
		int maximum = max(a, b);
		
		int result = a*b/gcd(maximum, minimum);


		// 최소공배수는 최초 두 수의 곱을 최대공약수로 나눈 값임
		cout << result << '\n';

	}

	return 0;
}
