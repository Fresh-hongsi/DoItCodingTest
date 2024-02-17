#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 이진탐색 ver
vector<int> arr;

bool binarySearch(int n) 
{
	int s = 0;
	int e = arr.size() - 1;
	bool flag = false;
	
	while (s <= e) {
		int m = (s + e) / 2;
		if (arr[m] == n)
		{
			flag = true;
			return flag;
		}
		else if (arr[m] > n) {
			e = m - 1;
		}
		else
		{
			s = m + 1;
		}
	}

	return flag;
	
}


int main(void) 
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int M = 0;
	cin >> N;

	
	for(int i=0;i<N;i++){
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	cin >> M;
	for (int i = 0; i < M; i++) 
	{
		int num = 0;
		cin >> num;

		bool flag =binarySearch(num);
		if (flag == true) {
			cout << 1 << '\n';
		}
		else 
		{
			cout << 0 << '\n';
		}
	}

	return 0;
}
