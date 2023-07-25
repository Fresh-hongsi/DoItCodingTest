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

	double N = 0; //세준이가 본 과목 수
	vector<double> scoreArr; //각 과목 별 점수를 담을 배열
	double maxScore = 0; //가장 점수 높은 과목 점수
	double resultAverage = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		double score = 0;
		cin >> score;
		scoreArr.push_back(score);

		if (maxScore < score) //점수 입력받음과 동시에 최고점 점수 정해짐
		{
			maxScore = score;
		}


	}

	//점수 변환 로직
	for (int i = 0; i < N; i++)
	{
		resultAverage += ((scoreArr[i] * 100) / maxScore);

		
	}

	resultAverage /= N;


	
	cout << fixed;
	cout.precision(10);
	cout << resultAverage << '\n';
	return 0;


}
