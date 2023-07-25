#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	int numLength = 0;
	string str;
	long long sum = 0;
	cin >> numLength; //숫자의 길이
	cin >> str; //숫자로 된 문자열

	for (int i = 0; i < numLength; i++) //문자열 길이만큼 반복하며 각 자리의 숫자값을 알아와 계산
	{
		sum += str[i] - '0';
	}

	cout << sum;
	return 0;


}
