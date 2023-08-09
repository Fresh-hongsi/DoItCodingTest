#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//버블 정렬로 풀기

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	vector<int> arr;

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;

		arr.push_back(temp);
	}
	 // 5 4 3 2 1
	 // 4 3 2 1 | 5
	 // 3 2 1 | 4 5
	 // 2 1 | 3 4 5
	 // 1 | 2 3 4 5
	//버블 정렬 진행
	for (int i = N-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}
