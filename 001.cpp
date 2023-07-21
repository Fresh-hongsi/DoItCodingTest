#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int length = 0;
	string numString;
	int result = 0;
	cin >> length >> numString;
	for (int i = 0; i < length; i++)
	{
		int temp = 0;
		temp = numString[i] - '0';
		result += temp;
	}

	cout << result;
	return 0;


}
