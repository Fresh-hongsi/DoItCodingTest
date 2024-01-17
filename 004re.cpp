#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<vector<int>>arr(1025, vector<int>(1025, 0)); //기본 이차원 벡터
	vector<vector<int>> prefixSumArr(1025, vector<int>(1025, 0)); //각 영역별 구간합 저장할 이차원 벡터

	int rowSize = 0; //행 크기 -> 행 크기과 열 크기 같음


	int tc = 0; //연산 횟수 테스트케이스

	cin >> rowSize >> tc;

	
	//원본 배열 저장
	for (int i = 1; i <= rowSize; i++)
	{
		for (int j = 1; j <= rowSize; j++)
		{
			int arrData = 0;
			cin >> arrData;
			arr[i][j] = arrData;
			

		}
	}

	//구간합 배열 저장
	for (int i = 1; i <= rowSize; i++)
	{
		for (int j = 1; j <= rowSize; j++)
		{
			prefixSumArr[i][j] = prefixSumArr[i - 1][j] + prefixSumArr[i][j - 1] - prefixSumArr[i - 1][j - 1] + arr[i][j];
		}
	}

	//질의 횟수만큼 연산해서 결과값 출력
	for (int i = 0; i < tc; i++)
	{
		int x1, y1, x2, y2 = 0;
		int result = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		result = prefixSumArr[x2][y2] - prefixSumArr[x1 - 1][y2] - prefixSumArr[x2][y1 - 1] + prefixSumArr[x1 - 1][y1 - 1];

		cout << result << '\n';
	}


	return 0;

}
