#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int sLength = 0; //문자열 길이
int windowSize = 0; //슬라이딩할 문자열 길이
int start_idx = 0; //시작 포인터
int end_idx = 0; //단말 포인터
int result = 0; //답안
string s; //입력받을 문자열

//요구조건 배열
int acgtReq[4] = { 0, };
//현재 acgt상태 배열
int acgtState[4] = { 0, };


//요구조건 배열과 상태 배열과 비교해서 조건 만족하면 결과 값 증가시키기
void is_valid(int* arr)
{
	if ((arr[0] >= acgtReq[0]) && (arr[1] >= acgtReq[1]) && (arr[2] >= acgtReq[2]) && (arr[3] >= acgtReq[3]))
	{
		result++;
	}

	return;
}

//시작 포인터가 하나 뒤로 밀려나면서 생기는 상태배열의 변화를 체크
void updateStartIdxState(int startIdx)
{
	if (s[startIdx - 1] == 'A')
	{
		acgtState[0]--;
	}

	else if (s[startIdx - 1] == 'C')
	{
		acgtState[1]--;
	}
	else if (s[startIdx - 1] == 'G')
	{
		acgtState[2]--;
	}
	else if (s[startIdx - 1] == 'T')
	{
		acgtState[3]--;
	}

	return;
}

//단말 포인터가 하나 뒤로 밀려나면서 생기는 상태배열의 변화를 체크
void updateEndIdxState(int endIdx)
{
	if (s[endIdx] == 'A')
	{
		acgtState[0]++;
	}

	else if (s[endIdx] == 'C')
	{
		acgtState[1]++;
	}
	else if (s[endIdx] == 'G')
	{
		acgtState[2]++;
	}
	else if (s[endIdx] == 'T')
	{
		acgtState[3]++;
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	//입력
	cin >> sLength >> windowSize;
	cin >> s;
	cin >>acgtReq[0] >> acgtReq[1] >> acgtReq[2] >> acgtReq[3];

	//초기 단말 포인터 위치 지정
	end_idx = windowSize - 1;

	//초기 상태 배열 업데이트
	for (int i = 0; i <= end_idx; i++)
	{
		if (s[i] == 'A')
		{
			acgtState[0]++;
		}

		else if (s[i] == 'C')
		{
			acgtState[1]++;
		}
		else if (s[i] == 'G')
		{
			acgtState[2]++;
		}

		else if (s[i] == 'T')
		{
			acgtState[3]++;
		}
	}
	start_idx++;
	end_idx++;
	is_valid(acgtState);

	//두번째부터 마지막까지 슬라이딩하면서 상태변화 체크
	while (!(end_idx == sLength))
	{
		
		updateStartIdxState(start_idx);
		updateEndIdxState(end_idx);
		is_valid(acgtState);
		start_idx++;
		end_idx++;

		
	}

	//결과 도출
	cout << result;
	return 0;
	

	
}

