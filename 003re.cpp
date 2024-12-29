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
	int M = 0;
	int temp = 0;
	vector<int> sumV;
	sumV.push_back(0);
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		int t = 0;
		cin >> t;
		temp += t;
		sumV.push_back(temp);

	}

	for (int i = 0; i < M; i++) {
		int st = 0;
		int end = 0;
		cin >> st >> end;

		int result = sumV[end] - sumV[st - 1];
		cout << result << '\n';
	}

	return 0;
}
