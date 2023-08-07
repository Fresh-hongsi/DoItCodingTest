#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	deque<int> dq;
	for (int i = N; i >= 1; i--)
	{
		dq.push_back(i);


	}

	while (1)
	{
		if (dq.size() == 1)
			break;

		dq.pop_back();
		int temp = dq.back();
		dq.pop_back();
		dq.push_front(temp);
	}

	cout << dq.front();
	return 0;

}
