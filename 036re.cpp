#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<string> split(string input, char delimeter)
{
	vector<string> result;
	stringstream mystream(input);
	string splitData;

	while (getline(mystream, splitData, delimeter)) {
		result.push_back(splitData);
	}

	return result;
}

int mySum(string a)
{
	int sum = 0;
	vector<string> plus = split(a, '+'); // - 토막 내에서 + 기준으로 split
	for (int i = 0; i < plus.size(); i++)
	{
		sum += stoi(plus[i]);
	}

	return sum;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int answer = 0;
	string example;
	cin >> example;

	vector<string> str = split(example, '-'); // - 기준으로 문자열을 잘라서 토막을 vector에 넣어줌

	for (int i = 0; i < str.size(); i++)
	{
		int temp = mySum(str[i]); // -로 split된 토막 안에서의 합을 구함

		if (i == 0) // 첫번째 토막은 부호 없는 수이므로 answer에 더해줌
		{
			answer += temp;
		}
		else // 그 외의 경우 answer에서 temp을 빼줌
		{
			answer -= temp;
		}
	}

	cout << answer;
	return 0;


}
