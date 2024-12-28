#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;
	string s = "";
	cin >> s;

	int result = 0;

	for (int i = 0; i < N; i++) {
		result += s[i] - '0';
	}

	cout << result;
	return 0;
}
