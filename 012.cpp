#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;


//오큰수
//스택 활용

int N = 0; //입력받을 숫자의 개수

vector<int> numArr(1000001,0); //각 인덱스에 입력받은 초기값을 저장할 벡터
vector<int> resultArr(1000001,0); //각 인덱스에 따른 오큰수 값을 저장할 벡터
stack<int> st; //정렬 기준에 따라 인덱스 값을 저장할 스택


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//입력
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> numArr[i];
	}

	//초기에 스택은 0을 넣고 시작->why? 초기엔 numArr[0]이 가장 큰 수이므로
	st.push(0);

	//스택을 활용해 오큰수 저장하기
	
	
	for (int i = 1; i < N; i++)
	{
		//오큰수를 찾음 -> 해당 오큰수에 적용되는 애들을 세팅해주기
		//만약 numArr[st.top] < numArr[i]이면, 오큰수를 찾은 것이므로 numArr[st.top]<numArr[i]일때까지 stack pop하고, pop할때 스택에 담겨있던 인덱스 값이 x였다면, resultArr[x]값을 numArr[i]로 세팅
		//pop이 끝났으면, 마지막에 현재 인덱스를 push해주기
		if (numArr[st.top()] < numArr[i])
		{
			while (!st.empty() && (numArr[st.top()] < numArr[i]))
			{
				resultArr[st.top()] = numArr[i];
				st.pop();
				

			}
			st.push(i);
			
		}

		//아직 오큰수를 못찾음 -> 일단 스택에 넣어주기
		//만약 numArr[st.top]>numArr[i]라면 오큰수를 찾지 못한 것이므로 st.push(i)해주기
		else if (numArr[st.top()] >= numArr[i])
		{
			st.push(i);
		}
	}

	//for문이 다 돌고 나서 스택에 남은 것들은 오큰수가 없는 것이므로 스택에 남은 값(k)에 대해 numResult[k]=-1해주기 
	//오큰수 결국에 못찾은 애들 -1로 세팅해주기
	while (!st.empty())
	{
		resultArr[st.top()] = -1;
		st.pop();
	}

	//결과 출력하기
	for (int i = 0; i < N; i++)
	{
		cout << resultArr[i] << ' ';
	}

	return 0;


}
