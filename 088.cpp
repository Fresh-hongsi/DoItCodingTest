#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	vector<vector<int>> dp(N + 1, vector<int>(10, 0));

	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[1][3] = 1;
	dp[1][4] = 1;
	dp[1][5] = 1;
	dp[1][6] = 1;
	dp[1][7] = 1;
	dp[1][8] = 1;
	dp[1][9] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}

			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}

			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < 10; i++) {
		answer = (answer+dp[N][i])% 1000000000;
	}

	cout << answer;
	return 0;

}

