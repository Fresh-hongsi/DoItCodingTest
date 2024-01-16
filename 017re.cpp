#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 선택 정렬으로 풀어보기
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;

	cin >> s;

	vector<int> arr;

	for (int i = 0; i < s.length(); i++)
	{
		int t = s[i] - 48;
		arr.push_back(t);
	}


	// 선택 정렬 알고리즘
	for (int i = 0; i < arr.size(); i++)
	{
		int maxIdx = i; // 정렬의 범위는 i번째 인덱스부터 끝까지

		// 정렬 범위 내에서 가장 큰 값이 있는 인덱스를 찾기
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[maxIdx] < arr[j])
			{
				maxIdx = j;
			}
		}

		// 정렬 범위 가장 앞에 있는 인덱스와 찾은 인덱스를 swap
		int temp = arr[maxIdx];
		arr[maxIdx] = arr[i];
		arr[i] = temp;
	}

	// 출력
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
	}

	return 0;


}
