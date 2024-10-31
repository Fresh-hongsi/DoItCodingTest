#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int M = 0;
	cin >> N >> M;

	int dp[1001][1001] = { 0, };

	for (int i = 0; i < N; i++) {
		string s = "";
		cin >> s;

		for (int j = 0; j < M; j++) {
			dp[i + 1][j + 1] = s[j] - '0';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (dp[i][j] == 1) {
				dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	long k = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M ; j++) {
			if (dp[i][j] > k) {
				k = dp[i][j];
			}
		}
	}

	cout << k * k;

	return 0;
}
