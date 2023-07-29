#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//투 포인터

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//입력
	int N = 0;
	cin >> N;
	int start_idx = 1; //시작 포인터
	int end_idx = 1; //끝 포인터
	int sum = 1; //각 조건에서의 자연수의 합을 계산할 값
	int result = 1; //마지막 수 하나만 가지는 경우 무조건 조건 성립하므로 결과값은 1로 세팅해놓고 시작

	while (!(end_idx == N)) //종료조건-> end_idx가 N인 순간 start_idx와 몇이든지와 상관없이 조건 만족하는 경우 x
	{
		if (sum == N) //조건이 만족하는 경우
		{
			result++;
			end_idx++;
			sum += end_idx;
		}

		else if (sum < N) //아직 sum값이 N보다 작은 경우
		{
			end_idx++;
			sum += end_idx;
		}

		else if(sum > N) //sum값이 N보다 커진 경우
		{
			sum -= start_idx;
			start_idx++;
			
		}

		
	}
	cout << result;
	return 0;
	


}
