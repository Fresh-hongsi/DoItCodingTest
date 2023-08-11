#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


//selection sort 이용
//백준 1427 

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//입력
	int N = 0;
	cin >> N;

	//문자열로 변환
	string s = to_string(N);
	
	//변환된 문자열을 배열로 변환
	vector<int> arr;
	for (int i = 0; i < s.length(); i++)
	{
		arr.push_back(s[i] - 48);
	}

	//선택정렬 수행
	for (int i = 0; i < arr.size(); i++)
	{
		int max = 0; //내부 루프에서 arr[i]~arr[M]에서의 최대값
		int maxIdx = 0; //최대값이 있었던 곳의 인덱스

		for (int j = i; j < arr.size(); j++)
		{
			if (max <= arr[j]) //내부 루프에서의 최대값, 최대값의 인덱스 찾ㄷ기
			{
				max = arr[j]; 
				maxIdx = j;
			}
		}

		//i번쨰 값과 maxIdx번째 값을 swap
		arr[maxIdx] = arr[i];
		arr[i] = max;
		

	}

	//출력
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
	}

	return 0;

	
}
