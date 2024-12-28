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
	vector<double> v1;
	vector<double> v2;

	cin >> N;

	for (int i = 0; i < N; i++) {
		double temp = 0;
		cin >> temp;
		v1.push_back(temp);
	}

	double maximum = *max_element(v1.begin(), v1.end());

	for (int i = 0; i < N; i++) {
		double temp = v1[i] / maximum * 100;
		v2.push_back(temp);
	}

	double result = 0;
	for (auto k : v2) {
		result += k;
	}

	result /= N;

	cout << result;

	return 0;
}
