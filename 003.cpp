//구간합 - 백준:11659번

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//입력
	int numOfArr = 0; //벡터에 들어갈 원소 개수
	int tc = 0; //테스트 케이스 횟수
	vector<int> pureArr; //문제 풀이에 사용될 벡터
	vector<int> prefixSumArr; //구간 합에 사용될 벡터

	cin >> numOfArr >> tc;

	//순수 배열과 구간합 배열의 0번쨰 항만 미리 세팅
	int num = 0;
	cin >> num;
	pureArr.push_back(num);
	prefixSumArr.push_back(num);

	//순수 배열과 구간합 배열 동시 저장
	for (int i = 1; i < numOfArr; i++)
	{
		
		
		cin >> num;
		pureArr.push_back(num);
		prefixSumArr.push_back(num + prefixSumArr[i - 1]); //구간합 계산해서 적용

	}

	//테스트 케이스마다 답 도출
	for (int i = 0; i < tc; i++)
	{
		int idx1 = 0;
		int idx2 = 0;
		int result = 0;
		cin >> idx1 >> idx2;

		if (idx1 == 1) //만약 첫번째 인덱스부터의 합부터 알고싶으면 그냥 해당 구간합의 값을 반환해주면 됨
		{
			result = prefixSumArr[idx2-1];
		}
		else //만약 첫번쨰 인덱스부터가 아닌 다른 곳부터의 합을 구하고 싶은 경우 s[j]-s[i-1]로 계산
			 result = prefixSumArr[idx2-1] - prefixSumArr[idx1-2];
		cout << result << '\n';
	}

	return 0;
}
