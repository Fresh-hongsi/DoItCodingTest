#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	vector<int> dp(1001, 0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;

	for (int i = 4; i <= N; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1])%10007;
	}

	cout << dp[N];
	return 0;
}


