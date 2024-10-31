#include <iostream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	vector<int> dp;
	vector<int> T;
	vector<int> P;

	dp.push_back(0);
	T.push_back(0);
	P.push_back(0);

	for (int i = 1; i <= N;i++) {
		int ti = 0;
		int pi = 0;

		cin >> ti >> pi;
		T.push_back(ti);
		P.push_back(pi);
		dp.push_back(0);
	}
	dp.push_back(0); //N+1번째 항 세팅

	// dp 적용
	for (int i = N; i >= 1; i--) {
		if (i + T[i] > N+1) { // 기간 내에 적용 불가능한 경우
			dp[i] = dp[i + 1];
		}

		else { // 기간 내에 적용 가능한 경우
			dp[i] = max(dp[i + 1], dp[i + T[i]] + P[i]);
		}
	}

	int answer = 0;
	answer = dp[1];
	cout << answer;
	return 0;


}
