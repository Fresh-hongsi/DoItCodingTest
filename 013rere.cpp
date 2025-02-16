#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <deque>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int N = 0;
	cin >> N;

	deque<int> dq;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	while (1) {
		
		if (dq.size() >= 2) {
			int first = dq.front();
			dq.pop_front();

			if (dq.size() > 1) {
				int second = dq.front();
				dq.pop_front();
				dq.push_back(second);
			}
			else {
				cout << dq.front();
				break;
			}
			
		}

		else {
			cout << dq.front();
			break;
		}


	}


	return 0;
}
