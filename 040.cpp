#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long min = 0;
	long long max = 0;

	cin >> min >> max;

	vector<bool> arr(max - min + 1,false);

	for (long long i = 2; i <= sqrt(max); i++)
	{
		long long pow = i * i; // 현재 재곱수
		long long start_idx = min / pow;  // 시작 인덱스

		if (min % pow != 0)
		{
			start_idx++;
		}

		for (long long j = start_idx; j * pow <= max; j++)
		{
			arr[j * pow - min] = true; // 제곱수로 나누어 떨어지는 수를 true로 표시
		}
	}

	int counter = 0;
	// false인 것 개수 찾기
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == false)
		{
			counter++;
		}
	}

	cout << counter;
	return 0;


}
