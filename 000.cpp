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

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;

		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (auto k : v) {
		cout << k << '\n';
	}

	return 0;
}
