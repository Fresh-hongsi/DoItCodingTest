#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//삽입 정렬 활용
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	//입력
	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	//삽입정렬 통해 오름차순 정렬 -> 그렇게 해야 각자 인출 시간의 합을 최소화할 수 있음 -> greedy임
	for (int i = 0; i < N; i++)
	{
		int min = 20000; //현재 루프에서 최소값
		int minIdx = 0; //현재 루프에서 최소값인 곳의 인덱스

		for (int j = i; j < N; j++)
		{
			if (min >= arr[j])
			{

				min = arr[j];
				minIdx = j;
			}
		}

		//swap
		arr[minIdx] = arr[i];
		arr[i] = min;
		
	}

	//모든 사람 각각이 인출하는데 걸리는 시간의 합을 구하기
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		
		if (i >= 1)
		{
			result += arr[i]+arr[i-1];
			arr[i] = arr[i - 1] + arr[i];
		}

		else
		{
			result += arr[i];
		}
		

		//1 1+2 1+2+3 1+2+3+3

	}

	

	cout << result;


}
