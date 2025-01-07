#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	int st = 1;
	int end = 1;
	int sum = 1;
	int result = 1;

	while (end < N) {

		if (sum < N) {
			end++;
			sum += end;
		}

		else if (sum == N) {
			result++;
			sum -= st;
			st++;
		}

		else {
			sum -= st;
			st++;
		}
	}

	cout << result;
	return 0;
}
