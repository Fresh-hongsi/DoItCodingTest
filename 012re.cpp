#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;
	vector<int> input;
	vector<int> nge(1000001,0);
	stack<int> st;

	// 입력
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;

		input.push_back(temp);
	}

	// 스택을 활용해서 오큰수를 찾기
	st.push(0); // 첫번째 인덱스 삽입

	
	for (int i = 1; i < N; i++)
	{
		// 만약 다음 값이 현재 스택의 top 인덱스에 있는 value보다 크다면, 해당 top인덱스에 해당하는 nge값을 다음값으로 세팅
		if (!st.empty() && (input[st.top()] < input[i]))
		{
			while (!st.empty() && (input[st.top()] < input[i]))
			{
				int idx = st.top();
				st.pop();
				nge[idx] = input[i];

				
			}

			st.push(i);
		}

		// 그게 아니라면, 아직 더 큰 수를 못찾은 것이므로 스택에 인덱스 값 넣어줌
		else
		{
			st.push(i);
		}
	}

	// 스택에 남아있는 idx에 대해 nge값을 -1로 세팅
	while (!st.empty())
	{
		int idx = st.top();
		st.pop();
		nge[idx] = -1;
	}

	// nge 값 출력 
	for (int i = 0; i < N; i++)
	{
		cout << nge[i] << ' ';
	}

	return 0;
}
