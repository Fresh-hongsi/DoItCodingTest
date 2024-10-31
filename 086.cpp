#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <sstream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	vector<vector<long long>> dp(91, vector<long long>(2, 0));
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][0] = dp[1][1] + dp[1][0];
	dp[2][1] = dp[1][0];

	for (int i = 3; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[N][0]+dp[N][1];

	return 0;

}

/*
101000
101001
101010
100001
100000
100010
100100
100101
*/

//1000000
//1000001

//1000010

//1000101
//1000100

//1001000
//1001001

//1010000
//1010001

//1001010

//1010010

//1010100
//1010101
