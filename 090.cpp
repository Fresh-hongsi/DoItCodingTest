#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;

string a;
string b;
int dp[1001][1001] = { 0, };
vector<char> path; // lcs 경로

void getText(int r, int c) {
	if (r == 0 || c == 0) {
		return;
	}

	if (a[r - 1] == b[c - 1]) {
		path.push_back(a[r - 1]);
		getText(r - 1, c - 1);
	}

	else {
		if (dp[r - 1][c] > dp[r][c - 1]) {
			getText(r - 1, c);
		}
		else {
			getText(r, c - 1);
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> b;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[a.size()][b.size()] << '\n'; // lcs 길이 출력

	// lcs 경로 찾기
	getText(a.size(), b.size());

	// 구해놓은 경로(path)의 역순 출력
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i];
	}
	return 0;
}

