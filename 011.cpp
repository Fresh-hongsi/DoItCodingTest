#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//입력
	vector<int> numSeq(100001, 0); //만들고 싶은 수열을 저장할 배열
	int N = 0; //스택에 사용될 자연수 범위 정하기
	cin >> N;

	//자연수 범위 내에서 만들고 싶은 수열 입력받기
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		numSeq[i] = temp;
	}

	
	int expectedValue = 1; //스택에 처음 입력될 숫자는 1이므로 기대하고 있는 값은 1임. 즉 다음에 기대하는 값
	stack<int> st; //스택에 직접 넣었다 뺄 수 있도록 스택 생성
	string s; //결과 문자열
	bool flag = false; //수열을 만들 수 없는 경우에 바로 반복문 탈출할 수 있도록 하는 flag변수

	for (int i = 0; i < N; i++)
	{
		int curSequenceValue = numSeq[i]; //만들고 싶은 수열의 현재 인덱스에 해당하는 값 세팅


		if (expectedValue <= curSequenceValue) //만약 현재 기대하는 값이 입력받은 sequence의 해당 인덱스에 대응하는 값보다 작거나 같다면, 만들고자하는 값까지 쭉 push하고 마지막에 pop해주기
		{
			for (int j = expectedValue; j <= curSequenceValue; j++)
			{
				st.push(j);
				s += '+';
			}
			st.pop();
			s += '-';

			expectedValue = curSequenceValue+1; //다음에 기대하는 값은 현재 스택의 top보다 하나 큰 값일 것이므로 기대값을 세팅
			continue;
		}

		if (expectedValue > curSequenceValue) //만약 현재 기대하는 값이 입력받은 sequence의 해당 인덱스에 대응하는 값보다 크다면,
			//스택을 pop해야하는데, 스택의 top이 curSequenceValue와 같지 않다면 원하는 수열을 만들지 못하는것임
			//만약 같다면, 스택에서 pop해주기
		{
			if (st.top() == curSequenceValue)
			{
				st.pop();
				s += '-';
				continue;
			}

			else
			{
				flag = true;
				s = "NO";
				break;
			}
		}

		
	}

	//수열을 만들 수 있는 경우 출력 방식
	if (flag == false)
	{
		for (int i = 0; i < s.length(); i++)
		{
			cout << s[i] << '\n';
		}
	}

	//수열을 만들 수 없는 경우 출력 방식
	else
	{
		cout << s;
	}
	
	
	return 0;


}
