#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

// dp 활용

int X = 0;
int answer = 0;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> X;

	vector<int> dp(1000001, 0);
	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i <= X; i++) {
		int a = 9999999;
		int b = 9999999;
		int c = 9999999;

		if (i % 3 == 0) {
			a = dp[i / 3] + 1;
		}

		if (i % 2 == 0) {
			b = dp[i / 2] + 1;
		}

		if (i - 1 > 1) {
			c = dp[i - 1] + 1;
		}

		dp[i] = min(min(a, b), c);
	}

	answer = dp[X];
	cout << answer;


	return 0;

}


/*1 2 3 4 5 6 7 8 9 10
0 1 1 2 3 2 3 3 2 3     */          
