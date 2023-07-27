#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

//구간합 이용 문제
//특별한 발상 필요!! -> 스타일을 외우는 수밖에.. 

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
   
	long long N = 0; //입력받을 수의 개수
	long long M = 0; //나머지를 취할 값
	vector<long long> prefixSumArr; //구간합을 저장할 일차원 벡터
	vector<long long> remainderArr(1001, 0); //구간합에 대해 각 인덱스별로 나머지값을 취한 결과, 나머지 값이 같은 것을 count해주기 위한 배열
	long long result = 0; //결과 값
	

	prefixSumArr.push_back(0); //구간합 세팅의 편의성을 위해 0값을 미리 삽입


	//입력
	cin >> N >> M;

	for (int i = 1; i <= N; i++) //구간합 세팅, remainderArr세팅, 나머지값이 0이면 result++
	{
		long long num = 0; 
		cin >> num;

		prefixSumArr.push_back(prefixSumArr[i - 1] + num) ; //구간합 계산해서 구간합 배열에 저장

		long long remain = prefixSumArr[i] % M;

		if (remain == 0) //구간합에 모듈로 연산을 가했을 때 나머지 값이 0이면 즉시 result값 증가
		{
			result++;
		}

		//나머지가 같은 인덱스의 갯수 세기 -> 밑에서 사용하기 위해
		remainderArr[remain]++;
		
	}


	//나머지가 같은 인덱스 중 2개를 뽑는 경우의 수를 구해서 result에 더해주기
	for (int i=0;i<=M-1;i++)
	{
		result += (remainderArr[i] * (remainderArr[i] - 1) / 2);
	}


	//출력
	cout << result;


	



	
	


}
