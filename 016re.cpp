#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int>b) //첫번째 기준 오름차순 정렬
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
	{
		return a.first < b.first;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int result = 0;

	cin >> N;

	// 보통 pair은 첫번째 기준으로 정렬한다.
	vector<pair<int,int>> arr; //(value, index)

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;

		arr.push_back(make_pair(temp, i));
	}

	sort(arr.begin(), arr.end(),comp);
	
	int Max = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i].second - i > Max)
		{
			Max = arr[i].second - i;
		}
	}

	
	cout << Max+1;

	return 0;
	


}
