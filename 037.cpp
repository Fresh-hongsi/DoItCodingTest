#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M = 0;
	int N = 0;

	vector<bool> arr(1000001, true);

	arr[0] = false;
	arr[1] = false;
	
	cin >> M >> N;

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (arr[i] == true) // 소수라면
		{
			for (int j = i+i; j <= N; j += i)
			{
				arr[j] = false;
			}
		}

		else
			continue;
	}

	for (int i = M; i <= N; i++)
	{
		if (arr[i] == true)
		{
			cout << i << '\n';
		}
	}

	return 0;

}
