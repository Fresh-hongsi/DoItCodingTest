#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

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


	for (int i = N; i>0;i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}
