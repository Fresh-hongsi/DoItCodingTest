#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<vector<int>>arr(1025,vector<int>(1025,0)); //기본 이차원 벡터
	vector<vector<int>> prefixSumArr(1025,vector<int>(1025,0)); //행별로 구간합 저장할 이차원 배열

	int rowSize = 0; //행 크기 -> 행 크기과 열 크기 같음
	

	int tc = 0; //연산 횟수 테스트케이스

	cin >> rowSize >> tc; 

	for (int i = 1; i <= rowSize; i++)
	{
		for (int j = 1; j <= rowSize; j++)
		{
			int arrData = 0;
			cin >> arrData;
			arr[i][j] = arrData;
			prefixSumArr[i][j] = prefixSumArr[i][j - 1] + arrData;

		}
	}

	//연산 횟수만큼 연산해서 결과값 출력
	for (int i = 0; i < tc; i++)
	{
		int x1, y1, x2, y2 = 0;
		int result = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1; j <= x2; j++)
		{
			result += (prefixSumArr[j][y2] - prefixSumArr[j][y1 - 1]);
		}

		cout << result << '\n';
	}


	return 0;

}
