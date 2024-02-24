#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 식 입력받을 문자열
	string s;
	cin >> s;

	// flag - true: 
	//	앞에 minus가 나왔음 표시 -> 따라서 이후에 +가 나오더라도 -로 변환하여 연산자 덱에 넣어주기
	// flag - false: 
	//	앞에 minus가 나온 적 없음 표시 -> 따라서 이후에 +가 나오면 + 그대로 연산자 덱에 넣어주기 위함
	bool flag = false;
	deque<int> operandQ; // 피연산자 담을 덱
	deque<char> operatorQ; // 연산자 담을 덱

	string num; // 연산자가 나오기 전까지 피연산자를 담을 문자열
	
	for (int i = 0; i < s.length(); i++)
	{
		// -가 나오면 연산자 큐에 넣어주기
		if (s[i] == '-')
		{
			flag = true; // 마이너스 나왔음 표시
			operatorQ.push_back('-'); // 마이너스 그대로 연산자 덱에 넣어주기
			operandQ.push_back(stoi(num)); // 그 전까지 추적하고 있던 피연산자를 피연산자 덱에 넣어주기
			num = ""; // 다시 피연산자는 초기화

		}

		// +가 나오면, 앞에 -가 있는 상태라면, -를 연산자 큐에 넣어주기
		else if (s[i] == '+')
		{
			if (flag == true) // 앞에 - 가 나왔었음 -> 따라서 이후의 +는 -로 변환하여 덱에 넣어줌
			{
				operatorQ.push_back('-');
				operandQ.push_back(stoi(num)); // 그 전까지 추적하고 있던 피연산자를 피연산자 덱에 넣어주기
				num = ""; // 다시 피연산자는 초기화
			}

			else // 앞에 - 가 나오지 않았음 -> 따라서 이후의 +는 + 그대로 덱에 넣어줌
			{
				operatorQ.push_back('+');
				operandQ.push_back(stoi(num)); // 그 전까지 추적하고 있던 피연산자를 피연산자 덱에 넣어주기
				num = ""; // 다시 피연산자는 초기화 
			}


		}

		// 연산자가 나오지 않은 경우, 피연산자를 갱신하며 추척
		else
		{
			num += s[i];
		}

	}

	// 마지막까지 추적했던 피연산자를 덱에 넣어주기
	operandQ.push_back(stoi(num));

	// 식 연산 과정
	while (operandQ.size() > 1)
	{
		// 연산자 확인
		char op = operatorQ.front();
		operatorQ.pop_front();

		// 첫번째 피연산자 확인 후 pop
		int a = operandQ.front();
		operandQ.pop_front();

		// 두번째 피연산자 확인 후 pop
		int b = operandQ.front();
		operandQ.pop_front();

		// 계산 후 피연산자 덱의 가장 앞에 넣어주기
		if (op == '-')
		{
			int temp = a-b;
			operandQ.push_front(temp);

		}

		else
		{
			int temp = a + b;
			operandQ.push_front(temp);
		}
	}

	cout << operandQ.front();
	operandQ.pop_front();

	return 0;
}
