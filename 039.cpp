#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

// 팰린드롬수인지 확인하기 위한 함수
bool is_palindrome(long long i)
{
	string s = to_string(i);

	long long l = s.length();

	bool result = true; // 일단 true로 놓고 시작

	// 첫번째 인덱스와 끝 인덱스를 변경해나가면서 팰린드롬수인지 구분
	for (long long i = 0; i < (long long)(s.length() / 2); i++)
	{
		if (s[i] != s[l - i-1])
		{
			result = false;
		}
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long N = 0;
	cin >> N;

	// 에라토스테네스의 체를 이용해 소수를 모두 구해놓기
	vector<bool> arr(1100000, true);
	arr[0] = false; // 0은 소수 아님
	arr[1] = false; // 1은 소수 아님

	// 소수 구하기
	for (long long i = 2; i < sqrt(1100000); i++)
	{
		if (arr[i] == true)
		{
			for (long long j = i + i; j < 1100000; j += i)
			{
				arr[j] = false;
			}
		}

		else
		{
			continue;
		}
	}


	// N부터 살펴보며, 소수이면서 팰린드롬수인 것 찾아서 출력
	for (long long i = N; i < 1100000; i++)
	{
		if (arr[i] == true && is_palindrome(i) == true)
		{
			cout << i;
			break;
		}
	}

	return 0;


}
