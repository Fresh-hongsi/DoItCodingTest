#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <deque>
using namespace std;




int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	long long answer = 0; // 거의 소수의 개수
	long long prefix = 100000000000001; // 테케의 가장 큰 범위
	long long a; // 거의 소수의 시작 기준
	long long b; // 거의 소수의 끝 기준

	cin >> a >> b;

	vector<bool> arr(sqrt(b)+2, true); // 소수는 prefix의 제곱근 + 1 까지만 구하면 됨(정수형이라 소수점은 버리므로)
	deque<long long> prime; // 소수들을 저장할 배열
	deque<long long> almost; // 거의 소수를 저장할 배열

	arr[0] = false; // 0은 소수 아님
	arr[1] = false; // 1은 소수 아님

	// 10^7까지의 소수를 판별
	// 에라토스테네스의 체 적용
	for (long long i = 2; i <= sqrt(b)+1; i++)
	{
		if (arr[i] == true)
		{
			for (long long j = i + i; j <= sqrt(b)+1; j += i)
			{
				arr[j] = false;
			}
		}

		else
			continue;
	}

	// 소수를 prime배열에 저장
	for (long long i = 2; i <= sqrt(b)+1; i++)
	{
		if (arr[i] == true)
		{
			prime.push_back(i);
		}
	}

	// 소수를 하나씩 꺼내 거의 소수인 수를 찾아서 alomost 덱에 넣어주기
	while (prime.size() > 0)
	{
		long long cur = prime.front(); // 소수 배열에서 소수를 하나 꺼냄
		prime.pop_front();
		
		
		long long temp = cur; // 거의 소수를 찾기 위해 기준이 되는 소수

		while (1)
		{
			// 우선 2제곱 해서 temp에 저장
			// 앞으로 temp를 갱신해 나가며 거의 소수를 찾아볼 것임
			temp *= cur;

			// 가장 끝 값을 넘어버린 경우
			if (temp > b)
			{
				break;
			}

			else
			{
				// 시작점보다 크거나 같으면 거의소수 확정
				if (temp >= a)
				{
					almost.push_back(temp);
				}

				// 근데 만약 현재 temp에 cur을 곱했을 때(다음 제곱) prefix를 넘으면 곧 오버플로우나므로,
				// 이를 방지하기 위한 조건
				if (temp > prefix / cur)
				{
					break;
				}



				
				
			}
		}

	}

	// 출력
	cout << almost.size();
	return 0;


}
